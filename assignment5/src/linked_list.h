// linked_list.h: 2211A Assignment 5 by Rohin Arya (251371185)
// This file defines the linked list structure and its operations for storing reminders.

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMINDER_LENGTH 100

// Node structure for linked list
struct Node {
    char reminder[MAX_REMINDER_LENGTH];
    struct Node* next;
};

// Function declarations for linked list operations
struct Node* addNode(struct Node* head, const char* reminder);
struct Node* deleteNode(struct Node* head, const char* reminder);
void freeAll(struct Node* head);
void printList(struct Node* head);
struct Node* createNode(const char* reminder);

#endif
