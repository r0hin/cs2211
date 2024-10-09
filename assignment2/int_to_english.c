// int_to_english.c: This program converts a number to English words.
// Written by Rohin Arya (rarya4), 251371185, for CS2211 on Oct 9, 2024

#include <stdio.h>

int main()
{
  // Get the number to convert
  int number;

  while (number != 0)
  {
    printf("Please enter a value (1-999, 0 to quit): ");
    scanf("%d", &number);

    if (number == 0)
    {
      return 1;
    }

    printf("You entered the number ");

    // Convert the number to English
    int hundreds = number / 100;
    int tens = (number % 100) / 10;
    int ones = number % 10;

    if (hundreds > 0)
    {
      switch (hundreds)
      {
      case 1:
        printf("one hundred ");
        break;
      case 2:
        printf("two hundred ");
        break;
      case 3:
        printf("three hundred ");
        break;
      case 4:
        printf("four hundred ");
        break;
      case 5:
        printf("five hundred ");
        break;
      case 6:
        printf("six hundred ");
        break;
      case 7:
        printf("seven hundred ");
        break;
      case 8:
        printf("eight hundred ");
        break;
      case 9:
        printf("nine hundred ");
        break;
      }
    }

    if (tens > 0)
    {
      switch (tens)
      {
      case 1:
        switch (ones)
        {
        case 0:
          printf("ten\n");
          break;
        case 1:
          printf("eleven\n");
          break;
        case 2:
          printf("twelve\n");
          break;
        case 3:
          printf("thirteen\n");
          break;
        case 4:
          printf("fourteen\n");
          break;
        case 5:
          printf("fifteen\n");
          break;
        case 6:
          printf("sixteen\n");
          break;
        case 7:
          printf("seventeen\n");
          break;
        case 8:
          printf("eighteen\n");
          break;
        case 9:
          printf("nineteen\n");
          break;
        }
        break;
      case 2:
        printf("twenty ");
        break;
      case 3:
        printf("thirty ");
        break;
      case 4:
        printf("forty ");
        break;
      case 5:
        printf("fifty ");
        break;
      case 6:
        printf("sixty ");
        break;
      case 7:
        printf("seventy ");
        break;
      case 8:
        printf("eighty ");
        break;
      case 9:
        printf("ninety ");
        break;
      }
    }

    if (tens != 1)
    {
      switch (ones)
      {
      case 1:
        printf("one\n");
        break;
      case 2:
        printf("two\n");
        break;
      case 3:
        printf("three\n");
        break;
      case 4:
        printf("four\n");
        break;
      case 5:
        printf("five\n");
        break;
      case 6:
        printf("six\n");
        break;
      case 7:
        printf("seven\n");
        break;
      case 8:
        printf("eight\n");
        break;
      case 9:
        printf("nine\n");
        break;
      }
    }
  }
}