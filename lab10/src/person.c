#include <stdio.h>
#include "person.h"

// Print a person's details
void printPerson(const Person *person) {
    printf("Name: %s\n", person->name);
    if (person->role == STUDENT) {
        printf("Role: Student\n");
        printf("Student ID: %d\n", person->info.student.StudentId);
        printf("GPA: %.2f\n", person->info.student.GPA);
    } else {
        printf("Role: Professor\n");
        printf("Professor ID: %d\n", person->info.professor.ProfessorId);
        printf("Salary: %.2lf\n", person->info.professor.salary);
    }
}