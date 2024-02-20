// WAP TO IMPLEMENT SEQUENTIAL SEARCH ALGORITHM USING C.

#include <stdio.h>
int sequentialSearch(int arr[], int n, int x);

int main() {
  int arr[] = {2, 6, 7, 8, 9, 20};
  int x = 6;  // element to be found
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = sequentialSearch(arr, n, x);
  if (result == -1)
    printf("Element not found!");
  else
    printf("Element found at index %d", result);
}

int sequentialSearch(int arr[], int n, int x) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == x) return i;
  }
  return -1;
}
