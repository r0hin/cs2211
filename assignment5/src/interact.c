// interact.c: 2211A Assignment 5 by Rohin Arya (251371185)
// This file implements user interaction functions and file I/O operations.

#include "interact.h"
#include <signal.h>
#include <ctype.h>

#define REMINDER_FILE "reminders.txt"

// Clear input buffer
void flushBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Handle program interruption signals
void handleSignal(int signal) {
    printf("\nReceived signal %d. Saving reminders and exiting...\n", signal);
    writingToFile();
    exit(0);
}

// Set up signal handlers for SIGINT, SIGTERM, and SIGSEGV
void setupSignalHandlers(void) {
    signal(SIGINT, handleSignal);
    signal(SIGTERM, handleSignal);
    signal(SIGSEGV, handleSignal);
}

// Read a reminder from user input
void readReminder(void) {
    int day;
    char input[MAX_REMINDER_LENGTH];
    
    printf("Enter day and reminder (0 to quit): ");
    // Read input from user
    if (fgets(input, MAX_REMINDER_LENGTH, stdin) != NULL) {
        if (sscanf(input, "%d", &day) != 1) {
            printf("Invalid input format. Please enter day followed by reminder.\n");
            return;
        }
        
        // Check if user wants to quit
        if (day == 0) {
            writingToFile();
            cleanup_calendar();
            exit(0);
        }
        
        // Check if day is valid
        if (day < 1 || day > month.month_days) {
            printf("Invalid day. Please enter a number between 1 and %d.\n", month.month_days);
            return;
        }
        
        // Find the start of the reminder text (after the day number)
        char* reminder_start = input;
        while (*reminder_start != '\0' && !isspace(*reminder_start)) {
            reminder_start++;
        }
        // Skip any additional whitespace
        while (*reminder_start != '\0' && isspace(*reminder_start)) {
            reminder_start++;
        }
        
        if (*reminder_start == '\0') {
            printf("No reminder text provided.\n");
            return;
        }
        
        // Remove trailing newline if present
        size_t len = strlen(reminder_start);
        if (len > 0 && reminder_start[len-1] == '\n') {
            reminder_start[len-1] = '\0';
        }
        
        month.reminders[day-1] = addNode(month.reminders[day-1], reminder_start);
    }
}

// Save reminders to file
void writingToFile(void) {
    FILE *fp = fopen(REMINDER_FILE, "w");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing!\n");
        return;
    }

    // Write reminders to file
    for (int i = 0; i < month.month_days; i++) {
        struct Node* current = month.reminders[i];
        while (current != NULL) {
            fprintf(fp, "%d|%s\n", i + 1, current->reminder);
            current = current->next;
        }
    }
    fclose(fp);
}

// Load reminders from file
void readingFromFile(void) {
    FILE *fp = fopen(REMINDER_FILE, "r");
    if (!fp) {
        return; // File doesn't exist yet, which is fine
    }

    char line[MAX_REMINDER_LENGTH + 10];
    // Read reminders from file
    while (fgets(line, sizeof(line), fp)) {
        int day;
        char reminder[MAX_REMINDER_LENGTH];
        
        // Split the line into day and reminder
        char* delimiter = strchr(line, '|');
        if (delimiter) {
            // Extract day and reminder
            *delimiter = '\0';
            day = atoi(line);
            strcpy(reminder, delimiter + 1);
            
            // Remove trailing newline if present
            size_t len = strlen(reminder);
            if (len > 0 && reminder[len-1] == '\n') {
                reminder[len-1] = '\0';
            }
            
            // Add the reminder to the corresponding day
            if (day >= 1 && day <= month.month_days) {
                month.reminders[day-1] = addNode(month.reminders[day-1], reminder);
            }
        }
    }
    fclose(fp);
}
