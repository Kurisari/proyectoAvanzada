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

void cuadroImpar(int orden, int eleccion){
    int cuadro[orden][orden] = {0};
    for(int i = 0; i < orden; i++)
        for(int j = 0; j < orden; j++)
            cuadro[i][j] = 0;
    int fila, columna, num, aux;
    switch (eleccion) {
        case 1:
            fila = 0;
            columna = orden / 2;
            num = 1;
            while (num <= orden*orden) {
                cuadro[fila][columna] = num;
                num++;
                // Con el algoritmo siamés calculamos la siguiente fila y columna
                int siguienteFila = (fila - 1 + orden) % orden;
                int siguienteColumna = (columna + 1) % orden;
                if (cuadro[siguienteFila][siguienteColumna] != 0) {
                    fila = (fila + 1) % orden;
                } else {
                    fila = siguienteFila;
                    columna = siguienteColumna;
                }
            }
            break;
        case 2:
            fila = 0;
            columna = orden / 2;
            aux = 0;
            while (num <= (orden*orden)*2) {
                cuadro[fila][columna] = num;
                num = (2*aux)+2;
                aux++;
                // Con el algoritmo siamés calculamos la siguiente fila y columna
                int siguienteFila = (fila - 1 + orden) % orden;
                int siguienteColumna = (columna + 1) % orden;
                if (cuadro[siguienteFila][siguienteColumna] != 0) {
                    fila = (fila + 1) % orden;
                } else {
                    fila = siguienteFila;
                    columna = siguienteColumna;
                }
            }
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        default:
            break;
    }
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            cout << cuadro[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Bienvenid@ al generador de cuadros magicos de Cristian" << endl;
    cout << "Ingresa el numero de elementos del cuadro magico" << endl;
    cin >> n;
    error:
    int elegido = elegir();
    if(elegido < 1 || elegido > 4) goto error;
    if(n%2 != 0){
        cuadroImpar(n, elegido);
    }
}