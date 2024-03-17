#include <stdio.h>
#include <math.h>

#define ROWS 15
#define COLS 15

void rowna(int A[ROWS][COLS],int B[ROWS][COLS],int R,int C){
    int RO[R][C];
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
            {
            if (A[i][j] == B[i][j]){
                RO[i][j] = 1;
            }
            else
                RO[i][j] = 0;
            }
        }
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%d ",RO[i][j]);
        }
        printf("\n");
    }
}

void przewaga(int A[ROWS][COLS],int B[ROWS][COLS],int R,int C){
    int PRZ[R][C];
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
            {
            if (A[i][j] > B[i][j]){
                PRZ[i][j] = 1;
            }
            else
                PRZ[i][j] = 0;
            }
        }
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%d ",PRZ[i][j]);
        }
        printf("\n");
    }




}


int main(void){
    int A[ROWS][COLS],R,C;
    int B[ROWS][COLS];
    printf("podaj iloœæ wierszy i kolumn :\n");
    scanf("%d%d", &R,&C);
    if (R > ROWS){
        R = 15;
    }
    if (C > COLS){
        C = 15;
    }
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
        {
            printf("macierz[%d][%d]=",i,j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
        {
            printf("macierz[%d][%d]=",i,j);
            scanf("%d", &B[i][j]);
        }
    }
    printf("\n");
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    for (int  i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    przewaga(A,B,R,C);
    rowna(A,B,R,C);


}
