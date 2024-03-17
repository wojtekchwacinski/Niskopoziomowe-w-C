#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define ROWS 50
#define COLS 50
void przeksztalcenie(double macierz[ROWS][COLS], int R,int C){
    double macierz2[R][C],k;
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
        {
            if (macierz[i][j] + 1 != 0){
                k = (pow(sin(macierz[i][j]*PI/180),2) - 3);
                printf("yes sir");
                printf("e ",k);
                macierz2[i][j] = k;
            }
            else
                macierz2[i][j] = 3.31;
        }
    }
    printf("\n");
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%e ",macierz2[i][j]);
        }
        printf("\n");
    }

}
int main(void){
    double macierz[ROWS][COLS];
    int R,C;
    printf("podaj iloœæ wierszy i kolumn :\n");
    scanf("%d%d", &R,&C);
    if (R > ROWS){
        R = 50;
    }
    if (C > 50){
        C = 50;
    }
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
        {
            printf("macierz[%d][%d]=",i,j);
            scanf("%e", &macierz[i][j]);
        }
    }
    printf("\n");
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%e ",macierz[i][j]);
        }
        printf("\n");
    }
    przeksztalcenie(macierz,R,C);


}
