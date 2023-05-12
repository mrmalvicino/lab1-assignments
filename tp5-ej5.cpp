/*
EJ. 5

Un restaurant registró la información de todas las comandas atendidas la noche anterior por sus mozos. Por cada comanda se registró:
- Número de comanda
- Número de mozo (entero)
- Tipo de plato (1 - Entrada, 2 - Plato Principal, 3 - Postre)
- Importe (float)

La información se encuentra agrupada por Número de mozo.
Cada mozo atendió diez comandas.
Para indicar el fin de la carga de datos se registra un Número de mozo negativo.

Calcular e informar:
1 - Por cada mozo, la cantidad de platos de cada tipo.
2 - El número de mozo que haya atendido el Plato Principal de menor importe.
3 - El importe promedio por comanda (entre todas las comandas).

nota: Una comanda es un servicio de mesa (pedido) atendido por un mozo en un restaurant.
*/

#include <iostream>

int main(){
    bool flag_init = 0;             // El programa entró al ciclo externo
    int order;                      // Número de comanda *
    int const ORDERS_TOT = 3;      // Cantidad de comandas por mozo
    int waiter;                     // Número de mozo *
    int type;                       // Tipo de plato *
    int n_type_1 = 0;               // Contador de entradas por mozo
    int n_type_2 = 0;               // Contador de platos principales por mozo
    int n_type_3 = 0;               // Contador de postres por mozo
    int n_orders = 0;               // Contador de comandas (de cualquier tipo)
    float value;                    // Importe *
    float accu_value = 0;           // Acumulador de importes
    float min_value;                // Importe mínimo
    int min_waiter;                 // Mozo que vendió el plato de mínimo importe
    bool flag_min = 0;              // Se registró el primer mínimo

    std::cout << "Número de mozo:" << std::endl;
    std::cin >> waiter;

    while(0 <= waiter){
        if(flag_init == 1){
            std::cout << "Número de mozo:" << std::endl;
            std::cin >> waiter;
        } else{
            flag_init = 1;
        }

        if(0 <= waiter){
            for(int i = 1; i <= ORDERS_TOT; i++){
                std::cout << "Número de comanda:" << std::endl;
                std::cin >> order;

                std::cout << "Tipo de plato:" << std::endl;
                std::cin >> type;

                std::cout << "Importe [$]:" << std::endl;
                std::cin >> value;

                switch(type){
                    case 1:
                        n_type_1 ++;
                        break;
                    case 2:
                        n_type_2 ++;
                        break;
                    case 3:
                        n_type_3 ++;
                        break;
                }

                if(flag_min == 1){
                    if(type == 2 && value < min_value){
                        min_value = value;
                        min_waiter = waiter;
                    }
                } else{
                    min_value = value;
                    min_waiter = waiter;
                    flag_min = 1;
                }

                accu_value = accu_value + value;
                
            }

            std::cout << "MOZO " << waiter << std::endl;
            std::cout << "Cantidad de entradas:" <<  n_type_1 << std::endl;
            std::cout << "Cantidad de platos principales:" <<  n_type_2 << std::endl;
            std::cout << "Cantidad de postres:" <<  n_type_2 << std::endl;

            n_orders = n_type_1 + n_type_2 + n_type_3;
            n_type_1 = 0;
            n_type_2 = 0;
            n_type_3 = 0;
        }
    }

    std::cout << "El mozo " <<  min_waiter << " vendió el plato principal de menor importe." << std::endl;
    std::cout << "Importe promedio: " <<  accu_value / static_cast<float>(n_orders) << std::endl;
}