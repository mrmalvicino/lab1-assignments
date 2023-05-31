/*
EJ. 2
Hacer un programa donde se carguen 15 números enteros y luego le solicite al usuario un número e indique si el mismo pertenece a la lista cargada anteriormente.
*/

#include <iostream>

int main(){
    int const SIZE = 15;
    int vec[SIZE];
    int num;

    std::cout << "Ingresar vector:" << std::endl;

    for(int i = 0; i < SIZE; i++){
        std::cin >> vec[i];
    }

    std::cout << "Ingresar número:" << std::endl;
    std::cin >> num;

    for(int i = 0; i < SIZE; i++){
        if(num == vec[i]){
            std::cout << "El número está en el vector." << std::endl;
            i = SIZE;
        }
    }
}