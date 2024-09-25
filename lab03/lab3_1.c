#include <stdio.h>

// User enters 4 integers

int main()
{
  int a, b, c, d;
  printf("Enter 4 integers: ");
  scanf("%d %d %d %d", &a, &b, &c, &d);

  // Get largest
  int largest = a;
  if (b > largest)
    largest = b;
  if (c > largest)
    largest = c;
  if (d > largest)
    largest = d;

  // Get smallest
  int smallest = a;
  if (b < smallest)
    smallest = b;
  if (c < smallest)
    smallest = c;
  if (d < smallest)
    smallest = d;

  printf("Largest: %d\n", largest);
  printf("Smallest: %d\n", smallest);

  return 0;
}