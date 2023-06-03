/*
EJ. 6
Se ingresa por teclado un vector de 10 elementos todos distintos entre sí.
Luego eliminar el valor máximo y desplazar todos los elementos un lugar.
Ejemplo:	 
Vector {1 3 9 1 4 6 2 0 5 7 }, quedará {1 3 1 4 6 2 0 5 7}
Nota: No mostrar el último elemento del vector.
*/

#include <iostream>

int main(){
    int const N = 10;
    int arr[N];
    int max;
    int max_i = 0;

    std::cout << "Ingresar " << N << " números:" << std::endl;

    for(int i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    max = arr[0];

    for(int i = 1; i < N; i++){
        if(max < arr[i]){
            max = arr[i];
            max_i = i;
        }
    }

    for(int i = max_i; i < N - 1; i++){
        arr[i] = arr[i+1];
    }

    std::cout << "Se eliminó el máximo:" << std::endl;

    for(int i = 0; i < N; i++){
        std::cout << arr[i] << std::endl;
    }
}