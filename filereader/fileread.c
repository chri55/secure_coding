#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Please input a valid file name with at least one line of text\n");
    return(1);
  }
  char cur;
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("File no found or cannot be opened\n");
    return(1);
  }
  while (1){
    cur = fgetc(file);
    if (!feof(file)) {
      printf("%c", cur);
    }
    else {
      break;
    } 
  }
    return(0);
}
