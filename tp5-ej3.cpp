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
    int n_emp = 3;  // Cantidad de empleados
    int emp;        // Número de legajo del empleado
    int hrs;        // Horas de trabajo por semana [h]
    int h_in;       // Hora de entrada [h]
    int h_out;      // Hora de salida [h]
    int h_sum = 0;  // Horas trabajadas [h]
    int days_a = 0; // Días de ausencia

    for(int i = 0; i < n_emp; i++){
        do{
            std::cout << "Número de legajo del empleado:" << std::endl;
            std::cin >> emp;
        } while(emp < 1);

        do{
            std::cout << "Horas de trabajo por semana [h]:" << std::endl;
            std::cin >> hrs;
        } while(hrs < 1);

        for(int i = 0; i < 7; i++){
            do{
                std::cout << "Hora de entrada [h] del día " << i + 1 << ":" << std::endl;
                std::cin >> h_in;
            } while(h_in < 0 || 23 < h_in);

            do{
                std::cout << "Hora de salida [h] del día " << i + 1 << ":" << std::endl;
                std::cin >> h_out;
            } while(h_out < h_in);

            if(h_in == h_out){
                days_a ++;
            }

            h_sum = h_sum + (h_out - h_in);
        }

        if(0 < days_a){
            std::cout << "El empleado número " << emp << " faltó " << days_a << " días en la semana." << std::endl;
        }

        days_a = 0;

        if(h_sum == hrs){
            std::cout << "El empleado número " << emp << " trabajó " << h_sum << " horas en la semana, tal como se estipulaba." << std::endl;
        } else if(h_sum < hrs){
            std::cout << "El empleado número " << emp << " trabajó " << h_sum << " horas en la semana, " << hrs - h_sum << " horas menos de lo estipulado." << std::endl;
        } else{
            std::cout << "El empleado número " << emp << " trabajó " << h_sum << " horas en la semana, " << h_sum - hrs << " horas más de lo estipulado." << std::endl;
        }

        h_sum = 0;
    }
}