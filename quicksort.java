quicksort in java#
// Java implementation of Quick Sort
public class QuickSort {

    // Method to partition the array on the basis of pivot
    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];  
        int i = (low - 1);      
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;  
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }
    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);  
            quickSort(arr, pi + 1, high); 
        }
    }
   static void printArray(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] arr = { 10, 80, 30, 90, 40, 50, 70 };

        System.out.println("Original Array:");
        printArray(arr);

        quickSort(arr, 0, arr.length - 1);

        System.out.println("Sorted Array:");
        printArray(arr);
    }
}
