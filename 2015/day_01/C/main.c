#include <stdio.h>
#include <stdlib.h>

#define PFILE "puzzle_input.txt"

int main() {
  FILE *file = fopen(PFILE, "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line[256];
  int floor = 0;
  char c = ' ';
  int count = 0;
  int flag = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    for (int i = 0; line[i] != '\0'; i++) {
      c = line[i];
      if (c == '\n') {
        continue;
      }
      if (c == '(') {
        floor++;
        count++;
      }
      if (c == ')') {
        floor--;
        count++;
      }
      if (floor < 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  printf("Position Entered the Basement: %d\n", count);

  fclose(file);
  return 0;
}
