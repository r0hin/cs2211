#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplication(int m, int n, int numbers[m][n]);
void addition(int m, int n, int numbers[m][n]);
void subtraction(int m, int n, int numbers[m][n]);
void display(int m, int n, int numbers[m][n]);

int main()
{
  int n;
  printf("Enter the number of columns (n): ");
  scanf("%d", &n);

  int numbers[3][n]; // 2D array with 3 rows and n columns

  // Input for the first row
  printf("Enter %d numbers for the first row:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &numbers[0][i]);
  }

  // Generate random numbers between 0 and 200 for the second row
  srand(time(0)); // Seed the random number generator
  for (int i = 0; i < n; i++)
  {
    numbers[1][i] = rand() % 201; // Random number between 0 and 200
  }

  // Initialize the third row to 0
  for (int i = 0; i < n; i++)
  {
    numbers[2][i] = 0;
  }

  int choice;
  while (1)
  {
    printf("\nChoose an operation:\n");
    printf("(0) Addition\n(1) Subtraction\n(2) Multiplication\n(3) Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 3)
    {
      printf("Exiting program.\n");
      break;
    }

    switch (choice)
    {
    case 0:
      addition(3, n, numbers);
      break;
    case 1:
      subtraction(3, n, numbers);
      break;
    case 2:
      multiplication(3, n, numbers);
      break;
    default:
      printf("Invalid choice. Try again.\n");
      continue;
    }

    display(3, n, numbers);
  }

  return 0;
}

void multiplication(int m, int n, int numbers[m][n])
{
  for (int i = 0; i < n; i++)
  {
    numbers[2][i] = numbers[0][i] * numbers[1][i];
  }
}

void addition(int m, int n, int numbers[m][n])
{
  for (int i = 0; i < n; i++)
  {
    numbers[2][i] = numbers[0][i] + numbers[1][i];
  }
}

void subtraction(int m, int n, int numbers[m][n])
{
  for (int i = 0; i < n; i++)
  {
    numbers[2][i] = numbers[0][i] - numbers[1][i];
  }
}

void display(int m, int n, int numbers[m][n])
{
  printf("Current state of the array:\n");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", numbers[i][j]);
    }
    printf("\n");
  }
}