// struct from a file
#include <stdio.h>
#include <stdlib.h>

// struct person with 3 fields
struct person
{
    int id;
    double wynik;
    int kod;
};

// Driver program
int main ()
{
    FILE *infile;
    struct person input;

    // Open person.dat for reading
    infile = fopen ("wyniczek.txt", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    // read file contents till end of file
    while(fread(&input, sizeof(struct person), 1, infile))
        printf ("id = %d name = %lf %d\n", input.id,
        input.wynik, input.kod);

    // close file
    fclose (infile);

    return 0;
}
