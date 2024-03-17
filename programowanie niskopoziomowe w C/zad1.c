#include <stdio.h>

int main(void)
{
    char plik[100];

    FILE *file = fopen("inputfile.txt", "r");

    if (file == NULL)
    {
        fputs("nie uda³o sie\n", stderr);
        return -1;
    }
    while (fgets(plik, sizeof(plik), file) != NULL)
    {
        printf("wczytane = %s\n", plik);
    }

    fclose(file);
    char ch;
  	int i, Count;
  	Count = 0;

  	printf("\n podaæ znak :  ");
  	scanf("%c", &ch);

  	for(i = 0; i <= strlen(plik); i++)
  	{
  		if(plik[i] == ch)
		{
  			Count++;
 		}
	}
	printf("\n taki znak'%c' pojawi³ sie tyle razy  %d ", ch, Count);

  	return 0;
}

