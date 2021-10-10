#include <iostream>

void printArray(int * array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void merge(int * A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2], i, j, k;
    // making two arrays of ?
    for (i = 0; i < n1; i++) {
        L[i] = A[p + i - 1];
    }
    for (j = 0; j < n2; j++) {
        R[j] = A[q + j];
    }
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            A[k] = A[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int * array, int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end)/2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main() {
    int arr5[8] = {7, 8, 3, 9, 11, 2, 16, 12};
    std::cout << "Running merge sort on: ";
    printArray(arr5, 8);
    mergeSort(arr5, 0, 8 - 1);
    printArray(arr5, 8);

    return 0;
}