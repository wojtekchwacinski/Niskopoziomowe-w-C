
#include <stdio.h>

int suma(int n){
    if (n == 0)
       return 0;
    return (n % 10 + suma(n / 10));
}
int main(){
    int liczba,wynik;
    scanf("%d", &liczba);
    wynik = suma(liczba);
    printf("suma cyferek %d to %d\n", liczba, wynik);

}
