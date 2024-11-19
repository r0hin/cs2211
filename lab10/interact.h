#ifndef INTERACT_H
#define INTERACT_H

#include "person.h"

// Displays the main menu and returns the user's choice
int displayMenu();

// Prompts for a person's details (role first)
Person getPersonDetails();

// Prompts for role, name, and ID to delete or update a person
void getRoleNameID(Role *role, char *name, int *id);

// Prompts for new GPA/Salary when updating a person
void getNewGPAOrSalary(Person *person);

#endif // INTERACT_H