#include <stdio.h>
const int MAX = 50;

struct Komputery{
char NazwaTowaru[32];
int LiczbaSztuk;
int Cena1Sztuki;
};
void wyswietl(int ile,struct Komputery TabKom[MAX]){
    for(int i = 0; i < ile; ++i){
        printf("%d. Komputer : %s, LiczbaSztuk : %d, Cena1Sztuki : %d\n",i, TabKom[i].NazwaTowaru, TabKom[i].LiczbaSztuk, TabKom[i].Cena1Sztuki);
        }
}
void wartosc(int ile,struct Komputery TabKom[MAX]){
    int ktory = 0;
    for (int i = 0; i < ile; ++i){
        ktory += TabKom[i].LiczbaSztuk * TabKom[i].Cena1Sztuki;
    }
    printf("Wartosc razem : %d\n", ktory);
}



int main(){
    struct Komputery TabKom[MAX];
    int ile = 0,k = 1;
    char opcja;
    while(k){
        printf("Wybierz opcje [N, W, R, Q] : ");
        fflush(stdin);
        scanf("%c", &opcja);
        switch(opcja & 0x5F){
            case 'N':
                if (ile < MAX){
                    printf("Podaj nazwe : ");
                    scanf("%31s", TabKom[ile].NazwaTowaru);
                    printf("Podaj cene : ");
                    scanf("%d", &TabKom[ile].LiczbaSztuk);
                    printf("Podaj liczbe sztuk : ");
                    scanf("%d", &TabKom[ile++].Cena1Sztuki);
                    }
                else
                    printf("Tablica pelna.\n");


                break;
            case 'W':
                wyswietl(ile,TabKom);
                break;
            case 'R':
                wartosc(ile,TabKom);
                break;
            case 'Q':k=k-1;
                break;

}
}
return 0;
}
