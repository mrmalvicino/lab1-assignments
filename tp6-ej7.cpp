/*
EJ. 7
Se ingresa por teclado en un vector de 10 elementos, 9 números todos distintos entre sí y ordenados de menor a mayor.
Se pide ingresar otro valor e insertarlo en el orden correspondiente y desplazar todos los elementos un lugar.
Vector {1 3 4 5 6 7 10 12 16}
Número ingresado: 9
Vector {1 3 4 5 6 7 9 10 12 16}
*/

#include <iostream>

int main(){
    int const ARR_N = 10;
    int arr[ARR_N] = {};
    int aux_1;
    int aux_2;
    bool flag = 0;

    std::cout << "Ingresar " << ARR_N - 1 << " números del vector:" << std::endl;

    for(int i = 0; i < ARR_N - 1; i++){
        std::cin >> arr[i];
    }

    std::cout << "Ingresar el número a insertar:" << std::endl;
    std::cin >> aux_1;

    if(aux_1 < arr[0]){
        flag = 1;
        aux_2 = aux_1;
    }

    for(int i = 0; i < ARR_N; i++){
        if(flag == 1){
            aux_1 = arr[i];
            arr[i] = aux_2;
            aux_2 = aux_1;
        } else if(arr[i] < aux_1 && aux_1 < arr[i+1]){
            flag = 1;
            aux_2 = arr[i+1];
            arr[i+1] = aux_1;
            i++;
        }
    }

    if(arr[ARR_N-1] < aux_1){
        arr[ARR_N-1] = aux_1;
    }

    std::cout << "Se insertó el número ingresado en el vector:" << std::endl;

    for(int i = 0; i < ARR_N; i++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}