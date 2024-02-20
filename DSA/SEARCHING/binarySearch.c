// WAP TO IMPLEMENT BINARY SEARCH ALGORITHM USING C.

#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
  while (l <= r) {
    int m = l + (r - l) / 2;

    // Check if x is present at mid
    if (arr[m] == x) return m;

    // If x greater than mid then we ignore left half
    if (arr[m] < x) l = m + 1;

    // If x is smaller than mid then we ignore right half
    else
      r = m - 1;
  }

  // If we reach here then the element was not present
  return -1;  // return error
}

int main() {
  int arr[] = {2, 3, 6, 10, 12, 30};
  // int arr[] = {9, 8, 7, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 6;
  int result = binarySearch(arr, 0, n - 1, x);
  if (result == -1)
    printf("Element is not present in array");
  else
    printf("Element is present at index %d", result);
  return 0;
}
