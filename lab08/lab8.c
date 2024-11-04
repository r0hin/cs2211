#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PEOPLE 100
#define NAME_LENGTH 51

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

Person people[MAX_PEOPLE];
int numPeople = 0;

// Function Prototypes
void printMenu(void);
bool personExist(enum RoleType role, int id);
void addPerson(void);
void updatePerson(void);
void deletePerson(void);
void readName(char *name);
void printPerson(Person *p);
Person *findPersonByName(const char *name);

int main()
{
  int choice;

  while (1)
  {
    printMenu();
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case ADD:
      addPerson();
      break;
    case UPDATE:
      updatePerson();
      break;
    case PRINT:
      for (int i = 0; i < numPeople; i++)
      {
        printPerson(&people[i]);
      }
      break;
    case DELETE:
      deletePerson();
      break;
    case EXIT:
      printf("Exiting program.\n");
      return 0;
    default:
      printf("Invalid choice! Please try again.");
    }
  }
  return 0;
}

void printMenu(void)
{
  printf("\nMenu Options:\n");
  printf("1. Add Person\n");
  printf("2. Update Person\n");
  printf("3. Print All People\n");
  printf("4. Delete Person\n");
  printf("5. Exit\n");
}

bool personExist(enum RoleType role, int id)
{
  for (int i = 0; i < numPeople; i++)
  {
    if (people[i].role == role)
    {
      if ((role == STUDENT && people[i].info.student.StudentId == id) ||
          (role == PROFESSOR && people[i].info.professor.ProfessorId == id))
      {
        return true;
      }
    }
  }
  return false;
}

Person *findPersonByName(const char *name)
{
  for (int i = 0; i < numPeople; i++)
  {
    if (strcmp(people[i].name, name) == 0)
    {
      return &people[i];
    }
  }
  return NULL;
}

void addPerson(void)
{
  if (numPeople >= MAX_PEOPLE)
  {
    printf("Database is full!\n");
    return;
  }

  Person p;
  int id;
  printf("\nEnter role (0 for STUDENT, 1 for PROFESSOR): ");
  scanf("%d", (int *)&p.role);

  if (p.role != STUDENT && p.role != PROFESSOR)
  {
    printf("Invalid role! Please try again.");
    return;
  }

  readName(p.name);

  if (p.role == STUDENT)
  {
    printf("Enter Student ID: ");
    scanf("%d", &id);
    if (personExist(STUDENT, id))
    {
      printf("A student with this ID already exists!\n");
      return;
    }
    p.info.student.StudentId = id;
    printf("Enter GPA: ");
    scanf("%f", &p.info.student.GPA);
  }
  else
  {
    printf("Enter Professor ID: ");
    scanf("%d", &id);
    if (personExist(PROFESSOR, id))
    {
      printf("A professor with this ID already exists!\n");
      return;
    }
    p.info.professor.ProfessorId = id;
    printf("Enter salary: ");
    scanf("%lf", &p.info.professor.salary);
  }

  people[numPeople++] = p;
  printf("Person added successfully.\n");
}

void updatePerson(void)
{
  char name[NAME_LENGTH];
  printf("Enter name of person to update: ");
  readName(name);

  Person *person = findPersonByName(name);
  if (person == NULL)
  {
    printf("Person not found!\n");
    return;
  }

  printf("Updating details for %s\n", person->name);

  if (person->role == STUDENT)
  {
    printf("Enter new Student ID: ");
    scanf("%d", &person->info.student.StudentId);
    printf("Enter new GPA: ");
    scanf("%f", &person->info.student.GPA);
  }
  else
  {
    printf("Enter new Professor ID: ");
    scanf("%d", &person->info.professor.ProfessorId);
    printf("Enter new salary: ");
    scanf("%lf", &person->info.professor.salary);
  }
  printf("Person updated successfully.\n");
}

void deletePerson(void)
{
  char name[NAME_LENGTH];
  printf("Enter name of person to delete: ");
  readName(name);

  for (int i = 0; i < numPeople; i++)
  {
    if (strcmp(people[i].name, name) == 0)
    {
      for (int j = i; j < numPeople - 1; j++)
      {
        people[j] = people[j + 1];
      }
      numPeople--;
      printf("Person deleted successfully.\n");
      return;
    }
  }
  printf("Person not found!\n");
}

void readName(char *name)
{
  printf("Enter name: ");
  while (getchar() != '\n')
    ; // Clear input buffer
  fgets(name, NAME_LENGTH, stdin);
  name[strcspn(name, "\n")] = 0; // Remove newline character
}

void printPerson(Person *p)
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