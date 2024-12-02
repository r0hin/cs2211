// main.c: 2211A Assignment 5 by Rohin Arya (251371185)
// This file includes the main function to interact with the reminder calendar.

#include <stdio.h>
#include <string.h>
#include "reminder.h"
#include "interact.h"

// Define the Month instance for December
struct Month month = {
    .month_days = 31,
    .start_day = 0 // Sunday
};

// Check if there are any reminders
int hasReminders(void) {
    for (int i = 0; i < month.month_days; i++) {
        if (month.reminders[i] != NULL) {
            return 1;
        }
    }
    return 0;
}

void print_usage(void) {
    printf("Usage:\n");
    printf("  gcal add <day> <reminder>    - Add a reminder to a specific day\n");
    printf("  gcal remove <day> <index>    - Remove a reminder from a specific day\n");
    printf("  gcal view                    - View calendar and all reminders\n");
    printf("  gcal today                   - View today's reminders\n");
}

int main(int argc, char *argv[]) {
    // Initialize month
    initializeMonth();
    
    // Load existing reminders from file
    readingFromFile();
    
    if (argc < 2) {
        print_usage();
        return 1;
    }
    
    const char *command = argv[1];
    
    if (strcmp(command, "add") == 0) {
        if (argc < 4) {
            printf("Error: gcal add requires a day and reminder\n");
            return 1;
        }
        
        int day = atoi(argv[2]);
        if (day < 1 || day > month.month_days) {
            printf("Error: Day must be between 1 and %d\n", month.month_days);
            return 1;
        }
        
        // Combine all remaining arguments as the reminder text
        char reminder[MAX_STR_LEN] = "";
        for (int i = 3; i < argc; i++) {
            strcat(reminder, argv[i]);
            if (i < argc - 1) strcat(reminder, " ");
        }
        
        add_reminder(day - 1, reminder);
        print_calendar();
        
    } else if (strcmp(command, "remove") == 0) {
        if (argc != 4) {
            printf("Error: gcal remove requires a day and index\n");
            return 1;
        }
        
        int day = atoi(argv[2]);
        int index = atoi(argv[3]);
        
        if (day < 1 || day > month.month_days) {
            printf("Error: Day must be between 1 and %d\n", month.month_days);
            return 1;
        }
        
        remove_reminder(day - 1, index - 1);
        print_calendar();
        
    } else if (strcmp(command, "view") == 0) {
        print_calendar();
        
    } else if (strcmp(command, "today") == 0) {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        int today = tm->tm_mday;
        
        printf("Today's reminders:\n");
        struct Node *current = month.reminders[today - 1];
        int index = 1;
        
        if (!current) {
            printf("No reminders for today.\n");
        }
        
        while (current != NULL) {
            printf("%d. %s\n", index++, current->reminder);
            current = current->next;
        }
        
    } else {
        printf("Unknown command: %s\n", command);
        print_usage();
        return 1;
    }
    
    // Save reminders to file
    writingToFile();
    
    return 0;
}