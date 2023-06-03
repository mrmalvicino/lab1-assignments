/*
EJ. 5
Cargar un conjunto de 100 números reales y formar con los valores positivos un vector llamado pos y con los valores negativos un vector llamado nega.
Mostrar por pantalla la cantidad de elementos que contiene cada vector y luego cada uno de los vectores.
Sólo deben utilizarse dos vectores en el programa: pos y nega.
*/

#include <iostream>

int main(){
    int const N = 100;
    float pos[N] = {};
    float neg[N] = {};
    float var;

    std::cout << "Ingresar " << N << " números:" << std::endl;

    for(int i = 0; i < N; i++){
        std::cin >> var;
        if(0 < var){
            pos[i] = var;
        } else if(var < 0){
            neg[i] = var;
        }
    }

    std::cout << "Vector de números positivos:"<< std::endl;

    for(int i = 0; i < N; i++){
        std::cout << pos[i] << " ; ";
    }

    std::cout << "Vector de números negativos:"<< std::endl;

    for(int i = 0; i < N; i++){
        std::cout << neg[i] << " ; ";
    }
}