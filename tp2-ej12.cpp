/*
EJ. 12
Hacer un programa para ingresar tres números distintos y listarlos ordenados de menor a mayor.
Ejemplo: si se ingresa 4,-3,7, se debe mostrar -3, 4,7.
*/

#include <iostream>
using namespace std;

int main(){
    float n_1, n_2, n_3, aux;
    cout << "Ingresar tres números." << endl;
    cin >> n_1;
    cin >> n_2;
    cin >> n_3;

    if(n_1>n_2){
        aux = n_2;
        n_2 = n_1;
        n_1 = aux;
    }

    if(n_2>n_3){
        aux = n_3;
        n_3 = n_2;
        n_2 = aux;
    }

    if(n_1>n_2){
        aux = n_2;
        n_2 = n_1;
        n_1 = aux;
    }

    if(n_2>n_3){
        aux = n_3;
        n_3 = n_2;
        n_2 = aux;
    }

    cout << "Orden de menor a mayor:" << endl << n_1 << endl << n_2 << endl << n_3 << endl;
}