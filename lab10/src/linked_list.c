#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* addNode(Node *head, Person person) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    newNode->person = person;
    newNode->next = head;
    return newNode;
}

Node* findNode(Node *head, int id, Role role) {
    Node *current = head;
    while (current) {
        if ((role == STUDENT && current->person.info.student.StudentId == id) ||
            (role == PROFESSOR && current->person.info.professor.ProfessorId == id)) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Node* deleteNode(Node *head, int id, Role role) {
    Node *current = head, *prev = NULL;

    while (current) {
        if ((role == STUDENT && current->person.info.student.StudentId == id) ||
            (role == PROFESSOR && current->person.info.professor.ProfessorId == id)) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return head;
}

void printList(const Node *head) {
    const Node *current = head;
    while (current) {
        printPerson(&current->person);
        printf("-----------------\n");
        current = current->next;
    }
}

void freeList(Node *head) {
    Node *current = head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}