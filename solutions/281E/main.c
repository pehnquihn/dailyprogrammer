
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Finds max possible base a number can be
int max(const char arg[]) {
	// Create a modifyable parameter
	char word[1000];
	strcpy(word, arg);
	int max = -1;
	// For each digit in the number
	for (int i = 0; word[i] != '\0'; i++) {
		// If the digit is a or higher
		if (isalpha(word[i])) 
			// Convert it to the appropriate integer number
			word[i] += 10 - 'a';
		// If the digit is a decimal number or lower
		else
			// Convert it to the appropriate integer number
			word[i] -= '0';
		// Set the max digit value if this digit is the highest one seen thus far
		if (word[i] > max)
			max = word[i];
	}
	// Return the max digit + 1
	return max + 1;
}

int main (int argc, char *argv[]) {
	// Open the input file
	FILE *fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Could not open input file!\n");
		exit(1);
	}
	// Scan through the input file line by line
	char line[1000];
	while (fscanf(fp, "%s", line) == 1) {
		// Get the base of the number
		int line_max = max(line);
		// Print the output for the number
		printf("base %d => %d\n", line_max, strtol(line, NULL, line_max));
	}
	fclose(fp);
	return 0;
}

