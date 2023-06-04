/*
EJ. 6
Hacer una función que reciba un número entero llamado valor_buscado, un vector de números enteros y su tamaño y devuelva verdadero si el valor buscado se encuentra dentro del vector.
Caso contrario debe devolver falso.
*/

#include <iostream>

bool val_in_arr(int val, int arr[], int const ARR_SIZE){
    bool flag = 0;
    
    for(int i = 0; i < ARR_SIZE; i++){
        if(arr[i] == val){
            flag = true;
        }
    }

    return flag;
}

int main(){
    int val_1 = 3;
    int val_2 = 9;
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << val_in_arr(val_1, arr, 5) << std::endl; // Verdadero
    std::cout << val_in_arr(val_2, arr, 5) << std::endl; // Faso
}

/*
Compile and run in terminal:
./bin/tp7-ej6
*/