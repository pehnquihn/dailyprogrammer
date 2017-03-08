
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_BUFFER 100

/*
 * find_value
 * Calculates corresponding "permutation base 2" value of a given
 * index
 * 
 * result: Where the resulting "permutation base 2" will be stored
 * index: The index of the "permutation base 2" to be calculated
 */
void find_value (char *result, int index) {
	// Find required length of the value, this length will
	// be stored in i. The resulting value of index will
	// now be the needed binary representation of value.
	int i;
	for (i = 1; index >= pow(2, i); i++)
		index -= pow(2, i);
	// Write the correct binary representation of index,
	// doing so backwards. This will also add all needed
	// padding zeros.
	for (int j = i - 1; j >= 0; j--) {
		result[j] = '0' + (index & 1);
		index >>= 1;
	}
}

/*
 * find_index
 * Calculates the corresponding "permutation base 2" index of a given
 * value
 *
 * value: The value of the "permutation base 2" to be calculated
 * 
 * returns: The "permutation base 2" index of the given value
 */
int find_index (char *value) {
	// Find the length of the value
	int len = strlen(value);
	// Find the binary representation stored in the value
	int bin_val = strtol(value, NULL, 2);
	// 2^len + bin_val - 2 will give the resulting index
	return pow(2, len) + bin_val - 2;
}

int main (int argc, char **argv) {
	// Convert a given index to a value
	if (argc == 2) {
		char *result = malloc(sizeof(char) * MAX_BUFFER);
		find_value(result, atoi(argv[1]));
		printf("%s\n", result);
		free(result);
	}
	// Convert a given value to an index
	else if (argc == 3)
		printf("%d\n", find_index(argv[2]));
	// Prompt the user the program was used incorrectly
	else
		printf("Must enter either 1 or two arguments!\n");
	return 0;
}

