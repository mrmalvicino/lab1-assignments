/*
EJ. 2
Hacer una función que reciba como parámetro un número float y devuelva un número entero con el redondeo del mismo.

Por ejemplo:
Si recibe 7.78 debe devolver 8
Si recibe 7.48 debe devolver 7
Si recibe 7.5 debe devolver 8
*/

#include <iostream>

int my_round(float N){
    int rtn, roof, floor;
    roof = static_cast<int>(N) + 1;
    floor = static_cast<int>(N);

    if(roof - N <= 0.5){
        rtn = roof;
    } else{
        rtn = floor;
    }

    return rtn;
}

int main(){
    std::cout << my_round(7.48) << std::endl;
    std::cout << my_round(7.5) << std::endl;
}