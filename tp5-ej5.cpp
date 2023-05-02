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
    int order;              // Número de comanda
    int orders_n = 0;       // Contador de comandas por mozo
    int orders_tot = 10;    // Cantidad de comandas por mozo (parámetro arbitrario)
    int waiter;             // Número de mozo
    int waiter_n = 1;       // Contador de mozos trabajando
    int waiter_status;      // Número de mozo actual
    int type;               // Tipo de plato
    int type_1_n = 0;       // Contador de platos de tipo 1 por mozo
    int type_2_n = 0;       // Contador de platos de tipo 2 por mozo
    int type_3_n = 0;       // Contador de platos de tipo 3 por mozo
    float value;            // Importe [$]
    float value_accu = 0;   // Acumulador de importes [$]
    float min_value;        // Importe mínimo [$]
    int min_waiter;         // Mozo que vendió el plato de mínimo importe [$]
    bool min_flag = 0;      // Bandera: ¿Se registró el primer mínimo?
    bool end_flag = 0;      // Bandera: ¿Fin de carga de datos?

    // user inputs
    do{
        std::cout << "Número de orden:" << std::endl;
        std::cin >> order;
    } while(order <= 0);

    do{
        std::cout << "Número de mozo:" << std::endl;
        std::cin >> waiter;
    } while(waiter <= 0);

    do{
        std::cout << "Tipo de plato:" << std::endl;
        std::cin >> type;
    } while(type != 1 && type != 2 && type != 3);

    do{
        std::cout << "Importe [$]:" << std::endl;
        std::cin >> value;
    } while(value <= 0);

    // main

    while(0 < waiter){
        waiter_status = waiter;

        while(waiter == waiter_status){
            // process per order
            switch(type){
                case 1:
                    type_1_n++;
                    break;
                case 2:
                    type_2_n++;
                    break;
                case 3:
                    type_3_n++;
                    break;
            }

            if(min_flag == 1){
                if(value < min_value){
                    min_value = value;
                    min_waiter = waiter;
                }
            } else{
                min_value = value;
                min_waiter = waiter;
                min_flag = 1;
            }

            orders_n++;
            value_accu = value_accu + value;

            // user inputs
            do{
                std::cout << "Número de orden:" << std::endl;
                std::cin >> order;
            } while(order <= 0);

            if(orders_n < orders_tot){
                do{
                    std::cout << "Número de mozo:" << std::endl;
                    std::cin >> waiter;
                } while(waiter != waiter_status);
            } else{
                do{
                    std::cout << "Número de mozo:" << std::endl;
                    std::cin >> waiter;
                    if(waiter <= 0){
                        end_flag = 1;
                    }
                } while(waiter == waiter_status);
            }

            if(end_flag == 0){
                do{
                    std::cout << "Tipo de plato:" << std::endl;
                    std::cin >> type;
                } while(type != 1 && type != 2 && type != 3);

                do{
                    std::cout << "Importe [$]:" << std::endl;
                    std::cin >> value;
                } while(value <= 0);
            }
        }

        // outputs per waiter
        std::cout << "Comandas del mozo " << waiter_status << " de tipo 1: " << type_1_n << std::endl;
        std::cout << "Comandas del mozo " << waiter_status << " de tipo 2: " << type_2_n << std::endl;
        std::cout << "Comandas del mozo " << waiter_status << " de tipo 3: " << type_3_n << std::endl;

        // process per waiter
        if(end_flag == 0){
            orders_n = 0;
            type_1_n = 0;
            type_2_n = 0;
            type_3_n = 0;
            waiter_n++;
        }
    }

    // main outputs
    std::cout << "El mozo " << min_waiter << " comandó el plato de menor importe." << std::endl;
    std::cout << "El importe promedio entre todas las comandas es " << value_accu / (waiter_n * orders_tot) << std::endl;
}

// Por ambiente ideal, el usuario no pisa los números de comandas ni los números de mozos en distintos registros.
// ¿Es correcto que el informe sobre un mozo salga después de la primer entrada del mozo que le sigue?