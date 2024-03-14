#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* mergeSort(int arr[], int size);
int* merge(int left[], int right[], int leftSize, int rightSize);

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* sortedArr = mergeSort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");
    free(sortedArr);
    return 0;
}

int* mergeSort(int arr[], int size) {
    if (size <= 1) {
        int* newArr = malloc(size * sizeof(int));
        memcpy(newArr, arr, size * sizeof(int));
        return newArr;
    }

    int mid = size / 2;
    int* leftHalf = mergeSort(arr, mid);
    int* rightHalf = mergeSort(arr + mid, size - mid);
    int* merged = merge(leftHalf, rightHalf, mid, size - mid);
    free(leftHalf);
    free(rightHalf);
    return merged;
}

int* merge(int left[], int right[], int leftSize, int rightSize) {
    int* result = malloc((leftSize + rightSize) * sizeof(int));
    int leftIdx = 0, rightIdx = 0, resultIdx = 0;

    while (leftIdx < leftSize && rightIdx < rightSize) {
        if (left[leftIdx] < right[rightIdx]) {
            result[resultIdx++] = left[leftIdx++];
        } else {
            result[resultIdx++] = right[rightIdx++];
        }
    }

    while (leftIdx < leftSize) {
        result[resultIdx++] = left[leftIdx++];
    }

    while (rightIdx < rightSize) {
        result[resultIdx++] = right[rightIdx++];
    }

    return result;
}
