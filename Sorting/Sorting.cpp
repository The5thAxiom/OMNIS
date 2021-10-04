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
    std::cout << "Running bubble sort on: ";
    printArray(array, size);
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
    printArray(array, size);
}

/*
    Go throught the array, find the smallest elment and exchange with the first,
    find the second smallest and exchange with the 2nd one and so on
    O(n^2) i think for the worst case
*/
void selectionSort(int * array, int size) {
    int current, j, temp, min;
    std::cout << "Running selection sort on: ";
    printArray(array, size);
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
    printArray(array, size);
}

/*
    go through the array and for each element:
        go backwards in another loop and move the elements forward if they are bigger than the current one
        and stop moving if a smaller one is found and put the current element there
*/
void insertionSort(int * array, int size) {
    int i, j, temp;
    std::cout << "Running insertion sort on: ";
    printArray(array, size);
    for (i = 0; i < size; i++) {
        temp = array[i]; // the 'current' element
        for (j = i - 1; j >= 0; j--) { // go back
            if (array[j] > temp) { // move the elements forward if bigger
                array[j + 1] = array[j];
            } else {
                array[j + 1] = temp;
                break;
            }
        }
    }
    printArray(array, size);
}

int main() {
    int arr1[8] = {7, 8, 3, 9, 11, 2, 15, 12};
    bubbleSort(arr1, 8);
    int arr2[8] = {7, 8, 3, 9, 11, 2, 15, 12};
    selectionSort(arr2, 8);
    int arr3[8] = {7, 8, 3, 9, 11, 2, 15, 12};
    insertionSort(arr3, 8);
}
