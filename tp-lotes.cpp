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
        std::cout << "Insertar numero de empleado:" << std::endl;
        std::cin >> num_de_emp;
        std::cout << "Insertar categoria:" << std::endl;
        std::cin >> categoria;

        if(categoria != 0){
            std::cout << "Insertar antiguedad:" << std::endl;
            std::cin >> antiguedad;
            lote_de_carga[i].num_de_emp = num_de_emp;
            lote_de_carga[i].categoria = categoria;
            lote_de_carga[i].antiguedad = antiguedad;
        } else{
            i = CANT_EMP;
        }
    }
}

void procesar_datos(int lote_de_proceso[][200][31], int const CANT_EMP){
    int const MAX_LEGAJO = 999;
    int dia;
    int num_de_emp;
    int horas_trabajadas;
    int jornal_cobrado;
    int j = 0;
    int indices_de_legajos[MAX_LEGAJO - 1] = {}; // Vector que almacena los indices de cada legajo siendo 1 el menor indice. De ser nulo, el legajo no fue cargado.

    std::cout << "Insertar dia:" << std::endl;
    std::cin >> dia;
    std::cout << "Insertar numero de empleado:" << std::endl;
    std::cin >> num_de_emp;

    indices_de_legajos[num_de_emp - 1] = j + 1;

    while(num_de_emp != 0){
        std::cout << "Insertar horas trabajadas:" << std::endl;
        std::cin >> horas_trabajadas;
        std::cout << "Insertar jornal cobrado:" << std::endl;
        std::cin >> jornal_cobrado;

        j = indices_de_legajos[num_de_emp - 1] - 1;

        lote_de_proceso[0][j][dia - 1] = num_de_emp;
        lote_de_proceso[1][j][dia - 1] = horas_trabajadas;
        lote_de_proceso[2][j][dia - 1] = jornal_cobrado;

        std::cout << "Insertar dia:" << std::endl;
        std::cin >> dia;
        std::cout << "Insertar numero de empleado:" << std::endl;
        std::cin >> num_de_emp;

        if(indices_de_legajos[num_de_emp - 1] == 0){
            j ++;
            indices_de_legajos[num_de_emp - 1] = j + 1;
        }
    }
}

int main(){
    int const CANT_EMP = 200; // Arbitrario
    int const CANT_DIAS = 31; // Arbitrario
    int const CANT_CATS = 20; // Arbitrario
    int const PREMIO = 200; // Usado en punto B
    int max_horas = 0; // Usado en punto A
    int max_dia; // Usado en punto A
    int cant_jornadas = 0; // Usado en punto B
    int max_acu_sueldo = 0; // Usado en punto C
    int max_cat; // Usado en punto C
    EMPLEADO lote_de_carga[CANT_EMP] = {}; // Vector que tiene en cada componente un dato de tipo EMPLEADO.
    SUELDO sueldos[CANT_EMP] = {}; // Vector que tiene en cada componente un dato de tipo SUELDO.
    int lote_de_proceso[3][CANT_EMP][CANT_DIAS] = {}; // Matriz que tiene por columnas los empleados, por filas el legajo, las horas y el sueldo y en la tercer dimension los dias del mes.

    cargar_datos(lote_de_carga, CANT_EMP);
    procesar_datos(lote_de_proceso, CANT_EMP);

    for(int j = 0; j < CANT_EMP; j ++){
        for(int k = 0; k < CANT_DIAS; k ++){
            if(max_horas < lote_de_proceso[1][j][k]){ // Punto A
                max_horas = lote_de_proceso[1][j][k];
                max_dia = k + 1;
            }
            
            if(lote_de_proceso[0][j][k] != 0){
                sueldos[j].num_de_emp = lote_de_proceso[0][j][k]; // Puntos A, B y C
                sueldos[j].sueldo += lote_de_proceso[2][j][k]; // Punto B
                cant_jornadas ++; // Punto B
            }
        }

        if(20 < cant_jornadas){ // Punto B
            sueldos[j].sueldo += PREMIO;
        }

        if(sueldos[j].sueldo != 0){ // Punto B
            std::cout << "EMPLEADO NUMERO " << sueldos[j].num_de_emp << std::endl;
            std::cout << "- Jornada mas larga: dia " << max_dia << " (" << max_horas << " h)" << std::endl;
            std::cout << "- Sueldo percibido: $" << sueldos[j].sueldo << std::endl;
        }

        cant_jornadas = 0; // Punto B
    }

    for(int i = 0; CANT_EMP; i ++){
        if(sueldos[i].num_de_emp == lote_de_carga[i].num_de_emp){
            sueldos[i].categoria == lote_de_carga[i].categoria;
        }
    }

    std::cout << "Categoria que acumulo mas sueldo: " << "max_cat" << " ($" << max_acu_sueldo << ")" << std::endl;
}

/*
COMPILAR Y CORRER PRUEBA DE ESCRITORIO:
g++ -o ./bin/tp-lotes tp-lotes.cpp
./bin/tp-lotes < ./bin/test.txt

COMPILAR Y EJECUTAR:
g++ -o ./bin/tp-lotes tp-lotes.cpp
./bin/tp-lotes
*/