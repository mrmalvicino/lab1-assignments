/*
EJ. 9
Hacer un programa para ingresar tres números y listar el máximo de ellos.
*/

#include <iostream>
using namespace std;

int main(){
    float n_1, n_2, n_3, max;
    cout << "Ingresar tres números." << endl;
    cin >> n_1;
    cin >> n_2;
    cin >> n_3;
    max = n_1;
    if(max<n_2){
        max = n_2;
    }
    if(max<n_3){
        max = n_3;
    }
    cout << "El máximo es:" << max << endl;
}