// earliest_date.c: This program finds the earliest date entered by the user.
// Written by Rohin Arya (rarya4), 251371185, for CS2211 on Oct 9, 2024

#include <stdio.h>

int main()
{
  // Continuusly prompt for dates
  int day, month, year;
  int earliestDay = 0, earliestMonth = 0, earliestYear = 0;

  // Input as mm/dd/yy

  while (1)
  {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    if (day == 0 && month == 0 && year == 0)
    {
      break;
    }

    if (earliestYear == 0)
    {
      earliestDay = day;
      earliestMonth = month;
      earliestYear = year;
    }
    else
    {
      if (year < earliestYear)
      {
        earliestDay = day;
        earliestMonth = month;
        earliestYear = year;
      }
      else if (year == earliestYear)
      {
        if (month < earliestMonth)
        {
          earliestDay = day;
          earliestMonth = month;
          earliestYear = year;
        }
        else if (month == earliestMonth)
        {
          if (day < earliestDay)
          {
            earliestDay = day;
            earliestMonth = month;
            earliestYear = year;
          }
        }
      }
    }
  }

  printf("%d/%d/%d is the earliest date\n", earliestMonth, earliestDay, earliestYear);
}