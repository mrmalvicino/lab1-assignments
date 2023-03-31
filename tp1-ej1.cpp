/*
EJ. 1
Hacer un programa que permita ingresar dos números enteros por teclado.
Luego calcular e informar la suma de ellos.
*/

#include <iostream>
using namespace std;
#include <cstdlib>

int main(){
  int num1, num2, resultado;
  cout << "Ingresar dos nros enteros para ser sumados:" << endl;
  cin >> num1;
  cin >> num2;
  resultado = num1 + num2;
  cout << endl;
  cout << "Resultado de la suma: " << resultado << endl;
  system("pause");

  return 0;
}