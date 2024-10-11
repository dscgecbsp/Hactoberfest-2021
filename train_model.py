import os
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Input, Conv2D, MaxPooling2D, UpSampling2D, concatenate, Dropout
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.callbacks import EarlyStopping, ModelCheckpoint

# Define image dimensions and other parameters
IMG_HEIGHT = 256
IMG_WIDTH = 256
BATCH_SIZE = 16
EPOCHS = 50

# Define the U-Net model with Dropout layers for regularization
def unet_model(input_size=(IMG_HEIGHT, IMG_WIDTH, 3)):
    inputs = Input(input_size)
    
    # Encoder
    conv1 = Conv2D(64, 3, activation='relu', padding='same')(inputs)
    drop1 = Dropout(0.2)(conv1)
    pool1 = MaxPooling2D(pool_size=(2, 2))(drop1)
    
    conv2 = Conv2D(128, 3, activation='relu', padding='same')(pool1)
    drop2 = Dropout(0.2)(conv2)
    pool2 = MaxPooling2D(pool_size=(2, 2))(drop2)
    
    conv3 = Conv2D(256, 3, activation='relu', padding='same')(pool2)
    drop3 = Dropout(0.3)(conv3)
    
    # Decoder
    up1 = concatenate([UpSampling2D(size=(2, 2))(drop3), drop2], axis=-1)
    conv4 = Conv2D(128, 3, activation='relu', padding='same')(up1)
    
    up2 = concatenate([UpSampling2D(size=(2, 2))(conv4), drop1], axis=-1)
    conv5 = Conv2D(64, 3, activation='relu', padding='same')(up2)
    
    outputs = Conv2D(1, 1, activation='sigmoid')(conv5)
    
    model = Model(inputs, outputs)
    return model

# Instantiate the model
model = unet_model()

# Compile the model
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Define paths
train_image_path = '/Users/alok/Desktop/REFUGE2/train/images'
train_mask_path = '/Users/alok/Desktop/REFUGE2/train/mask'
model_save_path = '/Users/alok/Desktop/REFUGE2/saved_model.h5'

# Define ImageDataGenerators for augmentation
image_datagen = ImageDataGenerator(
    rescale=1./255,
    rotation_range=15,
    width_shift_range=0.1,
    height_shift_range=0.1,
    shear_range=0.1,
    zoom_range=0.1,
    horizontal_flip=True,
    validation_split=0.2
)

mask_datagen = ImageDataGenerator(
    rescale=1./255,
    validation_split=0.2
)

# Create data generators for training and validation
train_image_generator = image_datagen.flow_from_directory(
    train_image_path,
    target_size=(IMG_HEIGHT, IMG_WIDTH),
    class_mode=None,
    batch_size=BATCH_SIZE,
    subset='training',
    seed=42
)

train_mask_generator = mask_datagen.flow_from_directory(
    train_mask_path,
    target_size=(IMG_HEIGHT, IMG_WIDTH),
    class_mode=None,
    batch_size=BATCH_SIZE,
    subset='training',
    seed=42
)

val_image_generator = image_datagen.flow_from_directory(
    train_image_path,
    target_size=(IMG_HEIGHT, IMG_WIDTH),
    class_mode=None,
    batch_size=BATCH_SIZE,
    subset='validation',
    seed=42
)

val_mask_generator = mask_datagen.flow_from_directory(
    train_mask_path,
    target_size=(IMG_HEIGHT, IMG_WIDTH),
    class_mode=None,
    batch_size=BATCH_SIZE,
    subset='validation',
    seed=42
)

# Combine generators
def combine_generator(image_gen, mask_gen):
    while True:
        img = image_gen.next()
        mask = mask_gen.next()
        yield (img, mask)

train_generator = combine_generator(train_image_generator, train_mask_generator)
val_generator = combine_generator(val_image_generator, val_mask_generator)

# Callbacks for saving the best model and early stopping
callbacks = [
    ModelCheckpoint(model_save_path, monitor='val_loss', save_best_only=True, verbose=1),
    EarlyStopping(monitor='val_loss', patience=5, verbose=1, restore_best_weights=True)
]

# Train the model
history = model.fit(
    train_generator,
    steps_per_epoch=train_image_generator.samples // BATCH_SIZE,
    validation_data=val_generator,
    validation_steps=val_image_generator.samples // BATCH_SIZE,
    epochs=EPOCHS,
    callbacks=callbacks
)
