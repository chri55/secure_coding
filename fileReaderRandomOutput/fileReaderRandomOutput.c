#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randoms(int lower, int upper);

int main(int argc, char**argv) {
	FILE *fileptr;
	int i = 0;
	int num = 0;
	char *file;
	char line[256];
	char written[256][256];
	if (argc != 2) {
		printf("ERROR:Incorrect number of arguments. Need 2 arguments. Input:%d\n", argc);
		return 1;
	}
	file = argv[1];
	if ((fileptr = fopen(file, "r")) == NULL) {
    printf("Error opening file.\n");
		return 1;
	}
	while (!feof(fileptr)) {
		fgets(line, 256, fileptr);
		strncpy(written[i], line, strlen(line));
		i++;
	}
	srand(time(NULL));
	num = randoms(0,i);

	printf("%s\n", written[num]);
	fclose(fileptr);
	file = NULL;
	return 0;
}

int randoms(int lower, int upper) {
  int num = ((rand() % (upper + 1 -lower)) + lower);
	return num;
}
