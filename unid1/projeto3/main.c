
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main(void) {

 //aceitar acentuacao no prompt
setlocale(LC_ALL, "Portuguese");

char str[] = "oiii" ;

printf("\n valor atual: %s" ,str);

printf("\n maiuscula: %s" ,strupr(str));
printf("\n minuscula: %s" ,strlwr(str));

printf("\n tamanho: %i" ,strlen(str));

printf("\n substituir valores: %s" ,strcpy(str, "teste 2"));

printf("\n comparar: %i \n 0 para iguais e 1 para outros" ,strcmp("teste 2" , str));
printf("\n substituir valores colocando qt posicao p/ substituir: %s" ,strncpy(str , "camis",2));


//ATRIBUINDO NOVO VALOR
strcpy(str, "camis");
printf("\n concatenar: %s", strcat(str,"  monteiro"));

return 0;
}
