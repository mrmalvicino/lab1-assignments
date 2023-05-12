/*
EJ. 2
Un banco tiene tres sucursales, ubicadas en las siguientes localidades:
- Sucursal 1: Virreyes
- Sucursal 2: San Fernando
- Sucursal 3: Tigre

En cada una de ellas se registra para cada transacción que realiza un cliente, los siguientes datos:
- Nro. de Cliente (100 al 1200)
- Nro. de Sucursal (1, 2 ó 3)
- Código de Transacción (‘D’ para depósitos, ‘E’ para extracciones)
- Monto en pesos de la transacción

El último registro se indica con nro. de cliente igual a cero. Se pide a partir de estos datos, determinar e informar:
a) Cantidad de depósitos por más de $1000.-.
b) El nro. de cliente que hizo la extracción por mayor monto, y en que sucursal la hizo.
c) El porcentaje de transacciones realizadas en cada una de las sucursales, respecto al total de las mismas.
d) Total de pesos depositados en cada una de las sucursales.
e) Cantidad de depósitos en la sucursal de Tigre.
f) El nro. de sucursal que recibió más cantidad de depósitos (sin importar el monto de los mismos).
*/

#include <iostream>

int main(){
    bool flag_init = 0;     // El programa entró al ciclo interno
    int cli;                // número de cliente *
    int bank;               // número de sucursal *
    char type;              // tipo de transacción *
    float amount;           // monto de transacción *
    int n_dep = 0;          // cantidad de depósitos mayores a $1000
    float max_ext = 0;      // valor de la extracción máxima [$]
    int max_ext_cli;        // cliente que realizó la máxima extracción
    int max_ext_bank;       // sucursal en la que se realizó la máxima extracción
    int n_tot = 0;          // cantidad de transacciones en total
    int n_1 = 0;            // cantidad de transacciones en sucursal 1
    int n_2 = 0;            // cantidad de transacciones en sucursal 2
    int n_3 = 0;            // cantidad de transacciones en sucursal 3
    float dep_1 = 0;        // depósitos en sucursal 1 [$]
    float dep_2 = 0;        // depósitos en sucursal 2 [$]
    float dep_3 = 0;        // depósitos en sucursal 3 [$]
    int n_dep_1 = 0;        // cantidad de depósitos en sucursal 1
    int n_dep_2 = 0;        // cantidad de depósitos en sucursal 2
    int n_dep_3 = 0;        // cantidad de depósitos en sucursal 3
    int max_dep_bank = 1;   // sucursal en la que se realizó más depósitos

    std::cout << "Número de cliente:" << std::endl;
    std::cin >> cli;

    while(cli != 0){
        if(flag_init = 1){
            std::cout << "Número de cliente:" << std::endl;
            std::cin >> cli;
        } else{
            flag_init = 1;
        }

        if(cli != 0){
            std::cout << "Número de sucursal:" << std::endl;
            std::cin >> bank;

            std::cout << "Tipo de transacción:" << std::endl;
            std::cin >> type;

            std::cout << "Monto:" << std::endl;
            std::cin >> amount;

            if(1000 < amount && (type == 'D' || type == 'd')){
                n_dep ++;
            }

            if(max_ext < amount && (type == 'e' || type == 'E')){
                max_ext = amount;
                max_ext_cli = cli;
                max_ext_bank = bank;
            }

            n_tot ++;

            switch(bank){
                case 1:
                    n_1 ++;
                    if(type == 'd' || type == 'D'){
                        dep_1 = dep_1 + amount;
                        n_dep_1 ++;
                    }
                    break;
                case 2:
                    n_2 ++;
                    if(type == 'd' || type == 'D'){
                        dep_2 = dep_2 + amount;
                        n_dep_2 ++;
                    }
                    break;
                case 3:
                    n_3 ++;
                    if(type == 'd' || type == 'D'){
                        dep_3 = dep_3 + amount;
                        n_dep_3 ++;
                    }
                    break;
            }
        }
    }

    if(n_dep_1 < n_dep_2 && n_dep_3 < n_dep_2){
        max_dep_bank = 2;
    }

    if(n_dep_1 < n_dep_3 && n_dep_2 < n_dep_3){
        max_dep_bank = 3;
    }

    // Cantidad de depósitos por más de $1000:
    std::cout << "Cantidad de depósitos por más de $1000: " << n_dep << std::endl;

    // Cliente que hizo la mayor extracción, y en qué sucursal la hizo:
    std::cout << "Cliente que hizo la mayor extracción: " << max_ext_cli << " (suc. " << max_ext_bank << ")" << std::endl;
    
    // Porcentaje de transacciones en cada sucursal:
    std::cout << "Cantidad de transacciones en sucursal 1: " << (static_cast<float>(n_1)/n_tot)*100 << "%" << std::endl;
    std::cout << "Cantidad de transacciones en sucursal 2: " << (static_cast<float>(n_2)/n_tot)*100 << "%" << std::endl;
    std::cout << "Cantidad de transacciones en sucursal 3: " << (static_cast<float>(n_3)/n_tot)*100 << "%" << std::endl;
    
    // Total depositado en cada sucursal:
    std::cout << "Depositado en sucursal 1: $" << dep_1 << std::endl;
    std::cout << "Depositado en sucursal 2: $" << dep_2 << std::endl;
    std::cout << "Depositado en sucursal 3: $" << dep_3 << std::endl;
    
    // Cantidad de depósitos en sucursal 3:
    std::cout << "Cantidad de depósitos en sucursal 3: " << n_dep_3 << std::endl;
    
    // Sucursal que recibió más depósitos:
    std::cout << "Sucursal que recibió más depósitos: " << max_dep_bank << std::endl;
}