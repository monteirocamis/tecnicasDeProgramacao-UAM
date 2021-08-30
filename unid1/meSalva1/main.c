// calcula e soma  2 valores
#include <stdio.h>
#include <stdlib.h>

int main()
{

     /* exemplo1 IF ELSE
    int val1, val2, soma;
    printf("digite o primeiro valor \n");
    scanf("%d",&val1);

      printf("digite o segundo valor \n");
        scanf("%d",&val2);





          if(val1 <0 || val2<0){
            printf("\n erro: numero negativo");
           }
           else{
            soma = val1 + val2;
           printf("resultado da soma: %d",soma);
           }
*/

// exemplo2 WHILE

//inicializar as variaveis
/*
int val1 = -1;
int val2 = -1;
int soma;


//antes do uso
while( val1 <=0 || val2 <= 0){

    printf("digite o primeiro valor \n");
    scanf("%d",&val1);

      printf("digite o segundo valor \n");
        scanf("%d",&val2);
}
 soma = val1 + val2;
           printf("resultado da soma: %d",soma);

*/

           // exemplo3 DO WHILE
           int val1 ;
int val2;
int soma;

do{
    printf("digite o primeiro valor \n");
    scanf("%d",&val1);

      printf("digite o segundo valor \n");
        scanf("%d",&val2);
}
while( val1 <=0 || val2 <= 0);

    soma = val1 + val2;
           printf("resultado da soma: %d",soma);


        return 0;
}




































