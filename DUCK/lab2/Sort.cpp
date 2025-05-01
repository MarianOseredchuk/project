#include "Sort.h"
#include <iostream>
using namespace std;

void Swap(datatype* a, datatype* b) {
    datatype temp = *a;
    *a = *b;
    *b = temp;
}

void Show(datatype arr[], int size, int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SortBubble(datatype* arr, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start); j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void SortInsertion(datatype* arr, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        datatype key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SortSelection(datatype* arr, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (arr[i] > arr[j]) {
                Swap(&arr[i], &arr[j]);
            }
        }
    }
}
