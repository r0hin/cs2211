// Write a program named reverse.c that takes a list of strings as command-line arguments and prints them in reverse order.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage: ./reverse <str1> <str2> ... <strN>\n");
    return 1;
  }

  for (int i = argc - 1; i > 0; i--)
  {
    printf("%s ", argv[i]);
  }

  return 0;
}