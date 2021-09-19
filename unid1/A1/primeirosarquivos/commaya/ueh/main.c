#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct car
{
    char brand[10];
    char model[10];
    char plate[7];
    int year;
} TP_CAR;

void Menu()
{

    printf("\n 1 - Listar veículos.");
    printf("\n 2 - Cadastrar veículo.");
    printf("\n 3 - Listar veículo por ano:");
    printf("\n 4 - Listar veículo a partir do ano:");
    printf("\n 5 - Listar veículo por modelo:");
    printf("\n 0 - Sair.");
    printf("\n Escolha as opções numericas: ");
}


void organizeVehicles(int ind, TP_CAR carros[])
{

    TP_CAR aux;

    for (int i = 0; i < ind + 1; i++)
    {
        for (int j = i + 1; j < ind + 1; j++)
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
    // Encontra a posição para inserir
    int pos = 0;
    while (pos < carsSize && cars[pos].year < car.year) {
        pos++;
    }

    // movo todos que devem ficar depois para a direita
    for (int i = carsSize; i > pos; i--) {
        cars[i] = cars[i-1];
    }

    cars[pos] = car;

    return carsSize + 1;
}

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
}


void printVehicle(TP_CAR car)
{
    printf("Veiculo: %s \n Modelo: %s \n Placa: %s \n Ano: %d \n\n  ", car.brand, car.model, car.plate, car.year);
}

void showVehicles(TP_CAR cars[], int* carsSize)
{
    for (int i = 0; i < *carsSize; i++) {
        printVehicle(cars[i]);
    }
}

int findIndexYear(TP_CAR cars[], int carsSize, int year, int diffIndex) {
    if (carsSize > 0 && carsSize <= 2) {
        for (int i = 0; i < carsSize; i++) {
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
    } else {
        // procuro na primeira metade
        return findIndexYear(cars, carsSize/2, year, diffIndex);
    }

}

void showVehiclesByYear(TP_CAR cars[], int carsSize) {
    int year;
    printf("Escolha um ano ");
    scanf("%d", &year);
    printf("%d\n", year);

    int index = findIndexYear(cars, carsSize, year, 0);
    while (index < carsSize && cars[index].year == year) {
        printVehicle(cars[index]);
        index++;
    }
}

void showVehiclesFromYear(TP_CAR cars[], int carsSize) {
    int year;
    printf("Escolha um ano ");
    scanf("%d", &year);
    printf("%d\n", year);

    int index = findIndexYear(cars, carsSize, year, 0);
    for (int i = index; i < carsSize; i++) {
        if (cars[i].year >= year)
            printVehicle(cars[i]);
    }
}
void showVehiclesByModel(TP_CAR cars[], int carsSize) {
    for (int i = 0; i<10; i++)
    {
        if (strcmp(modeloBusca, car[i].modelo ) == 0)
        {
           printf("Veiculo: %s \n Modelo: %s \n Placa: %s \n Ano: %d \n\n  ", car.brand, car.model, car.plate, car.year);
        }
    }
}


int getChoice()
{
    int choice;
    printf("\n 1 - Listar veiculos");
    printf("\n 2 - Cadastra veiculo");
    printf("\n 3 - Listar veiculos por ano");
    printf("\n 4 - Listar veiculos a partir de ano");
    printf("\n 5 - Listar veiculos por modelo");
    printf("\n 0 - Sair ");
    printf("\n escolha uma opção numerica ");
    scanf("%d", &choice);
    return choice;
}

int main()
{

    TP_CAR cars[10] = {};
    int carsSize = 0;
    int choice = getChoice();

    while (choice != 0)
    {
        printf("%d\n", carsSize);
        switch (choice)
        {

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

            case 5:
                showVehiclesByModel(cars, carsSize);
                break;
        }

        choice = getChoice();
    }
}
