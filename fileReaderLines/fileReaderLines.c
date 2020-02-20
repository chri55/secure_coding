#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINES 5
#define MAX_LINE_LENGTH 256

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Please input a valid file name with at least one line of text\n");
    return(1);
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("File no found or cannot be opened\n");
    return(1);
  }

  char allLines[MAX_LINES][MAX_LINE_LENGTH] ;
  char* curLine = malloc(MAX_LINE_LENGTH);
  char cur;

  int i = 0;
  while (!feof(file)) {
    fgets(curLine, MAX_LINE_LENGTH, file);
    strncpy(allLines[i], curLine, strlen(curLine));
    i++;
  }
  printf("%s", allLines[0]);

    return(0);
}
