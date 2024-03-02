// WAP TO IMPLEMENT ALL THE OPERATION OF CIRCULAR SINGLY LINKED LIST.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

// Function to display all the elements of the circular singly linked list
void traverse(struct node *last) {
  printf("Element: ");
  struct node *p = last->next;
  do {
    printf("%d ", p->data);
    p = p->next;
  } while (p != last->next);
}

// Function to insert a node at the front of a circular singly linked list
struct node *insertAtFront(struct node *last, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;
  return last;
}

// Function to insert a node at given index of a circular singly linked list
struct node *insertAtIndex(struct node *last, int data, int index) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  struct node *p = last->next;  // Start from the first node
  for (int i = 0; i < index - 1 && p != last;
       i++) {  // Traverse to the specified index
    p = p->next;
  }
  // Insert the new node after the current node
  newNode->next = p->next;
  newNode->data = data;
  p->next = newNode;
  return last;
}

// Function to insert a node at the end of a circular singly linked list
struct node *insertAtEnd(struct node *last, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = last->next;
  last->next = newNode;

  // update the last to the newNode
  last = newNode;
  return last;
}

// Function to delete a node from the front of a circular singly linked list
struct node *deletefromFront(struct node *last) {
  struct node *first = last->next;
  struct node *temp = first;
  last->next = first->next;
  free(temp);
  return last;
}

// Function to delete a node from the front of a circular singly linked list
struct node *deleteAtIndex(struct node *last, int index) {
  struct node *p = last->next;
  struct node *q = p->next;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    q = q->next;
    i++;
  }
  p->next = q->next;
  free(q);
  return last;
}

// Function to delete a node from the end of a circular singly linked list
struct node *deletefromEnd(struct node *last) {
  struct node *q = last->next;
  while (q->next != last) {
    q = q->next;
  }
  q->next = last->next;  // Here q->next points to first node
  free(last);
  return last;
}

int main() {
  struct node *last;
  struct node *first = NULL;
  struct node *second = NULL;
  struct node *third = NULL;

  first = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  first->data = 7;
  first->next = second;

  second->data = 8;
  second->next = third;

  third->data = 9;
  third->next = first;

  last = third;

  printf("\nBefore insertion\n");
  traverse(last);
  last = insertAtFront(last, 90);
  last = insertAtIndex(last, 6, 3);
  last = insertAtEnd(last, 100);

  printf("\nAfter insertion: \n");
  traverse(last);

  printf("\nAfter deletion:\n");
  last = deletefromFront(last);
  last = deleteAtIndex(last, 1);
  last = deletefromEnd(last);
  traverse(last);

  return 0;
}