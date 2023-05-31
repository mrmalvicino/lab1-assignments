/*
EJ. 3
Hacer un programa donde se carguen 15 números enteros y luego muestre por pantalla el mínimo elemento del vector y además indique cuántas veces se repite el valor mínimo dentro del vector.
*/

#include <iostream>

int main(){
    int const SIZE = 5;
    int vec[SIZE];
    int min;
    int count = 1;

    std::cout << "Ingresar vector:" << std::endl;

    for(int i = 0; i < SIZE; i++){
        std::cin >> vec[i];
    }

    min = vec[0];
    for(int i = 1; i < SIZE; i++){
        if(vec[i] < min){
            min = vec[i];
            count = 1;
        } else if(vec[i] == min){
            count++;
        }
    }

    std::cout << "Mínimo: " << min << std::endl;
    std::cout << "Veces que se repite: " << count << std::endl;
}