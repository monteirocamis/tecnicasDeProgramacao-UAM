#include <stdio.h>
#include <stdlib.h>



int main()
{
   imprimir(); // chama a funcao  imprimir pra rodar
   printf("\n valor: %d" , soma(4)); // pula linha, poe a string e mostra no %d o valor em decimal da funcao soma com o argumento 5
    return 0;
}



//tipagens: int, float, char , booleam ...


//tipagem nome argumento
void imprimir(){ // funcao que so imprime o oi
//inicio do bloco
printf("\n oi");

//fim do bloco
}


int soma(int a){


return a + 1;  // recebe o valor do argumento a- que nesse caso vem com 4.. faz a soma eretorna o resultado
}
