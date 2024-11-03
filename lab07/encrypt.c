// Take an input string from command line $ ./encrypt Hello World 1
// and integer and shift the characters in the string by the integer amount

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./encrypt <string> <shift>\n");
    return 1;
  }

  int shift = atoi(argv[2]);
  char *str = argv[1];

  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = (str[i] - 'A' + shift) % 26 + 'A';
    }
    else if (str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = (str[i] - 'a' + shift) % 26 + 'a';
    }
  }

  printf("%s\n", str);
  return 0;
}