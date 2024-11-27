// interact.h: 2211A Assignment 5 by Rohin Arya (251371185)
// This file declares functions for user interaction and file I/O operations.

#ifndef INTERACT_H
#define INTERACT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "reminder.h"

// Function declarations for user input and file operations
void readReminder(void);
void flushBuffer(void);
void readingFromFile(void);
void writingToFile(void);
void setupSignalHandlers(void);
void handleSignal(int signal);

#endif
