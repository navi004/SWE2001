#include<stdio.h>

// Function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int l, int mid, int h) {
	int i = l;
	int j = mid + 1;
	int k = l;
	int b[h + 1];

	// Merge the subarrays in sorted order
	while (i <= mid && j <= h) {
		if (arr[i] < arr[j]) {
			b[k++] = arr[i++];
		}
		else {
			b[k++] = arr[j++];
		}
	}

	// Copy remaining elements from the left subarray
	for (; i <= mid; i++) {
		b[k++] = arr[i];
	}

	// Copy remaining elements from the right subarray
	for (; j <= h; j++) {
		b[k++] = arr[j];
	}

	// Copy the sorted elements back to the original array
	for (int k = l; k <= h; k++) {
		arr[k] = b[k];
	}
}

// Function to implement merge sort
void mergeSort(int arr[], int l, int h) {
	if (l < h) {
		int mid = (l + h) / 2;
		// Recursively divide the array into two halves
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, h);
		// Merge the sorted halves
		merge(arr, l, mid, h);
	}
}

// Function to print the elements of an array
void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int arr[] = {9, 3, 7, 1, 6, 4, 8, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	// Sort the array using merge sort
	mergeSort(arr, 0, n - 1);

	// Print the sorted array
	print(arr, n);

	return 0;
}
