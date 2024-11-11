#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_LENGTH 51

// Enums
enum RoleType
{
  STUDENT,
  PROFESSOR
};

enum Choice
{
  ADD = 1,
  UPDATE,
  PRINT,
  DELETE,
  EXIT
};

// Structures and Unions
typedef struct
{
  int StudentId;
  float GPA;
} StudentInfo;

typedef struct
{
  int ProfessorId;
  double salary;
} ProfessorInfo;

typedef union
{
  StudentInfo student;
  ProfessorInfo professor;
} RoleInfo;

typedef struct
{
  enum RoleType role;
  char name[NAME_LENGTH];
  RoleInfo info;
} Person;

typedef struct Node
{
  Person person;
  struct Node *next;
} Node;

// Function Prototypes
void printMenu(void);
void addPerson(Node **head);
void updatePerson(Node *head);
void deletePerson(Node **head);
void printAllPeople(Node *head);
void readName(char *name);
int readPositiveInteger(const char *prompt);
float readValidGPA(const char *prompt);
bool isValidName(const char *name);
void clearInputBuffer(void);
Node *findPerson(Node *head, enum RoleType role, int id);
bool personExists(Node *head, enum RoleType role, int id);
void printPerson(const Person *p);

// Main Function
int main()
{
  Node *head = NULL;
  int choice;

  while (1)
  {
    printMenu();
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer(); // Clear buffer after scanf

    switch (choice)
    {
    case ADD:
      addPerson(&head);
      break;
    case UPDATE:
      updatePerson(head);
      break;
    case PRINT:
      printAllPeople(head);
      break;
    case DELETE:
      deletePerson(&head);
      break;
    case EXIT:
      printf("Exiting program.\n");
      return 0;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }
  return 0;
}

// Print the menu options
void printMenu(void)
{
  printf("\nMenu Options:\n");
  printf("1. Add Person\n");
  printf("2. Update Person\n");
  printf("3. Print All People\n");
  printf("4. Delete Person\n");
  printf("5. Exit\n");
}

// Add a person
void addPerson(Node **head)
{
  Person newPerson;

  while (1)
  {
    printf("\nEnter role (0 for STUDENT, 1 for PROFESSOR): ");
    scanf("%d", (int *)&newPerson.role);
    clearInputBuffer();
    if (newPerson.role == STUDENT || newPerson.role == PROFESSOR)
    {
      break;
    }
    printf("Invalid role! Please try again.\n");
  }

  readName(newPerson.name);

  if (newPerson.role == STUDENT)
  {
    newPerson.info.student.StudentId = readPositiveInteger("Enter Student ID: ");
    if (personExists(*head, STUDENT, newPerson.info.student.StudentId))
    {
      printf("A student with this ID already exists!\n");
      return;
    }
    newPerson.info.student.GPA = readValidGPA("Enter GPA: ");
  }
  else
  {
    newPerson.info.professor.ProfessorId = readPositiveInteger("Enter Professor ID: ");
    if (personExists(*head, PROFESSOR, newPerson.info.professor.ProfessorId))
    {
      printf("A professor with this ID already exists!\n");
      return;
    }
    printf("Enter salary: ");
    scanf("%lf", &newPerson.info.professor.salary);
    clearInputBuffer();
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->person = newPerson;
  newNode->next = *head;
  *head = newNode;

  printf("Person added successfully.\n");
}

// Update a person
void updatePerson(Node *head)
{
  int id;
  enum RoleType role;

  printf("\nEnter role (0 for STUDENT, 1 for PROFESSOR): ");
  scanf("%d", (int *)&role);
  clearInputBuffer();
  id = readPositiveInteger("Enter ID: ");

  Node *node = findPerson(head, role, id);
  if (!node)
  {
    printf("Person not found!\n");
    return;
  }

  printf("Updating details for %s\n", node->person.name);
  if (role == STUDENT)
  {
    node->person.info.student.StudentId = readPositiveInteger("Enter new Student ID: ");
    node->person.info.student.GPA = readValidGPA("Enter new GPA: ");
  }
  else
  {
    node->person.info.professor.ProfessorId = readPositiveInteger("Enter new Professor ID: ");
    printf("Enter new salary: ");
    scanf("%lf", &node->person.info.professor.salary);
    clearInputBuffer();
  }

  printf("Person updated successfully.\n");
}

// Delete a person
void deletePerson(Node **head)
{
  int id;
  enum RoleType role;

  printf("\nEnter role (0 for STUDENT, 1 for PROFESSOR): ");
  scanf("%d", (int *)&role);
  clearInputBuffer();
  id = readPositiveInteger("Enter ID: ");

  Node *current = *head, *prev = NULL;
  while (current)
  {
    if (current->person.role == role &&
        ((role == STUDENT && current->person.info.student.StudentId == id) ||
         (role == PROFESSOR && current->person.info.professor.ProfessorId == id)))
    {
      if (prev)
      {
        prev->next = current->next;
      }
      else
      {
        *head = current->next;
      }
      free(current);
      printf("Person deleted successfully.\n");
      return;
    }
    prev = current;
    current = current->next;
  }
  printf("Person not found!\n");
}

// Print all people
void printAllPeople(Node *head)
{
  Node *current = head;
  if (!current)
  {
    printf("No people in the database.\n");
    return;
  }
  while (current)
  {
    printPerson(&current->person);
    current = current->next;
  }
}

// Validate and read a name
void readName(char *name)
{
  char buffer[NAME_LENGTH];
  while (1)
  {
    printf("Enter name: ");
    fgets(buffer, NAME_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
    if (isValidName(buffer))
    {
      strncpy(name, buffer, NAME_LENGTH);
      return;
    }
    printf("Invalid name! Names cannot contain numbers. Please try again.\n");
  }
}

// Read and validate a positive integer
int readPositiveInteger(const char *prompt)
{
  int value;
  char buffer[100];
  while (1)
  {
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    if (sscanf(buffer, "%d", &value) == 1 && value > 0)
    {
      return value;
    }
    printf("Invalid input! Please enter a positive integer.\n");
  }
}

// Read and validate GPA
float readValidGPA(const char *prompt)
{
  float value;
  char buffer[100];
  while (1)
  {
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    if (sscanf(buffer, "%f", &value) == 1)
    {
      return value;
    }
    printf("Invalid input! Please enter a valid GPA.\n");
  }
}

// Validate that a name does not contain numbers
bool isValidName(const char *name)
{
  for (int i = 0; name[i] != '\0'; i++)
  {
    if (isdigit(name[i]))
    {
      return false;
    }
  }
  return true;
}

// Clear input buffer
void clearInputBuffer(void)
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Check if a person exists
bool personExists(Node *head, enum RoleType role, int id)
{
  return findPerson(head, role, id) != NULL;
}

// Find a person by role and ID
Node *findPerson(Node *head, enum RoleType role, int id)
{
  Node *current = head;
  while (current)
  {
    if (current->person.role == role &&
        ((role == STUDENT && current->person.info.student.StudentId == id) ||
         (role == PROFESSOR && current->person.info.professor.ProfessorId == id)))
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Print a person's details
void printPerson(const Person *p)
{
  printf("\nName: %s\n", p->name);
  if (p->role == STUDENT)
  {
    printf("Role: Student\n");
    printf("Student ID: %d\n", p->info.student.StudentId);
    printf("GPA: %.2f\n", p->info.student.GPA);
  }
  else
  {
    printf("Role: Professor\n");
    printf("Professor ID: %d\n", p->info.professor.ProfessorId);
    printf("Salary: %.2lf\n", p->info.professor.salary);
  }
}