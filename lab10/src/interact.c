#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "interact.h"

// Display the main menu and return the user's choice
int displayMenu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Add a person\n");
    printf("2. Update a person\n");
    printf("3. Print people\n");
    printf("4. Delete a person\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Helper function to check if a string contains digits
int containsDigits(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

// Prompt the user to enter a person's details (role first)
Person getPersonDetails() {
    Person person;

    // Get role
    do {
        printf("Enter role (0 for Student, 1 for Professor): ");
        scanf("%d", (int *)&person.role);
    } while (person.role != STUDENT && person.role != PROFESSOR);

    // Get name (validate to ensure no digits)
    do {
        printf("Enter name (letters only, max 50 characters): ");
        scanf(" %50[^\n]", person.name);
        if (containsDigits(person.name)) {
            printf("Name cannot contain numbers. Please try again.\n");
        }
    } while (containsDigits(person.name));

    // Get role-specific information
    if (person.role == STUDENT) {
        // Validate positive Student ID
        do {
            printf("Enter Student ID (positive integer): ");
            scanf("%d", &person.info.student.StudentId);
            if (person.info.student.StudentId <= 0) {
                printf("Student ID must be positive. Try again.\n");
            }
        } while (person.info.student.StudentId <= 0);

        printf("Enter GPA (floating-point number): ");
        scanf("%f", &person.info.student.GPA);
    } else {
        // Validate positive Professor ID
        do {
            printf("Enter Professor ID (positive integer): ");
            scanf("%d", &person.info.professor.ProfessorId);
            if (person.info.professor.ProfessorId <= 0) {
                printf("Professor ID must be positive. Try again.\n");
            }
        } while (person.info.professor.ProfessorId <= 0);

        printf("Enter Salary (positive value): ");
        scanf("%lf", &person.info.professor.salary);
    }

    return person;
}

// Prompt for role, name, and ID for delete or update
void getRoleNameID(Role *role, char *name, int *id) {
    // Get role
    do {
        printf("Enter role (0 for Student, 1 for Professor): ");
        scanf("%d", (int *)role);
    } while (*role != STUDENT && *role != PROFESSOR);

    // Get name (validate to ensure no digits)
    do {
        printf("Enter name (letters only, max 50 characters): ");
        scanf(" %50[^\n]", name);
        if (containsDigits(name)) {
            printf("Name cannot contain numbers. Please try again.\n");
        }
    } while (containsDigits(name));

    // Validate positive ID
    do {
        if (*role == STUDENT) {
            printf("Enter Student ID (positive integer): ");
        } else {
            printf("Enter Professor ID (positive integer): ");
        }
        scanf("%d", id);
        if (*id <= 0) {
            printf("ID must be positive. Try again.\n");
        }
    } while (*id <= 0);
}

// Prompt for new GPA or Salary
void getNewGPAOrSalary(Person *person) {
    if (person->role == STUDENT) {
        printf("Enter new GPA: ");
        scanf("%f", &person->info.student.GPA);
    } else {
        printf("Enter new Salary: ");
        scanf("%lf", &person->info.professor.salary);
    }
}