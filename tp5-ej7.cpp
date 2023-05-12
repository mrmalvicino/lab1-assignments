/*
EJ. 7

La asociación de maratonistas quiere registrar la información de las últimas 5 maratones que se realizaron en el país.

Por cada participante se registró la siguiente información:
- Número de maratón (entero)
- Número de participante (entero)
- Género ('F' - Femenino, 'M' - Masculino, 'X' - Prefiere no indicarlo)
- Tiempo (en minutos)
- Finaliza (1 - Finaliza, 0 - Abandona)

La información se encuentra agrupada por número de maratón.
Cada maratón puede tener una cantidad distinta de participantes.
Para indicar el fin de la carga de datos de una maratón se ingresa un número de participante negativo.

Se pide calcular e informar:
- El porcentaje de participantes por género.
- El tiempo promedio (en minutos) entre todos los que hayan finalizado maratones.
- Por cada maratón, la persona que haya realizado el menor tiempo y haya finalizado la competencia. Indicar el número de participante y el tiempo.
*/

#include <iostream>

int main(){
    bool flag_init = 0;         // El programa entró al ciclo interno
    int N;                      // Número de participante *
    char sex;                   // Sexo *
    int n_M = 0;                // Cantidad de hombres del lote
    int n_F = 0;                // Cantidad de mujeres del lote
    int n_X = 0;                // Cantidad de indeterminados del lote
    int n_tot = 0;              // Cantidad total de participantes
    float time;                 // Tiempo *
    float accu_time = 0;        // Acumulador de tiempo
    int n_tot_finished = 0;     // Contador de participantes que terminaron
    float min_time = 86400;     // Tiempo mínimo por maratón
    int min_N;                  // Número de participante con tiempo mínimo
    bool finished;              // Terminó? (o abandonó?) *

    for(int i = 1; i <= 5; i++){
        std::cout << "Número de participante:" << std::endl;
        std::cin >> N;
        
        while(N >= 0){

            if(flag_init == 1){
                std::cout << "Número de participante:" << std::endl;
                std::cin >> N;
            } else{
                flag_init = 1;
            }

            if(N >= 0){
                std::cout << "Sexo:" << std::endl;
                std::cin >> sex;

                std::cout << "Tiempo:" << std::endl;
                std::cin >> time;

                std::cout << "Finalizó la maratón:" << std::endl;
                std::cin >> finished;

                switch(sex){
                    case 'm':
                        n_M ++;
                        break;
                    case 'f':
                        n_F ++;
                        break;
                    case 'x':
                        n_X ++;
                        break;
                }

                if(finished){
                    accu_time = accu_time + time;
                    n_tot_finished ++;
                }
                
                if(time < min_time && finished){
                    min_time = time;
                    min_N = N;
                }
            }
        }

        flag_init = 0;
        std::cout << "Tiempo mínimo: " << min_time << " min (Competidor " << min_N << ")" << std::endl;
    }

    n_tot = n_M + n_F + n_X;

    std::cout << "Porcentaje de hombres: " << (n_M / static_cast<float>(n_tot)) * 100 << " %" << std::endl;
    std::cout << "Porcentaje de mujeres: " << (n_F / static_cast<float>(n_tot)) * 100 << " %" << std::endl;
    std::cout << "Porcentaje de indeterminados: " << (n_X / static_cast<float>(n_tot)) * 100 << " %" << std::endl;
    std::cout << "Tiempo promedio: " << (accu_time / static_cast<float>(n_tot_finished)) << " min" << std::endl;
}