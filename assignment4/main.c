// main.c: 2211A Assignment4 by Rohin Arya (251371185)
// This file includes the main function to interact with the reminder calendar.

#include <stdio.h>
#include "reminder.h"

// Define the Month instance for November
struct Month November = {
    .month_days = 30,
    .start_day = 5,
};

int main()
{
  int day;
  char reminder[MAX_STR_LEN];

  while (1)
  {
    // Prompt the user for the day and check if they want to exit
    printf("\nEnter day and reminder (0 to exit): ");
    if (scanf("%d", &day) != 1 || day == 0)
      break;

    getchar(); // Clear newline character from buffer

    // Check if the day is valid for November
    if (day < 1 || day > November.month_days)
    {
      printf("Invalid day. Please enter a day between 1 and %d.\n", November.month_days);
      continue;
    }

    // Use read_reminder to get the reminder text
    if (!read_reminder(reminder, MAX_STR_LEN))
    {
      printf("Failed to read reminder.\n");
      continue;
    }

    // Insert the reminder for the specified day
    insert_to_calendar(day, reminder);

    // Display the updated calendar and list of reminders
    print_calendar();
  }

  return 0;
}