#include <iostream>

void printArray(int * array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

/*
    Go through the array and swap if any elements are in the wrong order
    Take as many passes as needed
    O(n^2)
*/
void bubbleSort(int * array, int size) {
    int i, temp;
    bool sorted;
    do { // as many passes as it takes
        sorted = true; // if the 'if' statement in the for loop below is never used, it means the array is sorted
        for (i = 0; i < size - 1; i++) { // go through each element
            if (array[i] > array[i+1]) { // if the next one is greater than the current one then swap them
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                sorted = false;
            }
        }
    } while (!sorted);
}

/*
    Go throught the array, find the smallest elment and exchange with the first,
    find the second smallest and exchange with the 2nd one and so on
    O(n^2) i think for the worst case
*/
void selectionSort(int * array, int size) {
    int current, j, temp, min;
    for (current = 0; current < size ; current++) { // for the 1st element
        min = current;
        for (j = current ; j < size ; j++) { // if any element after it is smaller, make it the min element
            if (array[j] < array[min]) {
                min = j;                //update the index
            }
            temp = array[current];
            array[current] = array[min]; //swapping
            array[min] = temp;
        }
    }
}

/*
    go through the array and for each element:
        go backwards in another loop and move the elements forward if they are bigger than the current one
        and stop moving if a smaller one is found and put the current element there
*/
void insertionSort(int * array, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        temp = array[i]; // the 'current' element
        for (j = i - 1; j > -1; j--) { // go back from the current element
            if (array[j] > temp) { // if the previous element is greater than the 'current' one, move it forwards
                array[j + 1] = array[j];
            } else break;// if its not, it means here is where the 'current' must be placed
            array[j] = temp;
        }
    }
}

void merge(int * array, int start, int mid, int end) {
    
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

void quickSort(int * array, int size) {
    // to be implemented
}



int main() {
    int size = 8;
    int arr1[size] = {7, 8, 3, 9, 11, 2, 16, 12};
    std::cout << "Running bubble sort on: ";
    printArray(arr1, size);
    bubbleSort(arr1, size);
    printArray(arr1, size);
    
    int arr2[8] = {7, 8, 3, 9, 11, 2, 16, 12};
    std::cout << "Running selection sort on: ";
    printArray(arr2, size);
    selectionSort(arr2, size);
    printArray(arr2, size);

    int arr3[8] = {7, 8, 3, 9, 11, 2, 16, 12};
    std::cout << "Running insertion sort on: ";
    printArray(arr3, size);
    insertionSort(arr3, size);
    printArray(arr3, size);

    int arr5[8] = {7, 8, 3, 9, 11, 2, 16, 12};
    std::cout << "Running merge sort on: ";
    printArray(arr5, size);
    mergeSort(arr5, 0, size - 1);
    printArray(arr5, size);

    int arr4[8] = {7, 8, 3, 9, 11, 2, 16, 12};
    std::cout << "Running quick sort on: ";
    printArray(arr4, size);
    quickSort(arr4, size);
    printArray(arr4, size);

    return 0;
}
