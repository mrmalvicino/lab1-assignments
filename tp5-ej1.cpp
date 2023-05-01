/*
EJ. 1
En una empresa los empleados cobran un sueldo según la categoría a la que pertenecen.

Son 50 empleados y los sueldos son:
- Categoría 1: $38000
- Categoría 2: $70000
- Categoría 3: $105000

Al sueldo se le suma además $1200 por cada año trabajado.

Para cada empleado se tienen los siguientes datos:
- Categoría (1 a 3)
- Antigüedad (entero)

Hay un registro por cada empleado.
La información no está agrupada ni ordenada.

Se pide calcular e informar:
a) ¿Cuantos empleados hay para cada categoría?
b) Total de sueldos (en $) pagados para cada categoría.
c) Sueldo Promedio.
d) ¿Cual fue el sueldo máximo y a que categoría pertenece?
*/

#include <iostream>

int main(){
    int n_e = 50;       // cantidad de empleados
    int years;          // años de antiguedad
    float bon = 1200;   // bonificación por año [$]
    int cat;            // categoría
    float cat_val;      // valor de categoría [$]
    int n_cat_1 = 0;    // cantidad de empleados en categoría 1
    int n_cat_2 = 0;    // cantidad de empleados en categoría 2
    int n_cat_3 = 0;    // cantidad de empleados en categoría 3
    float s_cat_1 = 0;  // sueldos en categoría 1 [$]
    float s_cat_2 = 0;  // sueldos en categoría 2 [$]
    float s_cat_3 = 0;  // sueldos en categoría 3 [$]
    float s;            // sueldo [$]
    float s_tot;        // sueldo total [$]
    float s_ave;        // sueldo promedio [$]
    float s_max = 0;    // sueldo máximo [$]
    int s_max_cat;      // categoría del sueldo máximo

    for(int i = 0; i < n_e; i++){
        do{
            std::cout << "Categoría del empleado " << i + 1 << ":" << std::endl;
            std::cin >> cat;
        } while(cat < 1 || 3 < cat);
        
        do{
            std::cout << "Años de antiguedad del empleado " << i << ":" << std::endl;
            std::cin >> years;
        } while(years < 1);

        switch(cat){
            case 1:
                n_cat_1 ++;
                cat_val = 38000;
                s = cat_val + bon*years;
                s_cat_1 = s_cat_1 + s;
                break;
            case 2:
                n_cat_2 ++;
                cat_val = 70000;
                s = cat_val + bon*years;
                s_cat_2 = s_cat_2 + s;
                break;
            case 3:
                n_cat_3 ++;
                cat_val = 105000;
                s = cat_val + bon*years;
                s_cat_3 = s_cat_3 + s;
                break;
        }

        if(s_max < s){
            s_max = s;
            s_max_cat = cat;
        }

        s_tot = s_tot + s;
    }

    s_ave = s_tot / n_e;

    // a) Cantidad de empleados para cada categoría:
    std::cout << "Cantidad de empleados en categoría 1: " << n_cat_1 << std::endl;
    std::cout << "Cantidad de empleados en categoría 2: " << n_cat_2 << std::endl;
    std::cout << "Cantidad de empleados en categoría 3: " << n_cat_3 << std::endl;

    // b) Suma de sueldos para cada categoría:
    std::cout << "Sueldos en categoría 1: $" << s_cat_1 << std::endl;
    std::cout << "Sueldos en categoría 2: $" << s_cat_2 << std::endl;
    std::cout << "Sueldos en categoría 3: $" << s_cat_3 << std::endl;

    // c) Sueldo promedio:
    std::cout << "Sueldo promedio: $" << s_ave << std::endl;

    // d) Sueldo máximo y su respectiva categoría:
    std::cout << "Sueldo máximo: $" << s_max << " (cat. " << s_max_cat << ")" << std::endl;
}