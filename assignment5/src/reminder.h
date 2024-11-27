// reminder.h: 2211A Assignment 5 by Rohin Arya (251371185)
// This file defines the Month structure and calendar-related functions.

#ifndef REMINDER_H
#define REMINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "linked_list.h"

#define MAX_STR_LEN 100

// Structure to hold month information and reminders
struct Month {
    int month_idx;       // Current month (0-11)
    int month_days;      // Number of days in the month
    int start_day;       // First day of month (0=Sunday)
    struct Node* reminders[31];  // Array of linked lists for reminders
};

// Global month instance
extern struct Month month;

// Function declarations for calendar operations
void initializeMonth(void);
void print_calendar(void);
void cleanup_calendar(void);

#endif