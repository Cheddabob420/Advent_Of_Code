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
  int total_chars = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    for (int i = 0; line[i] != '\0'; i++) {
      c = line[i];
      total_chars++;
      if (c == '\n') {
        continue;
      }
      if (c == '(') {
        floor++;
      }
      if (c == ')') {
        floor--;
      }
    }
  }
  printf("Last Floor:\t%d\nTotal Floors\t%d\n", floor, total_chars);

  fclose(file);
  return 0;
}
