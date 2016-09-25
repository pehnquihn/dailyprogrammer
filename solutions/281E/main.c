
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int max(const char arg[]) {
	char word[1000];
	strcpy(word, arg);
	int max = -1;
	for (int i = 0; word[i] != '\0'; i++) {
		if (isalpha(word[i])) 
			word[i] += 10 - 'a';
		else
			word[i] -= '0';
		if (word[i] > max)
			max = word[i];
	}
	return max + 1;
}

int main (int argc, char *argv[]) {
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Could not open input file!\n");
		exit(1);
	}
	char line[1000];
	while (fscanf(fp, "%s", line) == 1) {
		int line_max = max(line);
		printf("base %d => %d\n", line_max, strtol(line, NULL, line_max));
	}
	fclose(fp);
	return 0;
}

