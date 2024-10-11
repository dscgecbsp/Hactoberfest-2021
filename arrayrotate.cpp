#include <iostream>
using namespace std;

// Function to reverse a segment of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to left rotate the array by d elements
void leftRotate(int arr[], int d, int n) {
    d = d % n; // In case d is greater than n
    reverse(arr, 0, d - 1); // Reverse the first d elements
    reverse(arr, d, n - 1); // Reverse the remaining n-d elements
    reverse(arr, 0, n - 1); // Reverse the whole array
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
    leftRotate(arr, 2, n);
    printArray(arr, n);

    return 0;
}
