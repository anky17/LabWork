// WAP TO SOLVE THE TOH PROBLEM USING RECURSIVE ALGOROTHM.

#include <stdio.h>

void towerOfHanoi(int n, char source, char intermediate, char destination) {
  if (n == 1) {
    printf("Move disk 1 from %c tower to %c tower\n", source, destination);
    return;
  }

  // Move n-1 disks from source to intermediate peg using destination peg
  towerOfHanoi(n - 1, source, destination, intermediate);

  // Move the nth disk from source to destination peg
  printf("Move disk %d from %c tower to %c tower\n", n, source, destination);

  // Move the n-1 disks from intermediate to destination peg using source peg
  towerOfHanoi(n - 1, intermediate, source, destination);
}

int main() {
  towerOfHanoi(3, 'X', 'Y', 'Z');
  return 0;
}
