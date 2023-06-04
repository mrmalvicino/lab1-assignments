/*
EJ. 8
Hacer una función que reciba un un vector de carácteres y devuelva la cantidad de caracteres del mismo hasta el '\0'.
Asumir que el vector dispone de un '\0'.

No confundir un string con un vector de cadenas de caracteres.
Los mismos se declaran y se utilizan de maneras distintas:

Vector de caracteres:
char mi_vector_caracteres[100];

String o cadena de caracteres:
string mi_cadena_caracteres;
*/

#include <iostream>

int char_arr_length(char arr[]){
    int i = 0;

    while(arr[i] != '\0'){
        i++;
    }

    return i;
}

int main(){
    char arr_1[13] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'};
    char arr_2[] = "Hello world!";
    std::cout << char_arr_length(arr_1) << std::endl;
    std::cout << char_arr_length(arr_2) << std::endl;
}

/*
Compile and run in terminal:
./bin/tp7-ej8
*/