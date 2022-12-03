#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_FILE "sample.txt"
#define INPUT_FILE "input.txt"

/*
check the next character
*/
int fpeek(FILE * const fp) {
  const int c = getc(fp);
  return c == EOF ? EOF : ungetc(c, fp);
}