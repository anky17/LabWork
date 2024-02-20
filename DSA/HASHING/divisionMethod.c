// WAP TO IMPLEMENT DIVISION METHOD OF HASHING.

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Define the size of the hash table

// Hash table item structure
typedef struct {
  int key;
  int value;
} HashItem;

// Hash table structure
typedef struct {
  HashItem** items;
} HashTable;

// Function to create a new hash item
HashItem* createItem(int key, int value) {
  HashItem* item = (HashItem*)malloc(sizeof(HashItem));
  item->key = key;
  item->value = value;
  return item;
}

// Function to initialize the hash table
HashTable* createTable() {
  HashTable* table = (HashTable*)malloc(sizeof(HashTable));
  table->items = (HashItem**)malloc(sizeof(HashItem*) * TABLE_SIZE);
  for (int i = 0; i < TABLE_SIZE; i++) {
    table->items[i] = NULL;
  }
  return table;
}

// Hash function using the division method
int hashFunction(int key) { return key % TABLE_SIZE; }

// Function to insert a key-value pair into the hash table
void insert(HashTable* table, int key, int value) {
  HashItem* item = createItem(key, value);
  int index = hashFunction(key);

  // Linear probing in case of collision
  while (table->items[index] != NULL && table->items[index]->key != key) {
    index = (index + 1) % TABLE_SIZE;
  }

  // Insert the new item
  table->items[index] = item;
}

// Function to search for a value by its key
int search(HashTable* table, int key) {
  int index = hashFunction(key);

  // Search with linear probing
  while (table->items[index] != NULL) {
    if (table->items[index]->key == key) {
      return table->items[index]->value;  // Return the found value
    }
    index = (index + 1) % TABLE_SIZE;
  }

  // Return -1 if the key is not found
  return -1;
}

// Function to display the hash table
void display(HashTable* table) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (table->items[i] != NULL) {
      printf("Index %d: Key %d, Value %d\n", i, table->items[i]->key,
             table->items[i]->value);
    } else {
      printf("Index %d: NULL\n", i);
    }
  }
}

int main() {
  HashTable* table = createTable();

  // Inserting some values
  insert(table, 1, 20);
  insert(table, 2, 70);
  insert(table, 42, 80);  // This will cause a collision with key 2
  insert(table, 4, 25);
  insert(table, 12, 44);  // This will cause a collision with key 2 and 42

  // Display the table
  display(table);

  // Search for values
  printf("Value for key 42: %d\n", search(table, 42));
  printf("Value for key 2: %d\n", search(table, 2));

  // Free memory
  free(table->items);
  free(table);

  return 0;
}
