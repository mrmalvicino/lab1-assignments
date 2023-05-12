/*
EJ. 8

Un popular juego de dados Napolitano llamado “Lara Lara” consiste en lanzar tres dados y sumar el puntaje teniendo en cuenta que el mismo consiste en:
la suma de los valores pares de los dados multiplicado por el tercer dado lanzado.

Por ejemplo:
1 4 6 → Suma de pares (4 + 6) → 10 * 6 (último dado) → 60 pts
1 3 5 → Suma de pares 0 → 0 * 5 (último dado) → 0 pts

Hacer un programa para ingresar por teclado los valores de los 3 dados e informar que puntaje le corresponde en el “Lara Lara”.
*/

#include <iostream>

int main(){
    int N;                  // Dado tirado
    int score = 0;          // Puntaje

    for(int i = 1; i <= 3; i++){
        std::cout << "Ingresar valor del dado " << i << ":" << std::endl;
        std::cin >> N;

        if(N % 2 == 0){
            score = score + N;
        }
        
        if(i == 3){
            score = score * N;
        }
    }

    std::cout << "Puntaje obtenido: " << score << std::endl;
}