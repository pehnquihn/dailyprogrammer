
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Helper function for sorting chars with qsort
int charcmp(const void *a, const void *b) {
	return *(const char *)a - *(const char *)b;
}

// Lowers, sorts, and removes whitespace in a string
void strformat(char *str) {
	// Lower all chars in the string
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
	// Sort the string
	qsort(str, strlen(str), sizeof(char), charcmp);
	// Remove the leading whitespace of the string
	char *begin = str;
	while (isspace(*begin)) begin++;
	memcpy(str, begin, strlen(begin) + 1);
}

int main(int argc, char *argv[]) {
	// Ensure the correct args are used
	if (argc != 3) {
		printf("Args incorrect!\n");
		exit(1);
	}
	// Copy the arguments for printing purposes
	char s1[strlen(argv[1]) + 1];
	char s2[strlen(argv[2]) + 1];
	strcpy(s1, argv[1]);
	strcpy(s2, argv[2]);
	// Format the argument strings
	strformat(argv[1]);
	strformat(argv[2]);
	// If the strings are the same, they are anagrams
	if (strcmp(argv[1], argv[2]) == 0)
		printf("\"%s\" is an anagram of \"%s\"\n", s1, s2);
	else
		printf("\"%s\" is NOT an anagram of \"%s\"\n", s1, s2);
	return 0;
}

