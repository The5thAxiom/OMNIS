def bubbleSort(array):
    print("Running bubble sort on: {}".format(array))
    sorted = False
    while (not sorted):
        sorted = True
        for i in range(len(array) - 1):
            if array[i] > array[i + 1]:
                temp = array[i]
                array[i] = array[i + 1]
                array[i + 1] = temp
                sorted = False
    print(array)

def selectionSort(array):
    print("Running selection sort on : {}".format(array))
    for i in range(len(array)):
        min = i
        for j in range(i, len(array)):
            if array[j] < array[min]:
                min = j
            temp = array[i]
            array[i] = array[min]
            array[min] = temp
    print(array)

def insertionSort(array):
    print("Running insertion sort on : {}".format(array))
    for i in range(len(array)):
        temp = array[i]
        for j in range(i-1, -1, -1):
            if array[j] > temp:
                array[j + 1] = array[j]
            else:
                break
            array[j] = temp
    print(array)

if __name__ == "__main__":
    array = [7, 8, 3, 9, 11, 2, 15, 12]
    bubbleSort(array)
    array = [7, 8, 3, 9, 11, 2, 15, 12]
    selectionSort(array)
    array = [7, 8, 3, 9, 11, 2, 15, 12]
    insertionSort(array)