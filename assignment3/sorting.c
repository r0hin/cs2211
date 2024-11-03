#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 10000

// Function Prototypes
void quickSort(int numbers[], int low, int high);
void bubbleSort(int numbers[], int n);
void fillRandomNumbers(int numbers[], int start, int end);
void displayArray(int numbers[], int m);
int partition(int numbers[], int low, int high);

int main()
{
  int n, m, choice;
  char command;
  time_t time1, time2;

  while (1)
  {
    // Prompt for n and m
    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    printf("Enter the array length (m): ");
    scanf("%d", &m);

    // Check that n <= m and both are even
    if (m < n || n % 2 != 0 || m % 2 != 0)
    {
      printf("Invalid input! Ensure m >= n and both are even numbers.\n");
      continue;
    }

    // Dynamically allocate memory for numbers array
    int **numbers = (int **)malloc(2 * sizeof(int *));
    numbers[0] = (int *)malloc(m * sizeof(int));
    numbers[1] = (int *)malloc(m * sizeof(int));

    if (numbers[0] == NULL || numbers[1] == NULL)
    {
      printf("Memory allocation failed.\n");
      return 1; // Exit if memory allocation fails
    }

    // Input n numbers into the first row of numbers array
    printf("Enter %d numbers:\n", n);
    int inputSuccess = 1;
    for (int i = 0; i < n; i++)
    {
      if (scanf("%d", &numbers[0][i]) != 1)
      { // Handle input errors
        inputSuccess = 0;
        break;
      }
    }

    // Fill the rest of the first row with random numbers if necessary
    if (!inputSuccess || n < m)
    {
      printf("Error in input. Filling remaining elements with random numbers.\n");
      fillRandomNumbers(numbers[0], n, m);
    }

    while (1)
    { // Submenu loop
      // Display the original array
      printf("Original array:\n");
      displayArray(numbers[0], m);

      // Prompt for sorting algorithm choice
      printf("Choose a sorting algorithm: (0) Quick sort, (1) Bubble sort: ");
      scanf("%d", &choice);

      // Copy the first row to the second row before sorting
      for (int i = 0; i < m; i++)
      {
        numbers[1][i] = numbers[0][i];
      }

      // Measure time and perform the chosen sorting algorithm
      time1 = time(NULL);
      if (choice == 0)
      {
        quickSort(numbers[1], 0, m - 1);
      }
      else if (choice == 1)
      {
        bubbleSort(numbers[1], m);
      }
      else
      {
        printf("Invalid choice. Exiting sorting process.\n");
        continue;
      }
      time2 = time(NULL);

      // Display the sorted array and time taken
      printf("Sorted array:\n");
      displayArray(numbers[1], m);
      printf("Sorting duration: %ld seconds\n", time2 - time1);

      // Command menu
      printf("\nOptions:\n(R) Re-generate random numbers and choose a new algorithm.\n");
      printf("(N) Enter new values for n and m and new numbers.\n");
      printf("(S) Use a different sorting algorithm on the same array.\n");
      printf("(Q) Quit.\n");
      printf("Enter your choice: ");
      scanf(" %c", &command);

      if (command == 'Q' || command == 'q')
      {
        // Free dynamically allocated memory
        free(numbers[0]);
        free(numbers[1]);
        free(numbers);
        return 0;
      }
      else if (command == 'R' || command == 'r')
      {
        // Refill with random numbers for the current n and m
        fillRandomNumbers(numbers[0], n, m);
      }
      else if (command == 'N' || command == 'n')
      {
        // Free dynamically allocated memory before new allocation
        free(numbers[0]);
        free(numbers[1]);
        free(numbers);
        break; // Exit submenu loop to re-enter n and m
      }
      else if (command == 'S' || command == 's')
      {
        // Re-sort using a different sorting algorithm on the same data
        continue;
      }
      else
      {
        printf("Invalid command. Please try again.\n");
      }
    }
  }
  return 0;
}

// QuickSort Helper Function
int partition(int numbers[], int low, int high)
{
  int pivot = numbers[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++)
  {
    if (numbers[j] < pivot)
    {
      i++;
      int temp = numbers[i];
      numbers[i] = numbers[j];
      numbers[j] = temp;
    }
  }
  int temp = numbers[i + 1];
  numbers[i + 1] = numbers[high];
  numbers[high] = temp;
  return i + 1;
}

// QuickSort Implementation
void quickSort(int numbers[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(numbers, low, high);
    quickSort(numbers, low, pi - 1);
    quickSort(numbers, pi + 1, high);
  }
}

// Bubble Sort Implementation
void bubbleSort(int numbers[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (numbers[j] > numbers[j + 1])
      {
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }
}

// Function to fill array with random numbers from a starting index
void fillRandomNumbers(int numbers[], int start, int end)
{
  srand(time(0));
  for (int i = start; i < end; i++)
  {
    numbers[i] = rand() % (MAX_RAND + 1);
  }
}

// Function to display the array with fixed width
void displayArray(int numbers[], int m)
{
  for (int i = 0; i < m; i++)
  {
    printf("%6d ", numbers[i]);
  }
  printf("\n");
}