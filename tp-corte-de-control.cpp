/*
Una casa de ventas de libros con varias sucursales registró las ventas durante el mes anterior en un lote de registros.

Para cada venta se registraron los siguientes datos:
- Sucursal de la venta (1 a 20)
- Número del vendedor que efectuó la venta (1 a 150)
- Día de la venta (1 a 31)
- Importe de la venta
- Tipo de Cliente ("U"= Universitario, "N"= No Universitario )
- Editorial del libro("A"= Alvarez, "B"= Benitez, "P"= Perez)

El lote finaliza con un registro con importe igual a cero.
Los datos se ingresan agrupados por sucursal.

A partir de esta información se pide determinar e informar:

a) La comisión total pagada a todos los vendedores en el mes para cada sucursal.
Considerar que la comisión es:
- un 10% del importe de la venta si se trata de un libro de la editorial Alvarez
- un 12% para Benitez
- y un 15% para Perez.

b) La cantidad total vendida de libros por cada sucursal y discriminado por cada editorial.
Se deberán mostrar tres cantidades por sucursal.

c) El número de vendedor que haya efectuado la venta individual de mayor importe,
informando en qué sucursal trabaja y el día en que se realizó esa venta. 
Se esperan los datos de un único vendedor.
*/

#include <iostream>

int main(){
    int sucursal;                   // Sucursal de la venta *
    int sucursal_actual;            // Registro actual de sucursal
    int N_vendedor;                 // Número del vendedor que efectuó la venta *
    int dia;                        // Día de la venta *
    float importe;                  // Importe de la venta *
    char tipo;                      // Tipo de Cliente ('U', 'N') *
    char editorial;                 // Editorial del libro ('A', 'B', 'P') *
    float const COMISION_A = 0.10;  // Porcentaje de comisión para Alvarez
    float const COMISION_B = 0.12;  // Porcentaje de comisión para Benitez
    float const COMISION_P = 0.15;  // Porcentaje de comisión para Perez
    float porcentaje;               // Porcentaje de comisión por la venta
    float acu_comision = 0;         // Comisión total pagada a todos los vendedores
    int cant_libros_A = 0;          // Cantidad de libros de A vendidos
    int cant_libros_B = 0;          // Cantidad de libros de B vendidos
    int cant_libros_P = 0;          // Cantidad de libros de P vendidos
    float max_importe;              // Importe máximo
    int max_vendedor;               // Vendedor que vendió el máximo importe
    int max_sucursal;               // Sucursal en la que se vendió el máximo importe
    int max_dia;                    // Día en el que se vendió el máximo importe
    bool flag_max = 0;              // Se registró el primer máximo

    std::cout << "Sucursal de la venta:" << std::endl;
    std::cin >> sucursal;

    std::cout << "Número del vendedor que efectuó la venta:" << std::endl;
    std::cin >> N_vendedor;

    std::cout << "Día de la venta:" << std::endl;
    std::cin >> dia;

    std::cout << "Importe de la venta:" << std::endl;
    std::cin >> importe;

    while(importe != 0){
        sucursal_actual = sucursal;

        while(sucursal == sucursal_actual && importe != 0){
            std::cout << "Tipo de Cliente:" << std::endl;
            std::cin >> tipo;

            std::cout << "Editorial del libro:" << std::endl;
            std::cin >> editorial;
            
            switch(editorial){
                case 'A':
                    porcentaje = COMISION_A;
                    cant_libros_A ++;
                    break;
                case 'B':
                    porcentaje = COMISION_B;
                    cant_libros_B ++;
                    break;
                case 'P':
                    porcentaje = COMISION_P;
                    cant_libros_P ++;
                    break;
            }
            
            acu_comision = acu_comision + porcentaje * importe;

            if(flag_max == 1){
                if(max_importe < importe){
                    max_importe = importe;
                    max_vendedor = N_vendedor;
                    max_sucursal = sucursal;
                    max_dia = dia;
                }
            } else{
                max_importe = importe;
                max_vendedor = N_vendedor;
                max_sucursal = sucursal;
                max_dia = dia;
                flag_max = 1;
            }

            std::cout << "Sucursal de la venta:" << std::endl;
            std::cin >> sucursal;
            
            std::cout << "Número del vendedor que efectuó la venta:" << std::endl;
            std::cin >> N_vendedor;

            std::cout << "Día de la venta:" << std::endl;
            std::cin >> dia;

            std::cout << "Importe de la venta:" << std::endl;
            std::cin >> importe;
        }

        // ITEM (a)
        std::cout << "Comisión total de todos los vendedores de la sucursal " << sucursal_actual << ": " << acu_comision << std::endl;

        // ITEM (b)
        std::cout << "Cantidad de libros de A vendidos: " << cant_libros_A << std::endl;
        std::cout << "Cantidad de libros de B vendidos: " << cant_libros_B << std::endl;
        std::cout << "Cantidad de libros de P vendidos: " << cant_libros_P << std::endl;

        acu_comision = 0;
        cant_libros_A = 0;
        cant_libros_B = 0;
        cant_libros_P = 0;
    }

    std::cout << "Número de vendedor que efectuó la venta individual de mayor importe: " << max_vendedor << std::endl;
    std::cout << "Sucursal en la que se vendió el máximo importe: " << max_sucursal << std::endl;
    std::cout << "Día en el que se vendió el máximo importe: " << max_dia << std::endl;
}