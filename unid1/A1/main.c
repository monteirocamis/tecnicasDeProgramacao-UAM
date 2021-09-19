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



//typedef struct fabricacao{
//    int mes;
//    int ano;
//}TP_FABRICACAO;


  typedef struct car{
        char brand[10];
        char model[10];
        char plate[7];
       int year;
       //TP_FABRICACAO data_fab;
 } TP_CAR;


//    void mostra(TP_VEICULO *veiculo){
//    printf("veiculo em mostra(): %s \n Modelo: %s \n Ano: %d \n" , veiculo->marca , veiculo->modelo , veiculo->data_fab.ano);
//    veiculo->data_fab.ano = 2015 ;
//    }

  // - Menu

void Menu() {

    printf("\n 1 - Listar veículos.");
    printf("\n 2 - Cadastrar veículo.");
    printf("\n 3 - Listar veículo por ano:");
    printf("\n 4 - Listar veículo a partir do ano:");
    printf("\n 5 - Listar veículo por modelo:");
    printf("\n 0 - Sair.");
    printf("\n Escolha as opções numericas: ");
}


           // - Listar os veiculos cadastrados;



void vehicles(TYPE_CAR car[]) {

    for (int i = 0; i<10; i++) {

        printf("Veiculo: %s \n Modelo: %s \n Placa: %d \n Ano: %s \n\n  " , car[i].brand , car[i].model , car[i].plate ,car[i].year);
    }
}

void organizeVehicles(int in, TP_CAR carros[]){

TYPE_CAR aux;

for(int i = 0 ; i< ind +1 ; i++){
    for(int j = i + 1 ; j < ind + 1 ; j++){
        if(carros[i].ano > carros[j].ano){
            aux = carro[i];
            carros[i] = carros[j];
            carros[j] = aux ;
        }
    }
}


}



void addVehicle(int index , TP_CAR car){
if(index < 10){
    print("\n Carro %d" , index );

    print("\n Digite a marca:");
    scanf("%s" , &car[index].brand);

    printf("\n digite o modelo:");
   scanf("%s" , &car[index].model);

    printf("\n digite a placa:");
   scanf("%s" , &car[index].plate);

    printf("\n digite o ano:");
   scanf("%d" , &car[index].year);

    organizarCarros(index,car);

}
else {
    printf("\n número maximo atingido!")
}

}



void vehiclesYear(int searchYear, TP_CAR car){
    for(int i = 0 ; i < 10 ; i++){
        if(car[i].ano > searchYear){
                printf("Veiculo: %s \n Modelo: %s \n Placa: %d \n Ano: %s \n\n  " , car[i].brand , car[i].model , car[i].plate ,car[i].year);

        }
    }
}


void vehiclesModels(char searchModel[], TP_CAR car[]){
    for(int i = 0 ; i < 10 ; i++){
        if(strcmp(searchModel, car[i].model) == 0{
           printf("Veiculo: %s \n Modelo: %s \n Placa: %d \n Ano: %s \n\n  " , car[i].brand , car[i].model , car[i].plate ,car[i].year);

           }
    }
}


//
//TP_CAR v1 = {"carro1" , "fusca" , "abc-1234", 2020 };
////v1.data_fab.ano = 2020;
//
//TP_CAR v2 = {"carro2" , "corsa" , "dfc-5647",2015 };
//v1.data_fab.ano = 2020;


//mostra(&v1);

//printf("Veiculo: %s \n Modelo: %s \n Ano: %d \n Placa: %s \n \n " , v1.brand , v1.model , v1.year , v1.plate);
//printf("Veiculo: %s \n Modelo: %s \n Ano: %d \n Placa: %s \n\n  " , v2.brand , v2.model , v2.year ,v2.plate);




int main(){

 //   struct car marca

    TP_CAR car[10] = {};
    int choices = 6;
    int i = 0;
    int searchYear = 0;
    char searchModel[20];

    while(choices != 0 ){

        switch(choices){
    // default:
    //    printf("digite um numero de 1 a 5:");
    //    scanf("%d" , &choices)
    //    break
    //    }
    //
                //lista veiculos cadastrados
        case 1:
            vehicles(car);
            choices = 6;
//            for (int i = 0; i < 10 ; i++){
//             printf("Marca: %s \n Modelo: %s \n Ano: %d \n Placa: %s \n \n " , v1.brand , v1.model , v1.year , v1.plate);
//            }
//            choices = 6;
            break;
                // cadastra veiculos
        case 2:
            addVehicle(i , car)
            i+=1;
            choices = 6;
            break;

            //lista veiculos em ordem de ano crescente
        case 3:
            addVehicle(i , car)
            i+=1;
            choices = 6;
            break;

            //lista veiculos a partir do ano inserido pelo user
        case 4:
          printf("busque veiculos a partir do ano:")
          scanf("%d" , %searchYear);
          vehiclesYears(searchYear , car);
            choices = 6;
            break;

      case 5:
          printf("busque veiculos por modelo:")
          scanf("%s" , %searchModel);
          vehiclesModels(searchModel , car);
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



    //        printf("digite um numero de 1 a 5:");
    //        scanf("%d" , &choices)
    //        break
    //        }
       }



}







          //  - Inserir um novo veiculo;

//char newCar ;
//
//printf("\n  insira um nome de carro:");
//scanf("%d" , &newCar);
//
//printf("%d", newCar);



//    size_t n = sizeof(number)/sizeof(number[0]);
//    printf("Total elements the array can hold is: %d\n",n);
//
//    return 0;



          // - Listar os veiculos filtrando-se por ano de fabricacao;


        // - Listar os veiculos com o ano de fabricacao��o acima de um certo valor especificado pelo usuario

//
//int anoUsuario;
//
//printf("\n  insira um ano:");
//scanf("%d" , &anoUsuario);
//
//printf("%d", anoUsuario);

         //  - Listar os ve�culos filtrando-se pelo modelo.




//return 0;









