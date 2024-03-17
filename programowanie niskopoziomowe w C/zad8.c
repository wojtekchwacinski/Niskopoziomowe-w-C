#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int max(int a,int b){
    if (a>=b){
        return a;
    }
    else
        return b;

}
int min(int a ,int b){
    if (a<=b){
        return a;
    }
    else
        return b;
}
main() {
   float u;

   FILE *fp;
   int count = 0,a,b,g,k;
   float arr[100];
   float arr1[100];
   printf("podaj ilosæ elementów w pierwszym i w drugim wierszu:\n");
   scanf("%d%d",&a,&b);
   fp = fopen("plik_zad_8.txt", "r");

   for (int i = 0; i < a; i++){
        fscanf(fp,"%f ",&arr[i]);
   }
   for (int i = 0; i < b; i++){
        fscanf(fp,"%f ",&arr1[i]);
   }

   for (int i = 0; i < a; i++){
        printf("%.1f ",arr[i]);
   }
   printf("\n");
   for (int i = 0; i < b; i++){
        printf("%.1f ",arr1[i]);
   }

   fclose(fp);
   printf("\nSuma :");
   g = max(a,b);
   k = min(a,b);
   for (int i = 0; i < k; i++){
    printf(" %.1f ",arr[i]+arr1[i]);

   }
   if(a>b){
    for(int i = 0;i < (a-b);i++){
        printf(" %.1f ",arr[b+i]);
    }
   }
   else if(a<b){
    for(int i = 0;i < (b-a);i++){
        printf(" %.1f ",arr[a+i]);
    }
   }
   printf("\nŒrednia :");
   for (int i = 0; i < k; i++){
    u = (arr[i]+arr1[i])/2;
    printf(" %.1f ",u);

   }
   if(a>b){
    for(int i = 0;i < (a-b);i++){
        printf(" %.1f ",arr[b+i]);
    }
   }
   else if(a<b){
    for(int i = 0;i < (b-a);i++){
        printf(" %.1f ",arr[a+i]);
    }
   }





}


