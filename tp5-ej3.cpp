/*
EJ. 3
Una empresa tiene 50 empleados que trabajaron durante 7 días hábiles.
Se confecciona una serie de registros con el objeto de controlar la asistencia de sus empleados.

Hay un primer registro por empleado que contiene:
- Nro. de Legajo
- Cantidad de horas teóricas a trabajar por semana

A continuación de este registro, siete registros más, uno por cada uno de los 7 días con los siguientes datos:
- Hora de entrada (entero)
- Hora de salida (entero)

El día que falta el empleado se ingresa cero en la hora de entrada y salida respectivamente.
Después de estos siete registros aparece nuevamente un registro de otro empleado seguido por los registros de los días trabajados por este último y así hasta el último empleado.

Realizar un programa que ingresando los datos indicados determine e informe:
a) Los nros. de legajo de los empleados que faltaron algún día en la semana.
b) Para cada empleado indicar con una leyenda aclaratoria si trabajó de más, igual o de menos a las horas teóricas que tiene asignadas en la semana.
*/

#include <iostream>

int main(){
    int const TOT_EMP = 50;     // Cantidad de empleados
    int emp;                    // Número de legajo del empleado *
    int hrs;                    // Horas de trabajo por semana *
    int h_in;                   // Hora de entrada *
    int h_out;                  // Hora de salida *
    int accu_hrs = 0;           // Horas trabajadas
    int n_days = 0;             // Días de ausencia

    for(int i = 1; i <= TOT_EMP; i++){
            std::cout << "Número de legajo del empleado:" << std::endl;
            std::cin >> emp;

            std::cout << "Horas de trabajo por semana [h]:" << std::endl;
            std::cin >> hrs;

        for(int i = 1; i <= 7; i++){
            std::cout << "Hora de entrada [h] del día " << i << ":" << std::endl;
            std::cin >> h_in;

            std::cout << "Hora de salida [h] del día " << i << ":" << std::endl;
            std::cin >> h_out;

            if(h_in == h_out){
                n_days ++;
            }

            accu_hrs = accu_hrs + (h_out - h_in);
        }

        if(0 < n_days){
            std::cout << "El empleado número " << emp << " faltó " << n_days << " días en la semana." << std::endl;
        }

        n_days = 0;

        if(accu_hrs == hrs){
            std::cout << "El empleado número " << emp << " trabajó " << accu_hrs << " horas en la semana, tal como se estipulaba." << std::endl;
        } else if(accu_hrs < hrs){
            std::cout << "El empleado número " << emp << " trabajó " << accu_hrs << " horas en la semana, " << hrs - accu_hrs << " horas menos de lo estipulado." << std::endl;
        } else{
            std::cout << "El empleado número " << emp << " trabajó " << accu_hrs << " horas en la semana, " << accu_hrs - hrs << " horas más de lo estipulado." << std::endl;
        }

        accu_hrs = 0;
    }
}