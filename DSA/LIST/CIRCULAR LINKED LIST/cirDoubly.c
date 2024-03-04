// WAP TO IMPLEMENT ALL THE OPERATION OF DOUBLY CIRCULAR LINKED LIST.
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

// Function to display all the elements of the circular doubly linked list
void traverse(struct node *last) {
  struct node *p = last->next;
  printf("Elements: <->");
  do {
    printf("%d<->", p->data);
    p = p->next;
  } while (p != last->next);  // Loop until we come back to the start
}

// Function to insert a node at the front of a circular doubly linked list
struct node *insertAtFront(struct node *last, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = last->next;
  newNode->prev = last;
  last->next->prev = newNode;  // the old first node points back to the newNode
  last->next = newNode;
  return last;
}

// Function to insert a node at given index of a circular doubly linked list
struct node *insertAtIndex(struct node *last, int data, int index) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  struct node *p = last->next;  // Start from the first node
  for (int i = 0; i < index - 1 && p != last; i++) {
    p = p->next;
  }
  newNode->next = p->next;
  newNode->prev = p;
  p->next->prev = newNode;
  p->next = newNode;
  return last;
}

// Function to insert a node at the end of a circular doubly linked list
struct node *insertAtEnd(struct node *last, int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = last->next;
  newNode->prev = last;
  last->next->prev = newNode;
  last->next = newNode;
  last = newNode;  // updating the last pointer
  return last;
}

// Function to delete a node from the front of a circular doubly linked list
struct node *deletefromFront(struct node *last) {
  struct node *first = last->next;
  last->next = first->next;
  first->next->prev = last;
  free(first);
  return last;
}

// Function to delete a node at given index of a circular doubly linked list
struct node *deleteAtIndex(struct node *last, int index) {
  struct node *p = last->next;
  for (int i = 0; i < index && p != last; i++) {
    p = p->next;
  }
  p->prev->next = p->next;
  p->next->prev = p->prev;
  free(p);
  return last;
}

// Function to delete a node from the end of a circular doubly linked list
struct node *deletefromEnd(struct node *last) {
  struct node *lastNode = last;
  last->prev->next = last->next;
  last->next->prev = last->prev;
  last = last->prev;
  free(lastNode);
  return last;
}

int main() {
  struct node *last = NULL;
  struct node *first = NULL;
  struct node *second = NULL;
  struct node *third = NULL;

  first = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  first->data = 7;
  second->data = 8;
  third->data = 9;

  first->prev = third;
  first->next = second;

  second->prev = first;
  second->next = third;

  third->prev = second;
  third->next = first;

  last = third;

  last = insertAtFront(last, 90);
  last = insertAtIndex(last, 6, 1);  // Inserting at index 1
  last = insertAtEnd(last, 100);

  printf("\nAfter insertion: \n");
  traverse(last);

  last = deletefromFront(last);
  last = deleteAtIndex(last, 1);  // Deleting at index 1
  last = deletefromEnd(last);

  printf("\nAfter deletion:\n");
  traverse(last);

  return 0;
}
