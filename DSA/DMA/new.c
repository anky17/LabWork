#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr;
  int initialSize = 3;
  int newSize = 5;

  // Allocate memory for initial size
  arr = (int *)malloc(initialSize * sizeof(int));

  // Initialize the numbers array
  printf("Enter the array elements: ");

  for (int i = 0; i < initialSize; i++) {
    scanf("%d", (arr + i));
  }

  // Print the numbers before resizing
  printf("Array elements before resizing:\n");
  for (int i = 0; i < initialSize; i++) {
    printf("%d ", arr[i]);
  }

  // Resize the memory block using realloc
  arr = realloc(arr, newSize * sizeof(int));

  // Update the newly added elements
  printf("\nEnter the remaining array elements: ");
  for (int i = initialSize; i < newSize; i++) {
    scanf("%d", (arr + i));
  }

  // Print the numbers after resizing
  printf("Array elements after resizing:\n");
  for (int i = 0; i < newSize; i++) {
    printf("%d ", arr[i]);
  }

  // Free the dynamically allocated memory
  free(arr);

  return 0;
}
