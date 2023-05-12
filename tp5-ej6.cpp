/*
EJ. 6

La asociación tigrense de panaderos desea registrar la información de los productos que comercializó el día de ayer.

Por cada producto registró:
- Código de producto
- Tipo (1 - Factura, 2 - Torta, 3 - Panificado)
- Cantidad de kilogramos vendidos
- Total recaudado ($)

La información no se encuentra agrupada ni ordenada.
Para indicar el fin de la carga de datos se ingresa un código de producto negativo.

Calcular e informar:
1 - El código de producto que haya recaudado la menor cantidad de dinero.
2 - El porcentaje de recaudación para cada tipo de producto.
*/

#include <iostream>

int main(){
    int prod;                   // Código de producto *
    int type;                   // Tipo *
    float quant;                // Cantidad vendida *
    float value;                // Total recaudado *
    float min_val;              // Recaudación mínima
    int min_prod;               // Producto que recaudó el mínimo
    bool flag_min = 0;          // Se registró el primer mínimo?
    float accu_1 = 0;           // Recaudado por facturas
    float accu_2 = 0;           // Recaudado por tortas
    float accu_3 = 0;           // Recaudado por pan
    float accu_tot = 0;         // Recaudación total

    std::cout << "Código de producto:" << std::endl;
    std::cin >> prod;

    while(0 <= prod){
        std::cout << "Tipo de producto:" << std::endl;
        std::cin >> type;

        std::cout << "Cantidad vendida:" << std::endl;
        std::cin >> quant;

        std::cout << "Total recaudado:" << std::endl;
        std::cin >> value;

        if(flag_min == 1){
            if(value < min_val){
                min_val = value;
                min_prod = prod;
            }
        } else{
            min_val = value;
            min_prod = prod;
            flag_min = 1;
        }

        accu_tot = accu_tot + value;

        switch(type){
        case 1:
            accu_1 = accu_1 + value;
            break;
        case 2:
            accu_2  = accu_2 + value;
            break;
        case 3:
            accu_3  = accu_3 + value;
            break;
        }

        std::cout << "Código de producto:" << std::endl;
        std::cin >> prod;
    }

    std::cout << "Producto que recaudó el mínimo: cod. " << min_prod << std::endl;
    std::cout << "Porcentaje de recaudación por facturas: " << (accu_1 / static_cast<float>(accu_tot)) * 100 << " %" << std::endl;
    std::cout << "Porcentaje de recaudación por tortas: " << (accu_2 / static_cast<float>(accu_tot)) * 100 << " %" << std::endl;
    std::cout << "Porcentaje de recaudación por pan: " << (accu_3 / static_cast<float>(accu_tot)) * 100 << " %" << std::endl;
}