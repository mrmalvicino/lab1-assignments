/*
EJ. 5
Hacer una función que reciba un vector de números enteros y su tamaño y liste cada uno de los elementos.
*/

#include <iostream>

void printArray(int arr[], int const SIZE){
    for (int i = 0; i < SIZE - 1; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << arr[SIZE - 1];
}