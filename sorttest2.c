#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest2 some_number another_number ...
 * Example:
 *         ./sorttest2 2014 15 7000
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {
	srand(0);
	int *nums; // space to store numbers entered from the command line.

	int i; //array loop variable declaration
	int num_nums; // How many numbers actually entered on the command line.
	char* func; //the sorting function to use

	if(argc < 3) {
		printf("Must indicate an array size and which sort function to use!\n");
		printf("The possible options are: sort, sort2, sort3. Exiting Program!\n");
		return 1;
	}
	else {
		num_nums = atoi(argv[1]);
		func = argv[2];
	}
	// Allocate an array big enough to hold the numbers
	nums = (int*) calloc(num_nums, sizeof(int));
	if (nums == NULL) {
		fprintf(stderr, "Unable to allocate enough memory to hold the numbers.\n");
	}

	/* Read all the numbers from the command line and put them into the array */
	for (i = 0; i < num_nums; i++) {
		nums[i] = rand();
	}

	// Now print, sort, and print the array, and time how long the sorting took.
	timesort(nums, num_nums, func);

	return 0; // Indicate success!
}
