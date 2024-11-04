// reminder.c: 2211A Assignment4 by Rohin Arya (251371185)
// This file includes the implementation of the functions declared in reminder.h.

#include "reminder.h"

// Function to insert a reminder for a specific day in November
void insert_to_calendar(int day, const char *value)
{
  if (day < 1 || day > November.month_days)
  {
    printf("Invalid day. Please enter a day between 1 and %d.\n", November.month_days);
    return;
  }

  // Store the reminder and mark the day as having a reminder
  strncpy(November.reminder_str[day - 1], value, MAX_STR_LEN - 1);
  November.reminder_str[day - 1][MAX_STR_LEN - 1] = '\0'; // Ensure null termination
  November.reminders[day - 1] = true;
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

// Function to display the November calendar, marking days with reminders in brackets
void print_calendar()
{
  printf("\nNovember Calendar:\n");
  printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

  // Print initial spaces for the starting day
  int start_day = November.start_day;
  for (int i = 0; i < start_day; i++)
  {
    printf("     "); // Five spaces to align days
  }

  // Print each day of November with brackets if there’s a reminder
  for (int day = 1; day <= November.month_days; day++)
  {
    if (November.reminders[day - 1])
    { // Day has a reminder
      printf("(%2d) ", day);
    }
    else
    { // Day has no reminder
      printf(" %2d  ", day);
    }

    // Move to the next line after Saturday (every 7 days)
    if ((start_day + day) % 7 == 0)
    {
      printf("\n");
    }
  }
  printf("\n");

  // Display each reminder below the calendar
  printf("\nReminders:\n");
  for (int i = 1; i <= November.month_days; i++)
  {
    if (November.reminders[i - 1])
    { // Print only days with reminders
      printf("Day %2d: %s\n", i, November.reminder_str[i - 1]);
    }
  }
}