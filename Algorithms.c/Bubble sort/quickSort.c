#include <stdio.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int l, int h) {
    int pivot = arr[l]; // Select the first element as the pivot
    int start = l + 1; // Index of the start of the unprocessed region
    int end = h; // Index of the end of the unprocessed region

    while (start <= end) {
        while (arr[start] <= pivot && start <= end) {
            start++; // Move the start index until finding an element greater than the pivot
        }
        while (arr[end] > pivot && start <= end) {
            end--; // Move the end index until finding an element less than or equal to the pivot
        }
        if (start < end) {
            swap(&arr[start], &arr[end]); // Swap the elements at start and end indices
        }
    }
    swap(&arr[l], &arr[end]); // Swap the pivot with the element at the end index
    return end; // Return the updated index of the pivot
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int loc = partition(arr, l, h); // Partition the array and get the index of the pivot
        quickSort(arr, l, loc - 1); // Sort the left subarray
        quickSort(arr, loc + 1, h); // Sort the right subarray
    }
}

int main() {
    int arr[] = {7, 2, 3, 8, 1, 9, 4, 6};
    int l = 0;
    int h = 7;

    quickSort(arr, l, h); // Call the quickSort function

    printf("Sorted array: ");
    for (int i = 0; i <= h; i++) {
        printf("%d ", arr[i]); // Print the sorted array
    }
    printf("\n");

    return 0;
}
