#include<stdio.h>

// Function to find the maximum element in an array
int getmax(int arr[], int n) {
    int max = arr[0];
    for (int j = 1; j < n; j++) {
        if (arr[j] > max) {
            max = arr[j];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit (pass)
void countSort(int arr[], int n, int pass) {
    int output[n];
    int count[10] = {0};

    // Count the occurrences of each digit at the given pass
    for (int i = 0; i < n; i++) {
        ++count[(arr[i] / pass) % 10];
    }

    // Calculate the cumulative count of digits
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted output array
    for (int i = n - 1; i >= 0; i--) {
        output[--count[(arr[i] / pass) % 10]] = arr[i];
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int max = getmax(arr, n);

    // Perform counting sort for each digit (pass), starting from the least significant digit
    for (int pass = 1; max/pass>0; pass *= 10) {
        countSort(arr, n, pass);
    }
}

int main() {
    int arr[] = {1, 70, 679, 34, 23, 43, 234};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using Radix Sort
    radixSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
