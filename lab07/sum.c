// Write a program named sum.c that takes a list of numbers as command-line arguments and prints the sum of those numbers.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: ./sum <num1> <num2> ... <numN>\n");
    return 1;
  }

  int sum = 0;
  for (int i = 1; i < argc; i++)
  {
    sum += atoi(argv[i]);
  }

  printf("Sum: %d\n", sum);
  return 0;
}