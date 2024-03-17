#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 50

typedef struct {
    char nazwisko[20];
    char imie[20];
    int numer;
}student;


typedef struct{
    int numer;
    int ocena;
}programowanie;


typedef struct{
    int numer;
    int ocena;
}fizyka;

int read_students(const char *filename, student *stdu) {
    FILE *fin = fopen(filename, "r");
    if (!fin) {
        printf("Can't open file: %s\n", filename);
        return 0;
    }
    int i = 0;
    while (fscanf(fin, "%s %s %d\n",
            stdu[i].nazwisko,
            stdu[i].imie,
            &stdu[i].numer)==3)
        ++i;
    fclose(fin);
    return i;
}
int read_fizyka(const char *filename,fizyka *fiz){
    FILE *fin = fopen(filename,"r");
    if (!fin) {
        printf("Can't open file: %s\n", filename);
        return 0;
    }
    int i = 0;
    while (fscanf(fin, "%d %d",
            &fiz[i].numer,
            &fiz[i].ocena)==2)
        ++i;
    fclose(fin);
    return i;
}
int read_programowanie(const char *filename,programowanie *prog){
    FILE *fin = fopen(filename,"r");
    if (!fin) {
        printf("Can't open file: %s\n", filename);
        return 0;
    }
    int i = 0;
    while (fscanf(fin, "%d %d",
            &prog[i].numer,
            &prog[i].ocena)==2)
        ++i;
    fclose(fin);
    return i;
}
void print_prog(programowanie *prog, int size3){
    for (int i = 0; i < size3; ++i) {
        programowanie *m = &prog[i];
        printf("%d %d\n",
            m->numer,m->ocena);
    }
}
void print_fiz(fizyka *fiz, int size2){
    for (int i = 0; i < size2; ++i) {
        fizyka *m = &fiz[i];
        printf("%d %d\n",
            m->numer,m->ocena);
    }
}
void print_student(student *stdu, int size) {
    for (int i = 0; i < size; ++i) {
        student *m = &stdu[i];
        printf("%s %s %d\n",
            m->nazwisko,m->imie,m->numer);
    }
}
void print_napodstawienazwisko(student *stdu, int size,int size2,int size3,programowanie *prog,fizyka *fiz){
    char nazw[20];
    printf("podaj nazwisko :\n");
    scanf("%s",nazw);
    for (int i = 0; i < size; ++i) {
        student *m = &stdu[i];
        if(strcmp(m->nazwisko, nazw)==0){
            for(int j = 0; j < size2;j++){
                fizyka *h = &fiz[j];
                if (m->numer == h->numer){
                    printf("ocena z fizyki %d\n",h->ocena);
                }
            }
            for(int d = 0; d < size3;d++){
                programowanie *k = &prog[d];
                if (m->numer == k->numer){
                    printf("ocena z programowania %d\n",k->ocena);
                }
        }
}
}
}
void print_napodstawienumeru(student *stdu, int size,int size2,int size3,programowanie *prog,fizyka *fiz){
    int num;
    printf("podaj numer :\n");
    scanf("%d",&num);
    for (int i = 0; i < size; ++i) {
        student *m = &stdu[i];
        if(m->numer == num){
            for(int j = 0; j < size2;j++){
                fizyka *h = &fiz[j];
                if (m->numer == h->numer){
                    printf("ocena z fizyki %d\n",h->ocena);
                }
            }
            for(int d = 0; d < size3;d++){
                programowanie *k = &prog[d];
                if (m->numer == k->numer){
                    printf("ocena z programowania %d\n",k->ocena);
                }
        }
}
}
}
void wyjscie(int jeszcze){
    printf("jesli chcesz dalej przegl¹dac wpisz 1 :\n");
    scanf("d",&jeszcze);
    return jeszcze;

}
int main() {
    student stdu[MAX_SIZE];
    int jeszcze = 1;
    char opcja;
    fizyka fiz[MAX_SIZE];
    programowanie prog[MAX_SIZE];
    int size = read_students("studenci.txt", stdu);
    int size2 = read_fizyka("fizyka.txt",fiz);
    int size3 = read_programowanie("programowanie.txt",prog);
    print_student(stdu, size);
    print_fiz(fiz,size2);
    print_prog(prog,size3);
    while (jeszcze){
    printf("wybierz opcje : N, A, Q :\n");
    scanf("%c",&opcja);
    switch(opcja & 0x5F){
    case 'N':
        print_napodstawienazwisko(stdu,size,size2,size3,prog,fiz);
        break;
    case 'A':
        print_napodstawienumeru(stdu,size,size2,size3,prog,fiz);
        break;
    case 'Q':
        jeszcze = jeszcze -1;
        }




    }
    return 0;
}


