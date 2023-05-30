/*
La clínica San Simón Protector dispone de la información de los últimos turnos de sus enfermeros.

Por cada turno trabajado por un enfermero se registró la siguiente información:
- Legajo del enfermero (entero)
- Número de turno (entero)
- Horario ('M' - Mañana, 'T' - Tarde, 'N' - Noche)
- Cantidad de horas trabajadas en el turno (entero mayor a cero)

La información se encuentra agrupada por legajo de enfermero.
No todos los enfermeros trabajaron la misma cantidad de turnos.
Para indicar el fin de los registros de un enfermero se ingresa un número de turno igual a cero.
Para indicar el fin del lote de datos se ingresa un legajo de enfermero negativo.

Notas
Cada turno consiste en 8 horas.
Las horas excedentes se consideran horas extras.
Por ejemplo: Si un enfermero trabajó 12 horas en un turno, realizó 8 hs regulares y 4 hs extra.
En cambio, si trabajó 6 horas en un turno: realizó 6 hs regulares y 0 hs extra.

Informar:
A) Por cada enfermero, el promedio de horas trabajadas por turno en el horario de la noche.
B) La cantidad total de horas extras realizadas entre todos los enfermeros.
C) La cantidad de enfermeros que realizaron al menos un turno en los tres horarios (mañana, tarde y noche).
D) El horario (mañana, tarde o noche) que haya registrado menor cantidad de horas trabajadas.
Sólo habrá un horario que haya registrado la menor cantidad de horas trabajadas.
*/

#include <iostream>

int main(){
    int doc;                    // Legajo del enfermero *
    int N;                      // Número de turno *
    char type;                  // Horario (M/T/N) *
    int hrs;                    // Cantidad de horas trabajadas por turno *
    int accu_hrs_N = 0;         // Acumulador de horas en turno noche por enfermero
    int n_N = 0;                // Contador de turnos noche por enfermero
    int accu_hrs_extra = 0;     // Cantidad total de horas extras realizadas entre todos los enfermeros
    bool flag_N = 0;            // Enfermero realizó al menos un turno noche
    bool flag_T = 0;            // Enfermero realizó al menos un turno tarde
    bool flag_M = 0;            // Enfermero realizó al menos un turno mañana
    int n_NTM = 0;              // Cantidad de enfermeros que realizaron al menos un turno en los tres horarios
    int accu_N = 0;             // Cantidad de horas trabajadas en turno N
    int accu_T = 0;             // Cantidad de horas trabajadas en turno T
    int accu_M = 0;             // Cantidad de horas trabajadas en turno M
    char min_type;              // Horario que acumuló menos horas trabajadas

    std::cout << "Legajo del enfermero:" << std::endl;
    std::cin >> doc;

    while(0 <= doc){

        std::cout << "Número de turno:" << std::endl;
        std::cin >> N;
        
        while(N != 0){
            std::cout << "Horario (M/T/N):" << std::endl;
            std::cin >> type;

            std::cout << "Cantidad de horas trabajadas en el turno:" << std::endl;
            std::cin >> hrs;
            
            if(type == 'N'){
                accu_hrs_N = accu_hrs_N + hrs;
                n_N ++;
            }

            switch(type){
                case 'N':
                    flag_N = 1;
                    accu_N = accu_N + hrs;
                    break;
                case 'T':
                    flag_T = 1;
                    accu_T = accu_T + hrs;
                    break;
                case 'M':
                    flag_M = 1;
                    accu_M = accu_M + hrs;
                    break;
            }

            if(8 < hrs){
                accu_hrs_extra = accu_hrs_extra + hrs - 8;
            }

            std::cout << "Número de turno:" << std::endl;
            std::cin >> N;
        }

        if(flag_N && flag_T && flag_M){
            n_NTM ++;
        }

        flag_N = 0;
        flag_T = 0;
        flag_M = 0;

        std::cout << "Promedio de horas trabajadas por turno en el horario de la noche: " << accu_hrs_N / static_cast<float>(n_N) << std::endl;
        
        accu_hrs_N = 0;
        n_N = 0;

        std::cout << "Legajo del enfermero:" << std::endl;
        std::cin >> doc;
    }

    if(accu_N < accu_M & accu_N < accu_T){
        min_type = 'N';
    } else if(accu_T < accu_M){
        min_type = 'T';
    } else{
        min_type = 'M';
    }

    std::cout << "Cantidad total de horas extras realizadas entre todos los enfermeros: " << accu_hrs_extra << std::endl;
    std::cout << "Cantidad de enfermeros que realizaron al menos un turno en los tres horarios: " << n_NTM << std::endl;
    std::cout << "Horario que acumuló menos horas trabajadas: " << min_type << std::endl;
}