#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <strings.h>

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



    //permite usar acentos - não funcionou!
//  void locale(){  setlocale(LC_ALL,"");
//    printf("olá");
//  }

typedef struct car
{
    char brand[10];
    char model[10];
    char plate[7];
    int year;
} TP_CAR;


    //**********funçoes**************//

void organizeVehicles(int ind, TP_CAR carros[])
{

    TP_CAR aux;
    int i;
    int j;
    for ( i = 0; i < ind + 1; i++)
    {
        for ( j = i + 1; j < ind + 1; j++)
        {
            if (carros[i].year > carros[j].year)
            {
                aux = carros[i];
                carros[i] = carros[j];
                carros[j] = aux;
            }
        }
    }
}

/*
 * Inserção ordenada!
 */
int insertVehicle(TP_CAR cars[], int carsSize, TP_CAR car)
{
   int i;
    // Encontra a posição para inserir
    int pos = 0;
    while (pos < carsSize && cars[pos].year < car.year) {
        pos++;
    }

    // movo todos que devem ficar depois para a direita
    for ( i = carsSize; i > pos; i--) {
        cars[i] = cars[i-1];
    }

    cars[pos] = car;

    return carsSize + 1;
}

  //[ 2 ] -------adiciona veiculos
int addVehicle(TP_CAR cars[], int carsSize)
{
    if (carsSize >= 10) {
        printf("\n número máximo atingido!");
        return carsSize;
    }

    TP_CAR car;

    printf("\n Digite a marca:");
    scanf("%s", car.brand);

    printf("\n digite o modelo:");
    scanf("%s", car.model);

    printf("\n digite a placa:");
    scanf("%s", car.plate);

    printf("\n digite o ano:");
    scanf("%d", &car.year);

    return insertVehicle(cars, carsSize, car);

    getChoice(); // volta pro menu
}


  //[ 1 ] -------lista veiculos
void printVehicle(TP_CAR car){


    printf("Veiculo: %s \n Modelo: %s \n Placa: %s \n Ano: %d \n\n  ", car.brand, car.model, car.plate, car.year);

       //    getChoice(); // volta pro menu
}



void showVehicles(TP_CAR cars[], int* carsSize){


       int i;
    for ( i = 0; i < *carsSize; i++) {
        printVehicle(cars[i]);
    }

  //  getChoice(); // volta pro menu
}

int findIndexYear(TP_CAR cars[], int carsSize, int year, int diffIndex) {



       int i;

        if (carsSize == 0)	{
		printf("\n nao temos veiculos \n");
	}


    if (carsSize > 0 && carsSize <= 2) {
        for ( i = 0; i < carsSize; i++) {
            if (cars[i].year == year) {
                return i;
            }
        }
        return diffIndex; // nesse caso não retorna o index daquele ano mas será útil para o caso de "a partir de"
    }
    int pivo = carsSize / 2;
    if (cars[pivo].year == year) {
        // encontra a primeira incidência de carro daquele ano
        while (cars[pivo-1].year == year) {
            pivo--;
        }
        // diffIndex é a diferença entre o primeiro elemento da região que estou buscando pro primeiro elemento geral
        return pivo + diffIndex;
    } else if (cars[pivo].year < year) {
        // procuro na segunda metade
        return findIndexYear(cars + (carsSize/2), carsSize/2, year, diffIndex + (carsSize/2));
    }

    else {
        // procuro na primeira metade
        return findIndexYear(cars, carsSize/2, year, diffIndex);
    }
 // getChoice(); // volta pro menu
}





    //[ 3 ] -------mostra os veiculos do ano escolhido

void showVehiclesByYear(TP_CAR cars[], int carsSize) {
    //int printouAlgo = 0;

    int year;
    printf("Escolha um ano ");
    scanf("%d", &year);
    printf("%d\n", year);

       if (carsSize == 0) {
            printf("Nao ha veiculos deste ano \n");

    }

    int index = findIndexYear(cars, carsSize, year, 0);
    while (index < carsSize && cars[index].year == year) {
        printVehicle(cars[index]);
        index++;
    }

getChoice(); // volta pro menu
}




     //[ 4 ] ------- mostra a partir do ano escolhido
void showVehiclesFromYear(TP_CAR cars[], int carsSize) {
    int year;
       int i;


    printf("Escolha um ano ");
    scanf("%d", &year);
    printf("%d\n", year);


     if (carsSize == 0)	{
		printf("\n nao temos veiculos \n");
	}


    int index = findIndexYear(cars, carsSize, year, 0);

    for ( i = index; i < carsSize; i++) {
        if (cars[i].year >= year){
              printVehicle(cars[i]);
        }


    }


    getChoice(); // volta pro menu
}






     //[ 5 ] ------- mostra por modelo
void showVehiclesByModel(TP_CAR cars[], int carsSize) {

    char searchModel[20];
    int i = 0;
    int count = 0;

    printf("escolha um modelo:");
    scanf("%s", &searchModel);
    printf("Procurando por modelo: \"%s\" \n\n", searchModel);

    for( i = 0 ; i < carsSize ; i++){
       if(!strcmp(cars[i].model , searchModel)){

      printf("Veiculo: %s \n Modelo: %s \n Placa: %s \n Ano: %d \n\n  " , cars[i].brand , cars[i].model , cars[i].plate ,cars[i].year);
        count++;
       }
    }
     if (count == 0)    {
       printf("\n nao temos este modelo\n");
    }
    else    {
        count = 0;
    }

}




//void pesquisarModelo(cadastroV cadastro[], int cod) {
//    char modelo[20];
//    int i = 0;
//    printf("Digite o modelo\n");
//    scanf("%s", &modelo);
//    printf("\n\tLISTA DE VEICULOS\n");
//    printf("---------------------------------");

//    for (int i = 0; i < cod; i++)
//    {
//        if (strcmp(cadastro[i].modelo, strlwr(modelo)) == 0)
//        {
//            printf("\n A marca do veículo é: %s", cadastro[i].marca);
//            printf("\n O modelo do veículo é: %s", cadastro[i].modelo);
//            printf("\n O ano do veículo é: %d", cadastro[i].ano);
//            printf("\n A placa do veículo é: %s", cadastro[i].placa);
//            printf("\n---------------------------------");
//            count++;
//        }
//    }
//    if (count == 0)
//    {
//        printf("\n\tMODELO NÃO ENCONTRADO\n");
//    }
//    else
//    {
//        count = 0;
//    }
//}

    //***********menu*********//
int getChoice(){
    int choice;
    printf("\n 1 - Listar veiculos");
    printf("\n 2 - Cadastra veiculo");
    printf("\n 3 - Listar veiculos por ano");
    printf("\n 4 - Listar veiculos a partir de ano");
    printf("\n 5 - Listar veiculos por modelo");
    printf("\n 0 - Sair ");
    printf("\n escolha uma opcao numerica ");
    scanf("%d", &choice);
    return choice;
}

int main(){


    TP_CAR cars[10] = {};
    int carsSize = 0;
    int choice = getChoice();
    char searchModel[20];

    while (choice != 0)
    {
        printf("%d\n", carsSize);
        switch (choice) {

            //lista veiculos cadastrados
            case 1:
                showVehicles(cars, &carsSize);
                break;
            // cadastra veiculo
            case 2:
                carsSize = addVehicle(cars, carsSize);
                break;

            //lista veiculos por ano
            case 3:
                showVehiclesByYear(cars, carsSize);
                break;

            //lista veiculos a partir do ano
            case 4:
                showVehiclesFromYear(cars, carsSize);
                break;
            //lista veiculos por modelo
            case 5:
                showVehiclesByModel(cars, carsSize);
                break;


        }

        choice = getChoice();
    }

}
