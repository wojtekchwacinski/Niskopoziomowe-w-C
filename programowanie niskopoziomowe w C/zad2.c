#include <stdio.h>
#include <math.h>
#define PI  3.14
#define ROWS 50
#define COLS 50
void przeksztalcenie(double macierz[ROWS][COLS], int R,int C){
    double macierz2[R][C];
    double k,g,l;

    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
        {
           if (macierz[i][j]+1==0){
            macierz2[i][j] = 3.31;
           }
           else
            macierz2[i][j] = (pow(sin(macierz[i][j]),2)-3)/sqrt(macierz[i][j]+1);

            }
            }

    printf("\n");
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%lf ",macierz2[i][j]);
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
            scanf("%lf", &macierz[i][j]);
        }
    }
    printf("\n");
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%lf ",macierz[i][j]);
        }
        printf("\n");
    }
    przeksztalcenie(macierz,R,C);


}
