
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int charcmp(const void *a, const void *b) {
	return *(const char *)a - *(const char *)b;
}

void strformat(char *str) {
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
	qsort(str, strlen(str), sizeof(char), charcmp);
	char *begin = str;
	while (isspace(*begin)) begin++;
	memcpy(str, begin, strlen(begin) + 1);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Args incorrect!\n");
		exit(1);
	}
	char s1[strlen(argv[1]) + 1];
	char s2[strlen(argv[2]) + 1];
	strcpy(s1, argv[1]);
	strcpy(s2, argv[2]);
	strformat(argv[1]);
	strformat(argv[2]);
	if (strcmp(argv[1], argv[2]) == 0)
		printf("\"%s\" is an anagram of \"%s\"\n", s1, s2);
	else
		printf("\"%s\" is NOT an anagram of \"%s\"\n", s1, s2);
	return 0;
}

