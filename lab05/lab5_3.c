#include <stdio.h>

int main()
{
  printf("Enter two fractions separated by a plus sign: ");

  int num1, den1, num2, den2;
  scanf("%d/%d+%d/%d", &num1, &den1, &num2, &den2);

  // Add together

  int num = num1 * den2 + num2 * den1;
  int den = den1 * den2;

  printf("The sum is %d/%d\n", num, den);
}
