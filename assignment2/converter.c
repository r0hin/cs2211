// converter.c: This program converts between different units of measurement.
// Written by Rohin Arya (rarya4), 251371185, for CS2211 on Oct 9, 2024

#include <stdio.h>

int main()
{
  int option = 0;

  while (1)
  {
    // While option is not 1-5
    while (option < 1 || option > 5)
    {
      printf("Enter a number corresponding to what you want to do:\n");
      printf("1. Convert between grams and ounces\n");
      printf("2. Convert between square meters and square yards\n");
      printf("3. Convert between liters and pints\n");
      printf("4. Convert between meteres and feet\n");
      printf("5. Quit\n");

      scanf("%d", &option);
    }

    if (option == 5)
    {
      return 1;
    }

    // Get the direction of the conversion
    float conversionFactor = 0.0;
    if (option == 1)
    {
      printf("Enter which direction you want to convert\n");
      printf("G: Grams to Ounces\n");
      printf("O: Ounces to Grams\n");
      char direction;
      scanf(" %c", &direction);
      if (direction == 'G')
      {
        conversionFactor = 0.03527;
      }
      else if (direction == 'O')
      {
        conversionFactor = 1 / 0.03527;
      }
      else
      {
        printf("Invalid direction \n");
        conversionFactor = 0.0;
      }
    }
    if (option == 2)
    {
      printf("Enter which direction you want to convert\n");
      printf("M: Square Meters to Square Yards\n");
      printf("Y: Square Yards to Square Meters\n");
      char direction;
      scanf(" %c", &direction);
      if (direction == 'M')
      {
        conversionFactor = 1.19599;
      }
      else if (direction == 'Y')
      {
        conversionFactor = 1 / 1.19599;
      }
      else
      {
        printf("Invalid direction \n");
        conversionFactor = 0.0;
      }
    }
    else if (option == 3)
    {
      printf("Enter which direction you want to convert\n");
      printf("L: Liters to Pints\n");
      printf("P: Pints to Liters\n");
      char direction;
      scanf(" %c", &direction);
      if (direction == 'L')
      {
        conversionFactor = 2.11338;
      }
      else if (direction == 'P')
      {
        conversionFactor = 1 / 2.11338;
      }
      else
      {
        printf("Invalid direction \n");
        conversionFactor = 0.0;
      }
    }
    else if (option == 4)
    {
      printf("Enter which direction you want to convert\n");
      printf("M: Meters to Feet\n");
      printf("F: Feet to Meters\n");
      char direction;
      scanf(" %c", &direction);
      if (direction == 'M')
      {
        conversionFactor = 3.28084;
      }
      else if (direction == 'F')
      {
        conversionFactor = 1 / 3.28084;
      }
      else
      {
        printf("Invalid direction \n");
        conversionFactor = 0.0;
      }
    }

    if (conversionFactor == 0.0)
    {
      // Don't reset the option
      continue;
    }
    else
    {
      // Ask for input
      float input;
      printf("Enter the value you want to convert\n");
      scanf("%f", &input);

      // Perform the conversion
      float result = input * conversionFactor;
      printf("Your conversion is...: %f\n", result);

      // Reset the option
      option = 0;
    }
  }
}