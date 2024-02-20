// WAP TO IMPLEMENT BUBBLE SORT ALGORITHM

#include <stdio.h>

void bubbleSort(int[], int n);
void displayArray(int[], int n);

int main() {
  int arr[] = {4, 8, 9, 0, 11, 56, 79, 22};
  printf("Array before sorting:\n");
  displayArray(arr, 8);

  bubbleSort(arr, 8);
  printf("\nArray after sorting:\n");
  displayArray(arr, 8);
  return 0;
}

// Function to display the array
void displayArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      // swap the elements to sort them in ascending order
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}