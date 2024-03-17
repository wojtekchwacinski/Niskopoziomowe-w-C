// C program for writing
// struct to file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct to read and write
struct person
{
	int numer;
    double pomiar1;
    double pomiar2;
    double pomiar3;
    double pomiar4;
    int kod;
};

int main ()
{
	FILE *outfile;

	// open file for writing
	outfile = fopen ("pomiar.txt", "w");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit (1);
	}

	struct person input1 = {1, 23.1, 341.3, 123, 12, 0};
	struct person input2 = {2, 2313, 44, 1.9, 54, 1};
	struct person input3 = {3, 342, 1.2, 33, 3.4, 2};
	// write struct to file
	fwrite (&input1, sizeof(struct person), 1, outfile);
	fwrite (&input2, sizeof(struct person), 1, outfile);
	fwrite (&input3, sizeof(struct person), 1, outfile);
	if(fwrite != 0)
		printf("contents to file written successfully !\n");
	else
		printf("error writing file !\n");

	// close file
	fclose (outfile);

	return 0;
}

