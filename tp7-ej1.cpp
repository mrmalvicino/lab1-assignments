/*
EJ. 1
Hacer una función que reciba como parámetro dos números enteros y devuelva verdadero si el primero de ellos es múltiplo del segundo.
Caso contrario debe devolver falso.
*/

#include <iostream>

bool is_multiple(int n_1, int n_2){
    bool rtn;

    if(n_1 % n_2 == 0){
        rtn = true;
    } else{
        rtn = false;
    }

    return rtn;
}

int main(){
    int n_1, n_2;
    std::cout << "Ingrese un numero: " << std::endl;
    std::cin >> n_1;
    std::cout << "Ingrese un numero: " << std::endl;
    std::cin >> n_2;
    std::cout << is_multiple(n_1, n_2) << std::endl;
}