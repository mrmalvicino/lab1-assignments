/*
EJ. 1
Hacer un programa que le pida al usuario una lista de 10 números enteros y luego de ingresarlos muestre cuáles de ellos fueron positivos.
*/

#include <iostream>

int main(){
    int vec[10];
    
    for(int i = 0; i < 10; i++){
        std::cin >> vec[i];
    }

    for(int i = 0; i < 10; i++){
        if(0 < vec[i]){
            std::cout << vec[i] << std::endl;
        }
    }
}