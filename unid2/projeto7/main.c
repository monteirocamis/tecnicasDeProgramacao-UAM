#include <stdio.h>
#include <stdlib.h>

int main()
{

    retornaValor();
    naoRetorna();
    int numero = retornaValor();
    printf("\n %d" , numero);
    return 0;
}

//procedure

void naoRetorna(){
printf("oiiiii");
}

//funcoes
int retornaValor(){
  return 5;
}
