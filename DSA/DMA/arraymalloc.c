/* WAP to dynamically allocate memory for the array elements using malloc() function and read and display the array elements */

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *p;
  int num, i, sum = 0;
  float avg;
  printf("Enter how many elements:");
  scanf("%d", &num);
  p = (int *)malloc(num * sizeof(int));
  if (p == NULL)
  {
    printf("Error! memory not allocated");
    exit(0);
  }
  printf("Enter the array element:\n");
  for (i = 0; i < num; i++)
  {
    scanf("%d", (p + i));
  }

  printf("The elements of array are:\n");
  for (i = 0; i < num; i++)
  {
    printf("%d ", *(p + i));
    sum = sum + *(p + i);
  }

  avg = sum / num;
  printf("sum=%d\tavg=%f", sum, avg);
  free(p);
  return 0;
}

// clang arraymalloc.c -o nk && ./nk