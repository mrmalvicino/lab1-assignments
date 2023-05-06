/*
LaraKart es un torneo que se realiza todos los años en la Ciudad de Buenos Aires.
Durante el lapso de un día los participantes pueden dirigirse a la pista de karting y realizar el circuito.
Luego de que haya terminado el torneo se anunciará al ganador de la competencia.

El organizador del torneo prevee que la edición 2023 tendrá una gran cantidad de participantes.
Cada participante realizará exactamente 4 vueltas a la pista de carrera, por cada vuelta de cada participante se registrá:
- Código de participante (entero)
- Número de vuelta (1 a 4)
- Tiempo empleado (en minutos)
- Descalificado (1 - Sí; 0 - No)

La información se encuentra agrupada por código de participante.
Por cada participante la información de las vueltas se encuentra ordenada por número de vuelta (de menor a mayor).
Para indicar el fin de la carga de datos se ingresa un código de participante negativo.

Se pide calcular e informar:

A) Informar el ganador de la competencia.
El mismo es aquella persona que haya demorado menos tiempo en completar el circuito completo (las 4 vueltas) y nunca haya sido descalificado.
Informar el código de participante y el tiempo demorado.

B) La cantidad total de participantes que hayan sido descalificados al menos una vez.

C) La cantidad total de participantes que no hayan sido descalificados en la última vuelta.

D) Por cada participante, el porcentaje de vueltas descalificadas y el porcentaje de vueltas no descalificadas.
*/

#include <iostream>

int main(){
    int car;                // Código de participante *
    int car_status;         // Código de participante actual
    int lap;                // Número de vuelta *
    float time;             // Tiempo empleado por vuelta *
    float acc_time = 0;     // Acumulador de tiempo
    float min_time = 1440;  // Tiempo mínimo
    int min_time_car = 1;   // Participante que tardó menos tiempo
    bool disqualified = 0;  // Descalificado en una vuelta *
    bool flag_disq = 0;     // Descalificado al menos una vez
    int count_disq = 0;     // Contador de descalificados
    int count_final;        // Contador de descalificados en última vuelta

    do{
        std::cout << "Código de participante:" << std::endl;
        std::cin >> car;
    } while(car < 0);

    do{
        std::cout << "Número de vuelta:" << std::endl;
        std::cin >> lap;
    } while(lap < 1 && 4 < lap);

    do{
        std::cout << "Tiempo empleado en vuelta:" << std::endl;
        std::cin >> time;
    } while(time <= 0);

    do{
        std::cout << "Descalificado:" << std::endl;
        std::cin >> disqualified;
    } while(disqualified != 0 && disqualified != 1);

    while(car != 0){

        car_status = car;

        while(car == car_status){
            acc_time = acc_time + time;
            
            if(disqualified == 1){
                flag_disq = 1;
                disqualified = 0;
            }

            if(disqualified == 1 && lap == 4){
                count_final ++;
            }

            do{
                std::cout << "Código de participante:" << std::endl;
                std::cin >> car;
            } while(car < 0);

            do{
                std::cout << "Número de vuelta:" << std::endl;
                std::cin >> lap;
            } while(lap < 1 && 4 < lap);

            do{
                std::cout << "Tiempo empleado en vuelta:" << std::endl;
                std::cin >> time;
            } while(time <= 0);

            do{
                std::cout << "Descalificado:" << std::endl;
                std::cin >> disqualified;
            } while(disqualified != 0 && disqualified != 1);
        }

        if(acc_time < min_time && flag_disq == 0){
            min_time = acc_time;
            min_time_car = car_status;
            acc_time = 0;
        } else{
            acc_time = 0;
        }

        if(flag_disq == 1){
            count_disq ++;
            flag_disq = 0;
        }
    }

    std::cout << "Ganador:" << min_time_car << std::endl;                                           // A
    std::cout << "Cantidad de descalificados:" << count_disq << std::endl;                          // B
    std::cout << "Cantidad de descalificados en última vuelta:" << count_final << std::endl;        // C
}