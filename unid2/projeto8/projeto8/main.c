#include <stdio.h>
#include <stdlib.h>

//procedure
// parametros com valor e com referencia
//argumento(tipo nome , tipo nome )


int main(){
    imprimir(5);
  //int resultado = soma(50,1);
 // printf("soma: %d \n " , resultado);
  // printf("soma: %d \n " , soma(50,1));
    printf("soma com referencia: %d \n " , somaRef(50,1));
    return 0;
}

void imprimir(int a ){
    int qtd = 0;
    for(qtd = 0;qtd < a; qtd ++){
        printf(" oi na posicao %d \n " , qtd);
    }
}

//funcao

int soma(int a , int b){

    return (a+b);
}

//recebe um ponteiro - o end da variavel

int somaRef(int *a , int b){

    return *a+b;
}
