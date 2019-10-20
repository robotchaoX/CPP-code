#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void InsertSort(int arr[], int len) {

    for (int i = 1; i < len; ++i) {

        if (arr[i] > arr[i - 1]) {
            int temp = arr[i];
            int j = i - 1;
            for (; j >= 0 && temp > arr[j]; j--) {
                arr[j + 1] = arr[j];
            }

            arr[j + 1] = temp;
        }
    }
}

void test() {
    int arr[] = {5, 3, 9, 2, 1, 3};
    int len = sizeof(arr) / sizeof(int);
    printArray(arr, len);
    InsertSort(arr, len);
    printArray(arr, len);
}

int main() {

    test();

    // system("pause");
    return EXIT_SUCCESS;
}