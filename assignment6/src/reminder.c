// reminder.c: 2211A Assignment 5 by Rohin Arya (251371185)
// This file includes the implementation of the functions declared in reminder.h.

#include "reminder.h"

struct Month month;

void initializeMonth(void) {
    // Initialize month information
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    // Set month_idx, month_days, start_day
    month.month_idx = t->tm_mon;
    t->tm_mday = 1;
    mktime(t);
    month.start_day = t->tm_wday;
    month.month_days = t->tm_mday;
    
    // Find the last day of the month
    while (t->tm_mon == month.month_idx) {
        month.month_days = t->tm_mday;
        t->tm_mday++;
        mktime(t);
    }

    // Initialize reminders array
    for (int i = 0; i < 31; i++) {
        month.reminders[i] = NULL;
    }
}

// Free up the memory allocated for reminders!
void cleanup_calendar(void) {
    for (int i = 0; i < month.month_days; i++) {
        if (month.reminders[i] != NULL) {
            freeAll(month.reminders[i]);
            month.reminders[i] = NULL;
        }
    }
}

// Function to read a reminder from user input
int read_reminder(char *str, int n)
{
  if (fgets(str, n, stdin) != NULL)
  {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
      str[len - 1] = '\0'; // Remove newline character
    }
    return 1;
  }
  return 0;
}

void print_calendar(void) {
    // Static arrays for month and day names
    static const char* month_names[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    
    // Static array for day names
    static const char* day_names[] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    
    // Print the calendar
    printf("\n%s Calendar:\n", month_names[month.month_idx]);
    printf("----------------------------------------\n");
    printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print initial spaces for the starting day
    for (int i = 0; i < month.start_day; i++) {
        printf("     ");
    }

    // Print each day of the month
    for (int day = 1; day <= month.month_days; day++) {
        if (month.reminders[day-1] != NULL) {
            printf("[%2d] ", day);
        } else {
            printf(" %2d  ", day);
        }

        // Start new line after Saturday
        if ((day + month.start_day) % 7 == 0 || day == month.month_days) {
            printf("\n");
        }
    }

    // Horizontal line nicely separates calendar from reminders
    printf("----------------------------------------\n");

    // Print reminders for days that have them
    printf("\n%s Reminders:\n", month_names[month.month_idx]);
    for (int day = 1; day <= month.month_days; day++) {
        if (month.reminders[day-1] != NULL) {
            struct Node* current = month.reminders[day-1];
            printf("%s %2d:: ", day_names[(day + month.start_day - 1) % 7], day);
            
            // Print first reminder on the same line
            printf("(1) %s\n", current->reminder);
            current = current->next;
            
            // Print remaining reminders with proper alignment
            int count = 2;
            while (current != NULL) {
                printf("         (%d) %s\n", count++, current->reminder);
                current = current->next;
            }
            printf("\n");
        }
    }
}