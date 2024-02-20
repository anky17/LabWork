// WAP TO SORT AN ARRAY USING INSERTION SORT.

#include <stdio.h>

void insertionSort(int[], int);
void displayArray(int[], int);

int main() {
  int arr[] = {4, 77, 5, 9, 1, 34, 98, 45};

  printf("Array before sorting:\n");
  displayArray(arr, 8);

  insertionSort(arr, 8);
  printf("\nArray after sorting:\n");
  displayArray(arr, 8);
}

void displayArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

void insertionSort(int arr[], int size) {
  int step, key, j;
  for (int step = 1; step < size; step++) {
    key = arr[step];  // assume second element of array as sorted and
                      // compare it with the next unsorted array.
    j = step - 1;
    /* Compare key with each element on the left of it until an element smaller
     than it is found. Move elements of arr[0..i-1] that are greater than key to
     one position ahead of their current position */
    while (key < arr[j] && j >= 0) {  // For descending order, change
                                      // key<array[j] to key > arr[j]//
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}