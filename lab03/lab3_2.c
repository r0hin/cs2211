#include <stdio.h>

int main()
{
  // Number of days in the month
  int days;
  printf("Enter the number of days in the month: ");
  scanf("%d", &days);

  // Which day it starts on (1-7)
  int start;
  printf("Enter the day of the week the month starts on (1=Sunday, 7=Saturday): ");
  scanf("%d", &start);

  // Print the calendar
  printf("Sun Mon Tue Wed Thu Fri Sat\n");
  for (int i = 1; i < start; i++)
  {
    printf("    ");
  }

  for (int i = 1; i <= days; i++)
  {
    printf("%3d ", i);
    if ((i + start - 1) % 7 == 0)
    {
      printf("\n");
    }
  }

  return 0;
}