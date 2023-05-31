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
    std::cout << is_multiple(4, 2) << std::endl;
    std::cout << is_multiple(5, 2) << std::endl;
}