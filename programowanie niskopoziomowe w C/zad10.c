#include <stdio.h>


int main() {
  char line[80];
  static const char *filename = "plik_zad_10.txt";
  FILE *input;

  input = fopen(filename, "r");
  printf("SUMA\n");
  for( int nlines = 0;
       fgets(line, sizeof(line), input) != NULL;
       nlines++ )
  {
    int value, sum = 0;
    int n;
    for( char *p = line; sscanf(p, "%d%n", &value, &n) > 0; p += n ) {
      sum += value;
      printf(" | %d",value);
    }
    printf(" | %d\n", sum );
  }

  return 0;
}
