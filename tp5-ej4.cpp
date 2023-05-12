/*
EJ. 4

Una empresa transporta encomiendas entre Buenos Aires y Mendoza.
Por cada encomienda se cobra un importe de acuerdo al peso de la misma, con la siguiente escala:

kilos <= 10         A
10 < kilos <= 40    B
40 < kilos          C

Los camiones utilizados transportan un máximo de 200 kilos.
Son cargados a medida que llegan las encomiendas, partiendo en el momento en que una encomienda no puede ser cargada en el camión por exceder los 200 kilos.
En tal caso se procede a colocar en otro camión que así comienza a ser cargado.
Los camiones a medida que se cargan se identifican con un número, partiendo del número uno (1).

Confeccionar un programa para que:
a) Ingrese los valores de los tres importes A, B y C.
b) Ingrese el peso de cada encomienda. Para finalizar la carga de datos se ingresa una encomienda "ficticia", con peso negativo.
c) Por cada encomienda despachada se informe la siguiente información:
Nro. de Camión, Kg. Transportados e Importe Cobrado
d) Informar la cantidad total de camiones y el total facturado.
*/

#include <iostream>

int main(){
    float A;        // Importe [$] para encomiendas menores a 10 kg
    float B;        // Importe [$] para encomiendas de 10 a 40 kg
    float C;        // Importe [$] para encomiendas mayores a 40 kg
    float m = 1;    // Peso [kg] de una encomienda *
    float val;      // Facturación [$] de una encomienda
    float tot;      // Facturación [$] total
    float c = 0;    // Carga [kg] de un camión
    int n = 1;      // Número de camiones usados

    std::cout << "Importe [$] para encomiendas menores a 10 kg:" << std::endl;
    std::cin >> A;
    
    std::cout << "Importe [$] para encomiendas de 10 a 40 kg:" << std::endl;
    std::cin >> B;
    
    std::cout << "Importe [$] para encomiendas mayores a 40 kg:" << std::endl;
    std::cin >> C;

    while(0 < m){
        std::cout << "Peso [kg] de la encomienda:" << std::endl;
        std::cin >> m;

        if(0 < m && m <= 200){
            if(c + m <= 200){
                c = c + m;
            } else{
                n++;
                c = m;
            }

            if(m <= 10){
                val = A;
            } else if(10 < m && m <= 40){
                val = B;
            } else if(40 < m){
                val = C;
            }

            tot = tot + val;

            std::cout << "Se facturó $" << val << " por encomienda de " << m << " kg despachada en el camion n. " << n << std::endl;
        }
    }

    std::cout << "El total de la facturación fue $" << tot << " y se despacharon " << n << " camiones." << std::endl;
}