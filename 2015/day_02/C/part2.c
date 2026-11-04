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
  int x1 = 0;
  int x2 = 0;
  int x3 = 0;
  int s1 = 0;
  int s2 = 0;
  int total = 0;
  int ribbon = 0;
  int bow = 0;
  int com_pres = 0;
  int count = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    sscanf(line, "%dx%dx%d", &x1, &x2, &x3);
    if (x1 <= x2 && x1 <= x3) {
      s1 = x1;
      if (x2 <= x3) {
        s2 = x2;
      } else {
        s2 = x3;
      }
    } else if (x2 <= x1 && x2 <= x3) {
      s1 = x2;
      if (x1 <= x3) {
        s2 = x1;
      } else {
        s2 = x3;
      }
    } else {
      s1 = x3;
      if (x1 <= x2) {
        s2 = x1;
      } else {
        s2 = x2;
      }
    }

    ribbon = (s1 * 2) + (s2 * 2);
    bow = x1 * x2 * x3;
    com_pres = ribbon + bow;
    total = total + com_pres;
    count++;
    /*printf("Present %d\nRibbon\t%d\nBow\t%d\nCompP\t%d\nTotal\t%d\n\n", count,
           ribbon, bow, com_pres, total);
    if (count >= 5) {
      break;
    }*/
  }
  printf("Total feet: %d\n", total);
  fclose(fp);
  return EXIT_SUCCESS;
}
