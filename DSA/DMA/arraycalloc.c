/* WAP to dynamically allocate memory for the array elements using calloc() function and read and display the array elements */

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *p;
  int num, i;
  printf("Enter the array size:");
  scanf("%d", &num);
  p = (int *)calloc(num, sizeof(int));
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
  }
  free(p);

  return 0;
}
