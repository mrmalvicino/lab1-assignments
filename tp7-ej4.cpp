/*
EJ. 4
Hacer una función que reciba un vector de números enteros y su tamaño y cargue cada uno de los elementos.
*/

#include <iostream>

void load_array(int arr[], int size){
    for (int i = 0; i < size; i++){
        std::cout << "Ingresar entero:" << std::endl;
        std::cin >> arr[i];
    }
}

int main(){
    int const SIZE = 3;
    int arr[SIZE];
    load_array(arr, SIZE);
    
    std::cout << "Los enteros ingresados fueron:" << std::endl;
    
    for (int i = 0; i < SIZE; i++){
        std::cout << arr[i] << std::endl;
    }
}