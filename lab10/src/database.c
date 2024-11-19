#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interact.h"
#include "linked_list.h"

int main() {
    Node *head = NULL;
    int running = 1;

    while (running) {
        int choice = displayMenu();
        switch (choice) {
            case 1: {
                // Add a person
                Person person = getPersonDetails();
                head = addNode(head, person);
                break;
            }
            case 2: {
                // Update a person
                Role role;
                char name[MAX_NAME_LENGTH];
                int id;
                getRoleNameID(&role, name, &id);

                Node *node = findNode(head, id, role);
                if (node && strcmp(node->person.name, name) == 0) {
                    getNewGPAOrSalary(&node->person);
                    printf("Details updated successfully.\n");
                } else {
                    printf("Person not found.\n");
                }
                break;
            }
            case 3:
                // Print people
                printList(head);
                break;
            case 4: {
                // Delete a person
                Role role;
                char name[MAX_NAME_LENGTH];
                int id;
                getRoleNameID(&role, name, &id);

                Node *prev = NULL, *current = head;
                while (current) {
                    if ((current->person.role == role) &&
                        (strcmp(current->person.name, name) == 0) &&
                        ((role == STUDENT && current->person.info.student.StudentId == id) ||
                         (role == PROFESSOR && current->person.info.professor.ProfessorId == id))) {
                        // Match found
                        if (prev) {
                            prev->next = current->next;
                        } else {
                            head = current->next;
                        }
                        free(current);
                        printf("Person deleted successfully.\n");
                        break;
                    }
                    prev = current;
                    current = current->next;
                }
                if (!current) {
                    printf("Person not found.\n");
                }
                break;
            }
            case 5:
                // Exit
                running = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    freeList(head);
    printf("Exiting program. Goodbye!\n");
    return 0;
}