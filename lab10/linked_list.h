#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "person.h"

// Node struct
typedef struct Node {
    Person person;
    struct Node *next;
} Node;

// Function prototypes
Node* addNode(Node *head, Person person);
Node* findNode(Node *head, int id, Role role);
Node* deleteNode(Node *head, int id, Role role);
void printList(const Node *head);
void freeList(Node *head);

#endif // LINKED_LIST_H