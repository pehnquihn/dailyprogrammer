
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// Ensure a swipe string was included in the args
	if (argc != 2) {
		printf("Args wrong\n");
		exit(1);
	}
	// Open the dictionary file
	FILE *fp = fopen("dict.txt", "r");
	// If the dictionary file could not be openned
	if (fp == NULL) {
		// Print an error out and exit
		printf("Could not open dict.txt file!\n");
		exit(1);
	}
	// While the end of the file has not been reached
	while (!feof(fp)) {
		// Scan in the next word in the dictionary file
		char word[1000];
		fscanf(fp, "%s", word);
		// Get the length of the scanned in word
		int len_word = strlen(word);
		// Continue to the next word if the word is less than 5 characters
		if (len_word < 5)
			continue;
		// Get the length of the swipe word
		int len_arg = strlen(argv[1]);
		// Copy the dictionary word for printing purposes
		char orig_word[1000];
		strcpy(orig_word, word);
		// Ensure that the first and last character are equal to the dictionary word
		int start = word[0] == argv[1][0];
		int end = word[len_word - 1] == argv[1][len_arg - 1];
		// If the first and last character are equal to the dictionary word
		if (start && end) {
			// Begin iterating over both the dictionary and swipe word
			for (int i = 1, j = 1; i < len_word - 1 && j < len_arg - 1; j++) {
				// While the current dictionary and swipe character are not equal
				// and the swipe index has not been moved out of bounds
				while (word[i] != argv[1][j] && j < len_arg - 1)
					// Increment the swipe character index
					j++;
				// While the swipe and dictionary word characters are equal
				// and the dictionary word index has not been moved out of bounds
				while (word[i] == argv[1][j] && i < len_word - 1)
					// Set the current word character to null and increment the index
					word[i++] = '\0';
			}
			// Begin testing if the dictionary word "fits" in the swipe word
			int match = 1;
			// Test if there is a remaining character in the dictionary word
			for (int i = 1; i < len_word - 1; i++)
				// If there is a remaining character in the dictionary word
				if (word[i] != '\0')
					// The dictionary word does not "fit" in the swipe word
					match = 0;
			// If the dictionary word first in the swipe word
			if (match)
				// Print the dictionary word
				printf("%s\n", orig_word);
		}
	}
}

