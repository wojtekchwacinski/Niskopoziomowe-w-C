#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZ 128
#define RSIZ 10

int main(void)
{
    char line[RSIZ][LSIZ];
	char fname[20];
    FILE *fptr = NULL;
    int i = 0,q,n,h;
    int tot = 0;
    printf("\n\n Read the file and store the lines into an array :\n");
	printf("------------------------------------------------------\n");
	printf(" Input the filename to be opened : ");
	scanf("%s",fname);

    fptr = fopen(fname, "r");
    while(fgets(line[i], LSIZ, fptr))
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file %s  are : \n",fname);
    q = sizeof(line[0])/sizeof(int);
    h = sizeof(line[1])/sizeof(int);
    printf("%d\n%d\n",q,h);
    printf("%s\n%s\n",line[0],line[1]);

    for(i = 0; i < tot; ++i)
    {

        printf(" %s\n", line[i]);
    }
    printf("\n");
    return 0;
}
