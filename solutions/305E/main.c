
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
	// Calculate how many zeros will be needed to be added
	// as padding
	int padding = i;
	if (index != 0)
		padding = i - (int)(log(index) / log(2)) - 1;
	// Add the necessary padding zeros
	for (int j = 0; j < padding; j++)
		*(result++) = '0';
	// Begin filling in the binary representation of index.
	// In the below while loop, this is done backwards.
	while (index) {
		*(--result + i - padding) = '0' + (index & 1);
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
	if (argc == 2) {
		char *result = malloc(sizeof(char) * MAX_BUFFER);
		find_value(result, atoi(argv[1]));
		printf("%s\n", result);
		free(result);
	}
	else if (argc == 3) {
		printf("%d\n", find_index(argv[2]));
	} else {
		printf("Must enter either 1 or two arguments!\n");
	}
	return 0;
}

