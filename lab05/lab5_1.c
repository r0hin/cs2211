#include <stdio.h>

int main()
{
  // Enter a three digit number (use chars)
  printf("Enter a three digit number: ");
  char num1, num2, num3;
  scanf("%c%c%c", &num1, &num2, &num3);

  // Reverse it
  printf("Reversed: %c%c%c\n", num3, num2, num1);
}