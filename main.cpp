/*
    Integrantes
    ? Cristian Aragón Salazar
*/

#include <iostream>

using namespace std;

int elegir(){
    // Menú de opciones
    int eleccion;
    cout << "Elige el tipo de numeros a usar:" << endl;
    cout << "1. Consecutivos" << endl;
    cout << "2. Pares" << endl;
    cout << "3. Impares" << endl;
    cout << "4. Multiplos de algun numero" << endl;
    cin >> eleccion;
    return eleccion;
}

void cuadroImpar(int orden, int eleccion, int multiplo){
    // Declaración del cuadro vacío
    int cuadro[orden][orden] = {0};
    // Inicialización en 0
    for(int i = 0; i < orden; i++)
        for(int j = 0; j < orden; j++)
            cuadro[i][j] = 0;
    int fila, columna, num, aux;
    // Switch con casos del menú
    switch (eleccion) {
        // Consecutivos
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
        // Pares
        case 2:
            fila = 0;
            columna = orden / 2;
            aux = 0;
            while (num < (orden*orden)*2) {
                num = (2*aux)+2;
                aux++;
                cuadro[fila][columna] = num;
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
        // Impares
        case 3:
            fila = 0;
            columna = orden / 2;
            aux = 0;
            while (num < ((orden*orden)*2)-1) {
                num = ((2*aux)-1)+2;
                aux++;
                cuadro[fila][columna] = num;
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
        // Múltiplos de X
        case 4:
            fila = 0;
            columna = orden / 2;
            num = multiplo;
            while (num <= (orden*orden)*multiplo) {
                cuadro[fila][columna] = num;
                num += multiplo;
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
        default:
            break;
    }
    // Suma por filas
    int sumaFila = 0;
    int sumaColumna = 0;
    int sumaDiagonal = 0;
    int aux1;
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            sumaFila += cuadro[i][j];
            cout << "\t" << cuadro[i][j] << "\t";
            if(j == i) sumaDiagonal += cuadro[i][j];
        }
        cout << "SumaF: " << sumaFila;
        sumaFila = 0;
        cout << endl;
    }
    aux1 = sumaDiagonal;
    sumaDiagonal = 0;
    // Suma diagonales
    for(int i = 0; i < orden; i++){
        for(int j = orden-1; j >= 0; j--){
            if(j == i) sumaDiagonal += cuadro[i][j];
        }
    }
    cout << "SumaD: " << sumaDiagonal << " ";
    // Suma por columnas
    for(int i = 0; i < orden; i++) {
        for(int j = 0; j < orden; j++) {
            sumaColumna += cuadro[j][i];
        }
        cout << "SumaC: " << sumaColumna << " ";
        sumaColumna = 0;
    }
    cout << "SumaD: " << aux1;
}

void cuadroPar(int orden){
    // Se necesitan algoritmos más complejos
}

int main() {
    // Main
    int n;
    int multiplo = 0;
    // Ingreso de orden
    cout << "Bienvenid@ al generador de cuadros magicos de Cristian" << endl;
    cout << "Ingresa el numero de elementos del cuadro magico" << endl;
    cin >> n;
    // En caso de haber elegido mal en el menú regresa
    error:
    int elegido = elegir();
    if(elegido < 1 || elegido > 4) goto error;
    if(elegido == 4){
        // Múltiplo en caso de opción 4
        cout << "Ingresa el multiplo que desees" << endl;
        cin >> multiplo;
    }
    if(n%2 != 0){
        // Cuadro impar
        cuadroImpar(n, elegido, multiplo);
    } else{
        // Cuadro impar
        cout << "No se puede generar el cuadro magico de ese orden, falta implementacion." << endl;
    }
}