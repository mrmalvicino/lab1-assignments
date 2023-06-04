/*
EJ. 7
Hacer una función que reciba un vector de números enteros y su tamaño y devuelva la posición en donde se encuentra el valor máximo del vector.
*/

#include <iostream>

int max_position(int arr[], int const ARR_SIZE){
        int max = arr[0];
        int position = 0;

        for(int i = 1; i < ARR_SIZE; i++){
            if(max < arr[i]){
                max = arr[i];
                position = i;
            }
        }

        return position;
    }

int main(){
    int arr[7] = {0, 1, 2, 3, 2, 1, 0};
    std::cout << max_position(arr, 7) << std::endl;
}

/*
Compile and run in terminal:
./bin/tp7-ej7
*/