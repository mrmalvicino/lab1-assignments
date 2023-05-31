/*
EJ. 3
Hacer una función que reciba un número entero como parámetro y devuelva verdadero si el mismo es un número primo.
De lo contrario debe devolver falso.
*/

#include <iostream>

bool is_prime(int N){
    bool rtn = false;
    int count = 0;

    for(int i = 1; i <= N; i++){
        if(N % i == 0){
            count ++;
        }
    }

    if(count <= 2){
        rtn = true;
    }

    return rtn;
}

int main(){
    std::cout << is_prime(1) << std::endl;
    std::cout << is_prime(2) << std::endl;
    std::cout << is_prime(5) << std::endl;
    std::cout << is_prime(8) << std::endl;
    std::cout << is_prime(60) << std::endl;
}