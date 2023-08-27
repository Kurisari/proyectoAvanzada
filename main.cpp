/*
    Integrantes
    ? Cristian Aragón Salazar
*/

#include <iostream>

using namespace std;

int elegir(){
    int eleccion;
    cout << "Elige el tipo de numeros a usar:" << endl;
    cout << "1. Consecutivos" << endl;
    cout << "2. Pares" << endl;
    cout << "3. Impares" << endl;
    cout << "4. Multiplos de algun numero" << endl;
    cin >> eleccion;
    return eleccion;
}

void cuadroImpar(int orden){
    int cuadro[orden][orden] = {0};
    for(int i = 0; i < orden; i++)
        for(int j = 0; j < orden; j++)
            cuadro[i][j] = 0;
    int fila = 0;
    int columna = orden / 2;
    int num = 1;
    while (num <= orden * orden) {
        cuadro[fila][columna] = num;
        num++;
        // Con el algoritmo siamece calculamos la siguiente fila y columna
        int siguienteFila = (fila - 1 + orden) % orden;
        int siguienteColumna = (columna + 1) % orden;
        if (cuadro[siguienteFila][siguienteColumna] != 0) {
            fila = (fila + 1) % orden;
        } else {
            fila = siguienteFila;
            columna = siguienteColumna;
        }
    }
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            cout << cuadro[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Bienvenid@ al generador de cuadros magicos de Cristian" << endl;
    cout << "Ingresa el numero de elementos del cuadro magico" << endl;
    cin >> n;
    int elegido = elegir();
    if(n%2 != 0){
        cuadroImpar(n);
    }
}