#include <stdio.h>

void shellSort(int array[], int size) {
    int gap, i, j, temp;

    // Start with a large gap and reduce it over iterations
    for (gap = size / 2; gap > 0; gap /= 2) {
        // Perform insertion sort on elements separated by gap
        for (i = gap; i < size; i++) {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }
    }
}

int main() {
    int array[] = {9, 5, 1, 8, 3, 2, 7, 6, 4};
    int size = sizeof(array) / sizeof(array[0]);
    int i;

    printf("Array before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    shellSort(array, size);

    printf("Array after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

