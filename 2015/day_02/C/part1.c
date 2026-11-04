#include <stdio.h>
#include <stdlib.h>

#define OPFILE "puzzle_input.txt"

int main(void) {
  FILE *fp = fopen(OPFILE, "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return EXIT_FAILURE;
  }

  char line[256];
  int length, width, height, s_flap, total, op = 0;
  int x1, x2, x3 = 0;

  while (fgets(line, sizeof(line), fp) != NULL) {
    sscanf(line, "%dx%dx%d", &length, &width, &height);
    x1 = length * width;
    x2 = width * height;
    x3 = height * length;
    op = (x1 * 2) + (x2 * 2) + (x3 * 2);
    if (x1 <= x2 && x1 <= x3) {
      s_flap = x1;
    } else if (x2 <= x1 && x2 <= x3) {
      s_flap = x2;
    } else {
      s_flap = x3;
    }
    total = total + op + s_flap;
  }
  printf("Total Square feet: %d\n", total);
  fclose(fp);
  return EXIT_SUCCESS;
}
