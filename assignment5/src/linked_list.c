// linked_list.c: 2211A Assignment 5 by Rohin Arya (251371185)
// This file implements the linked list operations for managing reminders.

#include "linked_list.h"

// Create a new node with the given reminder
struct Node* createNode(const char* reminder) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
    // Check if memory allocation failed
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    // Copy the reminder to the new node
    strncpy(newNode->reminder, reminder, MAX_REMINDER_LENGTH - 1);
    // Ensure null-termination basically
    newNode->reminder[MAX_REMINDER_LENGTH - 1] = '\0';
    newNode->next = NULL;
    return newNode;
}

// Add a new reminder to the end of the list
struct Node* addNode(struct Node* head, const char* reminder) {
    if (head == NULL) {
        return createNode(reminder);
    }
    
    // Iterate through the list to find the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Add the new node at the end
    current->next = createNode(reminder);
    return head;
}

// Delete a specific reminder from the list
struct Node* deleteNode(struct Node* head, const char* reminder) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        // Check if the current reminder matches the given reminder
        if (strcmp(current->reminder, reminder) == 0) {
            if (prev == NULL) {
                // If the current node is the head, update the head
                head = current->next;
            } else {
                prev->next = current->next;
            }
            // Free the current node
            free(current);
            return head;
        }
        // Move to the next node
        prev = current;
        current = current->next;
    }
    return head;
}

// Free all nodes in the list
void freeAll(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        // Free the current node
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Print all reminders in the list
void printList(struct Node* head) {
    struct Node* current = head;
    // Iterate through the list and print each reminder
    while (current != NULL) {
        printf("%s\n", current->reminder);
        current = current->next;
    }
}
