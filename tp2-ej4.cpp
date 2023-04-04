/*
EJ. 1
Hacer un programa para ingresar por teclado dos números y luego informar por pantalla la diferencia absoluta entre ambos.
Ejemplo 1: Si se ingresan 3 y 8, se emite 5. Si se ingresan 8 y 3, se emite 5.
Ejemplo 2: Si se ingresan -3 y 9, se emite 12. Si se ingresan -12 y -1, se emite 11.
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
// FORMA MATEMÁTICA
int main(){
  float n_1, n_2, dif;
  cout << "Ingresar dos números." << endl;
  cin >> n_1;
  cin >> n_2;
  dif = pow(pow((n_1 - n_2), 2), 0.5);
  cout << "Resta: " << dif << endl;
  return 0;
}
*/

// FORMA LÓGICA
int main(){
  float n_1, n_2, dif;
  cout << "Ingresar dos números." << endl;
  cin >> n_1;
  cin >> n_2;
  if(n_1<n_2){
    dif = n_2 - n_1;
  }
  else{
    dif = n_1 - n_2;
  }
  cout << "Módulo de la diferencia: " << dif << endl;
  return 0;
}
