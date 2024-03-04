// WAP TO IMPLEMENT THE OPERATION OF SINGLY LINKED LIST USING C.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

// Function to display all the elements of singly linked list
void listTraversal(struct node *head) {
  printf("Elements: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

// Funtion to insert a node at the front of singly linked list
struct node *insertAtFront(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->next = head;
  ptr->data = data;
  return ptr;
}

// Funtion to insert a node at a given index of singly linked list
struct node *insertAtIndex(struct node *head, int data, int index) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

// Funtion to insert a node at the end of singly linked list
struct node *insertAtEnd(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  ptr->data = data;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return head;
}

// Funtion to delete a node from the front of singly linked list
struct node *deletefromFront(struct node *head) {
  struct node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

// Funtion to delete a node from a given index of singly linked list
struct node *deleteAtIndex(struct node *head, int index) {
  struct node *ptr = head;
  struct node *ptr1 = head->next;
  for (int i = 0; i < index - 1; i++) {
    ptr = ptr->next;
    ptr1 = ptr1->next;
  }
  ptr->next = ptr1->next;
  free(ptr1);
  return head;
}

// Funtion to delete a node from the end of singly linked list
struct node *deletefromEnd(struct node *head) {
  struct node *ptr = head;
  struct node *ptr1 = head->next;
  while (ptr1->next != NULL) {
    ptr = ptr->next;
    ptr1 = ptr1->next;
  }
  ptr->next = NULL;
  free(ptr1);
  return head;
}

int main() {
  struct node *head;
  struct node *first;
  struct node *second;
  struct node *third;

  first = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  first->data = 7;
  second->data = 8;
  third->data = 9;

  first->next = second;
  second->next = third;
  third->next = NULL;

  head = first;

  printf("Before insertion:\n");
  listTraversal(head);
  head = insertAtFront(head, 11);
  head = insertAtIndex(head, 39, 3);
  head = insertAtEnd(head, 90);
  printf("\nAfter insertion:\n");
  listTraversal(head);

  printf("\nBefore deletion:\n");
  listTraversal(head);
  head = deletefromFront(head);
  head = deleteAtIndex(head, 3);
  head = deletefromEnd(head);
  printf("\nAfter deletion:\n");
  listTraversal(head);

  return 0;
}
