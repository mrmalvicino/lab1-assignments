/*
Una fábrica cuenta con un lote de registros con los datos de los empleados que trabajan en la misma, cada registro contiene:

- Número de empleado (3 dígitos, no correlativos).
- Categoría (1 a 20).
- Antigüedad.

Este lote se encuentra ordenado por empleado en forma ascendente (de menor a mayor) y finaliza con un registro con categoría igual a cero. La empresa cuenta como máximo con 200 empleados.

Existe un segundo lote con la información de los días trabajados por los empleados durante el mes anterior, cada registro contiene:

- Día (1 a 31).
- Número de empleado (3 dígitos, no correlativos).
- Cantidad de horas trabajadas ese día (entero).
- Jornal cobrado ese día.

Este lote finaliza con un registro con número de empleado igual a cero. Se generó un registro por cada día trabajado por cada empleado; los días no trabajados no tienen registro. Se pide determinar e informar:

a) Para cada número de empleado informar el día del mes que más horas trabajó.
b) Para cada número de empleado informar el total a cobrar, tener en cuenta que a los empleados que hayan trabajado más de 20 días se le debe adicionar un premio de $200.
c) Informar cual es el número de categoría por la cual se haya pagado mayor cantidad de pesos en sueldos.
*/

#include <iostream>

struct EMPLEADO{
    int num_de_emp;
    int categoria;
    int antiguedad;
};

struct SUELDO{
    int num_de_emp;
    int categoria;
    int sueldo;
};

void cargar_datos(EMPLEADO lote_de_carga[], int const CANT_EMP){
    int num_de_emp;
    int categoria;
    int antiguedad;

    for(int i = 0; i < CANT_EMP; i ++){
        std::cin >> num_de_emp;
        std::cin >> categoria;

        if(categoria != 0){
            std::cin >> antiguedad;
            lote_de_carga[i].num_de_emp = num_de_emp;
            lote_de_carga[i].categoria = categoria;
            lote_de_carga[i].antiguedad = antiguedad;
        } else{
            i = CANT_EMP;
        }
    }
}

void cargar_procesos(int lote_de_proceso[][200][31], int CANT_EMP){ // No pude no hardcodear CANT_EMP y CANT_DIAS en las dimensiones de la matriz.
    int dia;
    int num_de_emp;
    int horas_trabajadas;
    int jornal_cobrado;

    for(int j = 0; j < CANT_EMP; j ++){
        std::cin >> dia;
        std::cin >> num_de_emp;
        
        if(num_de_emp != 0){
            std::cin >> horas_trabajadas;
            std::cin >> jornal_cobrado;
            lote_de_proceso[0][j][dia - 1] = num_de_emp;
            lote_de_proceso[1][j][dia - 1] = horas_trabajadas;
            lote_de_proceso[2][j][dia - 1] = jornal_cobrado;
        } else{
            j = CANT_EMP;
        }
    }
}

int main(){
    int const CANT_VARS = 3;
    int const CANT_EMP = 200;
    int const CANT_DIAS = 31;
    int const PREMIO = 200;
    int emp_actual;
    int max_dia;
    int max_horas = 0;
    int tot_a_cobrar = 0;
    int cant_jornales_cobrados = 0;
    int max_sueldo = 0;
    int max_cat;
    EMPLEADO lote_de_carga[CANT_EMP] = {}; // Vector que tiene en cada componente un dato de tipo EMPLEADO.
    SUELDO sueldos[CANT_EMP] = {}; // Vector que tiene en cada componente un dato de tipo SUELDO.
    int lote_de_proceso[CANT_VARS][CANT_EMP][CANT_DIAS] = {}; // Matriz que tiene por columnas los empleados, por filas el legajo, las horas y el sueldo y en la tercer dimension los dias del mes.

    cargar_datos(lote_de_carga, CANT_EMP);
    cargar_procesos(lote_de_proceso, CANT_EMP);

    for(int j = 0; j < CANT_EMP; j ++){ // Por cada empleado
        for(int k = 0; k < CANT_DIAS; k ++){ // Por cada dia
            if(lote_de_proceso[0][j][k] != 0){ // Esto es solo para luego informar cada legajo. No se me ocurrio como hacerlo sin tener que entrar a este if en cada vuelta.
                emp_actual = lote_de_proceso[0][j][k]; 
            }
            
            if(max_horas < lote_de_proceso[1][j][k]){ // Punto A
                max_dia = k + 1;
                max_horas = lote_de_proceso[1][j][k];
            }

            if(lote_de_proceso[2][j][k] != 0){ // Punto B
                tot_a_cobrar += lote_de_proceso[2][j][k];
                cant_jornales_cobrados ++;
            }
        }

        if(20 < cant_jornales_cobrados){
            tot_a_cobrar += PREMIO;
        }

        sueldos[j].num_de_emp = emp_actual;
        sueldos[j].sueldo = tot_a_cobrar;

        for(int i = 0; i < CANT_EMP; i ++){ // Fetchiar categoria del EMPLEADO
            if(sueldos[j].num_de_emp == lote_de_carga[i].num_de_emp){
                sueldos[j].categoria = lote_de_carga[i].categoria;
            }
        }

        cant_jornales_cobrados = 0;

        std::cout << "El empleado " << emp_actual << " trabajo " << max_horas << " el dia " << max_dia << std::endl;
        std::cout << "El empleado " << emp_actual << " tiene para cobrar " << tot_a_cobrar << std::endl;
    }

    for(int i = 0; i < CANT_EMP; i ++){
        if(max_sueldo < sueldos[i].sueldo){
            max_sueldo = sueldos[i].sueldo;
            max_cat = sueldos[i].categoria;
        }
    }

    std::cout << "La categoria " << max_cat << " percibio el sueldo de mayor monto." << std::endl;
}