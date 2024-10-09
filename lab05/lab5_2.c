#include <stdio.h>

int main()
{
  printf("Enter a value for x: ");
  float x;
  scanf("%f", &x);

  // Solve 3x^5 + 2x^4− 5x^3− x^2 + 7x − 6

  float result = 3.0 * x * x * x * x * x + 2.0 * x * x * x * x - 5.0 * x * x * x - x * x + 7.0 * x - 6.0;

  printf("The result is: %f\n", result);
}