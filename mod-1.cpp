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
    bool flag_init = 0;         // El programa inició (entró al ciclo interno por primera vez)
    int car;                    // Código de participante *
    int lap;                    // Número de vuelta *
    int tot_laps = 4;           // Total de vueltas por participante
    float time;                 // Tiempo empleado por vuelta *
    float accu_time = 0;        // Acumulador de tiempo
    float min_time;             // Tiempo mínimo
    int min_time_car;           // Participante que tardó menos tiempo
    bool flag_min = 0;          // Bandera: Se registró algún mínimo?
    bool disqualified = 0;      // Descalificado en una vuelta *
    float percentage_disq = 0;  // Porcentaje de vueltas descalificadas por participante
    int count_disq = 0;         // Contador de descalificados
    int count_fair = 0;         // Contador de participantes no descalificados en la última vuelta

    std::cout << "Código de participante:" << std::endl;
    std::cin >> car;

    while(0 <= car){

        for(int i = 1; i <= tot_laps; i++){
            if(flag_init == 1){
                std::cout << "Código de participante:" << std::endl;
                std::cin >> car;
            } else{
                flag_init = 1;
            }
            
            if(0 <= car){
                std::cout << "Número de vuelta:" << std::endl;
                std::cin >> lap;

                std::cout << "Tiempo empleado en vuelta:" << std::endl;
                std::cin >> time;
                
                std::cout << "Descalificado:" << std::endl;
                std::cin >> disqualified;
                
                accu_time = accu_time + time;
                
                if(disqualified == 0 && i == 4){
                    count_fair ++;
                }

                if(disqualified == 1){
                    percentage_disq = percentage_disq + 1 / static_cast<float>(tot_laps);
                    disqualified = 0;
                }
            } else{
                i = 4;
            }
        }

        if(0 <= car){
            if(flag_min == 1){
                if(accu_time < min_time && percentage_disq == 0){
                    min_time = accu_time;
                    min_time_car = car;
                    accu_time = 0;
                } else{
                    accu_time = 0;
                }
            } else{
                min_time = accu_time;
                min_time_car = car;
                accu_time = 0;
            }

            std::cout << "Porcentaje de vueltas descalificadas:" << percentage_disq * 100 << "%" << std::endl; // D
            std::cout << "Porcentaje de vueltas no descalificadas:" << (1 - percentage_disq) * 100 << "%" << std::endl; // D

            if(0 < percentage_disq){
                count_disq ++;
                percentage_disq = 0;
            }
        }
    }

    std::cout << "Ganador:" << min_time_car << std::endl; // A
    std::cout << "Cantidad de descalificados:" << count_disq << std::endl; // B
    std::cout << "Cantidad de participantes no descalificados en la última vuelta:" << count_fair << std::endl; // C
}