// main.c: 2211A Assignment 5 by Rohin Arya (251371185)
// This file includes the main function to interact with the reminder calendar.

#include <stdio.h>
#include "reminder.h"
#include "interact.h"

// Define the Month instance for November
struct Month November = {
    .month_days = 30,
    .start_day = 5,
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

int main() {
    // Initialize month and set up signal handlers
    initializeMonth();
    setupSignalHandlers();
    
    // Load existing reminders from file
    readingFromFile();
    
    // If no reminders exist, ask for one before showing calendar
    if (!hasReminders()) {
        printf("Welcome to gcal!\n");
        readReminder();
    }
    
    // Main program loop
    while (1) {
        print_calendar();
        readReminder();
    }
    
    return 0;
}