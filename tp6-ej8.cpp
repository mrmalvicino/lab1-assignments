/*
EJ. 8
El dueño del gimnasio Laragym nos pide que realicemos un programa que les permita cargar todas los entrenamientos de sus 50 clientes, cada registro de entrenamiento contiene:
Numero de Entrenamiento (1 - 9999)
Cliente (101- 150)
Tipo de Entrenamiento ( 1 - 10 )
Tiempo del Entrenamiento (minutos)

Puede haber varios registros de entrenamiento por cliente.
La información no se encuentra agrupada ni ordenada.
El fin de la carga de entrenamientos se indica con un número de entrenamiento igual a cero, informar:

Por cada cliente, el tiempo total de entrenamiento (expresarlo en horas y minutos, ejemplo 70 minutos se expresaría 1 hora y 10 minutos).
Por cada cliente, los tipos de entrenamiento que realizó.
Por cada cada cliente y tipo de entrenamiento, la cantidad total de minutos entrenados. Sólo listar aquellos registros que sean superiores a 0.
El número de cliente que más tiempo haya entrenado.
Los tipos de entrenamiento que no se realizaron por ningún cliente.
*/

#include <iostream>

int main(){
    int train_num;
    int client;
    int type;
    int time;
    int const CLIENT_0 = 101;
    int const CLIENT_N = 150;
    int const ARR_N = CLIENT_N - CLIENT_0 + 1;
    int const TYPE_0 = 1;
    int const TYPE_M = 10;
    int const ARR_M = TYPE_M - TYPE_0 + 1;
    int mat_arr[ARR_M][ARR_N] = {};

    std::cout << "Ingresar número de entrenamiento:" << std::endl;
    std::cin >> train_num;

    while(train_num != 0){
        std::cout << "Ingresar número de cliente:" << std::endl;
        std::cin >> client;

        std::cout << "Ingresar tipo de entrenamiento:" << std::endl;
        std::cin >> type;

        std::cout << "Ingresar tiempo de entrenamiento:" << std::endl;
        std::cin >> time;

        mat_arr[type-TYPE_0][client-CLIENT_0] += time;

        std::cout << "Ingresar número de entrenamiento:" << std::endl;
        std::cin >> train_num;
    }

    for(int i = 0; i < ARR_M; i++){
        int time_type_i = 0;
        
        for(int j = 0; j < ARR_N; j++){
            time_type_i += mat_arr[i][j];
        }

        if(0 < time_type_i){
            std::cout << "Tiempo de entrenamiento de tipo " << i + TYPE_0 << ":" << std::endl;
            std::cout << time_type_i / 60 << " h  " << time_type_i % 60 << " min" << std::endl;
            std::cout << time_type_i << " min" << std::endl;
        }
    }

    std::cout << std::endl;

    for(int j = 0; j < ARR_N; j++){
        int time_client_j = 0;

        for(int i = 0; i < ARR_M; i++){
            time_client_j += mat_arr[i][j];
        }

        if(0 < time_client_j){
            std::cout << "Tiempo de entrenamiento del cliente " << j + CLIENT_0 << ":" << std::endl;
            std::cout << time_client_j / 60 << " h  " << time_client_j % 60 << " min" << std::endl;
            std::cout << time_client_j << " min" << std::endl;
        }
    }
}

/*
./bin/tp6-ej8
*/