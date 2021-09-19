#include <stdio.h>
#include <stdlib.h>

/*
Com base nisso, suponha que � necess�rio armazenar informa��es relacionadas � ve�culos, totalizando, no m�ximo, 10 ve�culos.
Para cada ve�culo, dever�o ser fornecidos os seguintes dados:


        - marca do ve�culo

        - modelo - ano de fabrica��o

        - placa (formato XXX-YYYY; onde X denota as letras e Y denota os n�meros da placa).

O sistema dever� oferecer, ao usu�rio, as seguintes funcionalidades:

            - Listar os veiculos cadastrados;

            - Inserir um novo veiculo;

            - Listar os veiculos filtrando-se por ano de fabricacao;

            - Listar os veiculos com o ano de fabricacao��o acima de um certo valor especificado pelo usuario ?????????????????????

            . - Listar os ve�culos filtrando-se pelo modelo.

O sistema dever� armazenar os ve�culos ordenados pelo ano de fabrica��o, ou seja, ao inserir um novo ve�culo, este deve ser inserido em ordem crescente de ano de fabrica��o.

Refer�ncia DEITEL, P. J.; DEITEL, H. C: Como Programar. 6. ed. S�o Paulo: Pearson Prentice Hall, 2011. [Recurso eletr�nico, Biblioteca Virtual Universit�ri
*/


  typedef struct car{
        char brand[10];
        char model[10];
        char plate[7];
       int year;

 } TP_CAR;


           // - Listar os veiculos cadastrados; - //

int main(){


    TP_CAR car[10] = {};
    int choices = 0;

    while(choices != 0 ){



    switch(choices){


    case 1:
        for (int i = 0; i < 10 ; i++){
         printf("Marca: %s \n Modelo: %s \n Ano: %d \n Placa: %s \n \n " , car[i].brand , car[i].model , car[i].plate , car[i].year);
        }
        choices = 6;
        break;


    default:
        printf("\n 1 - Veiculos ");
         printf("\n 2 - cadastre Veiculos ");
          printf("\n 3 - Veiculos por ano");
           printf("\n 4 - Veiculos a partir do ano:");
            printf("\n 5 - Veiculos por modelo ");
             printf("\n 0 - Sair ");
              printf("\n escolha uma opção numerica ");
              scanf("%d " , &choices);
              break;
        }
    }
}






