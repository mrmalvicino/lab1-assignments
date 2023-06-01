/*
EJ. 4
Se dispone de las ventas de un negocio durante el mes pasado.
Por cada venta se registró el número de venta, el número de día y el importe de la venta.
El fin de la carga de datos se indica con número de venta igual a 0.
Se pide calcular e informar:
Por cada día, la recaudación total (sólo de aquellos días que tuvieron recaudación).
El número de día que más se recaudó en total y cuál fue la recaudación máxima.
*/

#include <iostream>
using namespace std;

int main(){
    int sale_number;                        // Número de venta
    int day;                                // Número de día
    float amount;                           // Importe de la venta
    int const DAYS_IN_MONTH = 3;           // Cantidad de días del mes pasado
    float sales_vec[DAYS_IN_MONTH] = {};    // Vector de recaudaciones de cada día del mes
    float max = 0;                          // Máxima recaudación de un día
    int max_day;                            // Día de máxima recaudación

    cout << "Número de venta:" << endl;
    cin >> sale_number;

    while(sale_number != 0){
        cout << "Número de día:" << endl;
        cin >> day;

        cout << "Importe de la venta:" << endl;
        cin >> amount;

        sales_vec[day - 1] = sales_vec[day - 1] + amount;

        cout << "Número de venta:" << endl;
        cin >> sale_number;
    }

    for(int i = 0; i < DAYS_IN_MONTH; i++){
        if(sales_vec[i] != 0){
            cout << "Recaudación del día " << i + 1 << " : " << sales_vec[i] << endl;
        }
        if(max < sales_vec[i]){
            max = sales_vec[i];
            max_day = i + 1;
        }
    }

    cout << "El día " << max_day << " se recaudó el máximo: $" << max << endl;
}