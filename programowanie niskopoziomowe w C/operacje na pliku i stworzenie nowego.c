#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include<float.h>
#include<limits.h>
struct pomiary{
    int numer;
    double pomiar1;
    double pomiar2;
    double pomiar3;
    double pomiar4;
    int kod;
};
struct wyniki{
    int numer;
    double wynik;
    int kod;
};

void srednia(int k,int n,double p1, double p2, double p3, double p4,FILE *outfile)
{
    double sr;

    sr = (p1+p2+p3+p4)/4;

    struct wyniki input1 = {n, sr, k};

    fwrite (&input1, sizeof(struct wyniki), 1, outfile);

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

}
void akax(int k,int n,double p1, double p2, double p3, double p4,FILE *outfile){
    double mx,mx2,mx3;

    mx = fmax(p1,p2);
    mx2 = fmax(mx,p3);
    mx3 = fmax(mx2,p4);
    // open file for writing

    struct wyniki input1 = {n, mx3, k};

    fwrite (&input1, sizeof(struct wyniki), 1, outfile);

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
}
void minumu(int k,int n,double p1, double p2, double p3, double p4,FILE *outfile){
    double mx,mx2,mx3;

    mx = fmin(p1,p2);
    mx2 = fmin(mx,p3);
    mx3 = fmin(mx2, p4);
    // open file for writing

    struct wyniki input1 = {n, mx3, k};

    fwrite (&input1, sizeof(struct wyniki), 1, outfile);

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

}
int (*fx[3])(int k,int n,double p1, double p2, double p3, double p4,FILE *outfile) = {srednia,akax,minumu};

int main(){
    FILE *infile;
    FILE *outfile;
    outfile = fopen ("wyniczek.txt", "r+");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    int n,k;
    double p1,p2,p3,p4;
    struct pomiary input;

    infile = fopen("pomiar.txt","r");
    if (infile == NULL){
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    while(fread(&input,sizeof(struct pomiary),1,infile)){
            if (input.kod == 0){
                n = input.numer;
                k = input.kod;
                p1 = input.pomiar1;
                p2 = input.pomiar2;
                p3 = input.pomiar3;
                p4 = input.pomiar4;
                fx[0](k,n,p1,p2,p3,p4,outfile);

            }
            if (input.kod == 1){
                n = input.numer;
                k = input.kod;
                p1 = input.pomiar1;
                p2 = input.pomiar2;
                p3 = input.pomiar3;
                p4 = input.pomiar4;
                fx[1](k,n,p1,p2,p3,p4,outfile);
            }
            if (input.kod == 2){
                n = input.numer;
                k = input.kod;
                p1 = input.pomiar1;
                p2 = input.pomiar2;
                p3 = input.pomiar3;
                p4 = input.pomiar4;
                fx[2](k,n,p1,p2,p3,p4,outfile);
            }
        printf("numer = %d pomiar1 = %lf pomiar2 = %lf pomiar3 = %lf pomiar4 = %lf kod = %d\n", input.numer,input.pomiar1, input.pomiar2,input.pomiar3,input.pomiar4,input.kod);
    }
    fclose(infile);
    fclose(outfile);

}
