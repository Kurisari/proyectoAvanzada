 ## Magic Squares

This code generates magic squares of odd order. A magic square is a square matrix of numbers such that the sum of each row, column, and diagonal is the same.

The code is written in C++ and uses the following libraries:

* iostream: for input and output
* stdlib.h: for the `exit()` function

The code is divided into the following functions:

* `elegir()`: This function displays a menu of options for the user to choose from. The options are:
    * 1. Consecutivos: Generates a magic square with consecutive numbers.
    * 2. Pares: Generates a magic square with even numbers.
    * 3. Impares: Generates a magic square with odd numbers.
    * 4. Multiplos de algun numero: Generates a magic square with multiples of a given number.
* `cuadroImpar()`: This function generates a magic square of odd order. It takes the following parameters:
    * `orden`: The order of the magic square.
    * `eleccion`: The option chosen by the user.
    * `multiplo`: The multiple to use if the user chose option 4.
* `cuadroPar()`: This function generates a magic square of even order. It is not yet implemented.
* `main()`: The main function of the program. It calls the `elegir()` function to get the user's choice, and then calls the `cuadroImpar()` or `cuadroPar()` function to generate the magic square.

To use the program, follow these steps:

1. Clone the repository.
2. Open the `main.cpp` file in a text editor.
3. Compile the code using the following command:

```
g++ main.cpp -o magic_squares
```

4. Run the program using the following command:

```
./magic_squares
```

5. Enter the order of the magic square.
6. Choose an option from the menu.
7. If you chose option 4, enter the multiple to use.
8. The program will display the magic square.

Here is a sample output of the program:

```
Bienvenid@ al generador de cuadros magicos de Cristian
Ingresa el numero de elementos del cuadro magico
5
Elige el tipo de numeros a usar:
1. Consecutivos
2.
```
## Authors

- [@Kurisari](https://www.github.com/kurisari)


## Feedback

Si tienes alguna retroalimentación puedes hacerla a crisarag8.sal@gmail.com


## License

[MIT](https://choosealicense.com/licenses/mit/)

