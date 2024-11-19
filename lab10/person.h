#ifndef PERSON_H
#define PERSON_H

#define MAX_NAME_LENGTH 51

// Enum for Role
typedef enum {
    STUDENT,
    PROFESSOR
} Role;

// Struct for Student
typedef struct {
    int StudentId;
    float GPA;
} Student;

// Struct for Professor
typedef struct {
    int ProfessorId;
    double salary;
} Professor;

// Union for role-specific info
typedef union {
    Student student;
    Professor professor;
} RoleInfo;

// Struct for Person
typedef struct {
    Role role;
    char name[MAX_NAME_LENGTH];
    RoleInfo info;
} Person;

// Function prototypes
void printPerson(const Person *person);

#endif // PERSON_H