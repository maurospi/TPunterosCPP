#include <iostream>

double** crearMatriz(int filas, int columnas) {
    double** arr = new double*[filas];

    int i = 0;
    while (i < filas) {
        arr[i] = new double[columnas];
        i++;
    }

    return arr;
}

void liberarMatriz(double** arr, int filas) {
    int i = 0;
    while (i < filas) {
        delete[] arr[i];
        i++;
    }
    delete[] arr;
}

void llenarMatriz(double** arr, int filas, int columnas) {
    int i = 0;
    while (i < filas) {
        int j = 0;
        while (j < columnas) {
            std::cout << "  arr[" << i << "][" << j << "] = ";
            std::cin >> arr[i][j];
            j++;
        }
        i++;
    }
}

void imprimirMatriz(double** arr, int filas, int columnas) {
    int i = 0;
    while (i < filas) {
        std::cout << "  [ ";
        int j = 0;
        while (j < columnas) {
            std::cout << arr[i][j] << " ";
            j++;
        }
        std::cout << "]\n";
        i++;
    }
}

void sumaFilas(double** arr, int filas, int columnas, double* sumas) {
    int i = 0;
    while (i < filas) {
        sumas[i] = 0;
        int j = 0;
        while (j < columnas) {
            sumas[i] = sumas[i] + arr[i][j];
            j++;
        }
        i++;
    }
}


double mayorElemento(double** arr, int filas, int columnas) {
    double mayor = arr[0][0];

    int i = 0;
    while (i < filas) {
        int j = 0;
        while (j < columnas) {
            if (arr[i][j] > mayor) {
                mayor = arr[i][j];
            }
            j++;
        }
        i++;
    }

    return mayor;
}

double** transponerMatriz(double** arr, int filas, int columnas) {
    double** transpuesta = crearMatriz(columnas, filas);

    int i = 0;
    while (i < filas) {
        int j = 0;
        while (j < columnas) {
            transpuesta[j][i] = arr[i][j];
            j++;
        }
        i++;
    }

    return transpuesta;
}

void ejercicio1() {
    std::cout << "\nMatriz dinamica\n";

    int n, m;
    std::cout << "Cuantas filas? ";
    std::cin >> n;
    std::cout << "Cuantas columnas? ";
    std::cin >> m;

    double** arr = crearMatriz(n, m);
    llenarMatriz(arr, n, m);

    std::cout << "\nMatriz ingresada:\n";
    imprimirMatriz(arr, n, m);

    double* sumas = new double[n];
    sumaFilas(arr, n, m, sumas);

    std::cout << "\nSuma de cada fila:\n";
    int i = 0;
    while (i < n) {
        std::cout << "Fila " << i << ": " << sumas[i] << "\n";
        i++;
    }
    delete[] sumas;

    double mayor = mayorElemento(arr, n, m);
    std::cout << "\nEl mayor elemento es: " << mayor << "\n";

    double** trans = transponerMatriz(arr, n, m);
    std::cout << "\nMatriz transpuesta:\n";
    imprimirMatriz(trans, m, n);

    liberarMatriz(arr, n);
    liberarMatriz(trans, m);
}

double cuadrado(double x) {
    return x * x;
}

double doble(double x) {
    return x * 2;
}

double inverso(double x) {
    if (x == 0) {
        std::cout << "Error: no se puede calcular el inverso de 0\n";
        return 0;
    } else {
        return 1.0 / x;
    }
}

void aplicarFuncion(double* arreglo, int tam, double (*funcion)(double)) {
    int i = 0;
    while (i < tam) {
        arreglo[i] = funcion(arreglo[i]);
        i++;
    }
}

void imprimirArreglo(double* arreglo, int tam) {
    std::cout << "  [ ";
    int i = 0;
    while (i < tam) {
        std::cout << arreglo[i] << " ";
        i++;
    }
    std::cout << "]\n";
}

void ejercicio2() {
    std::cout << "\nPunteros a funcion\n";

    int tam;
    std::cout << "Tamano del arreglo: ";
    std::cin >> tam;

    double* arreglo = new double[tam];

    int i = 0;
    while (i < tam) {
        std::cout << "arreglo[" << i << "] = ";
        std::cin >> arreglo[i];
        i++;
    }

    std::cout << "\nArreglo original:\n";
    imprimirArreglo(arreglo, tam);

    std::cout << "\nQue funcion quieres aplicar?\n";
    std::cout << "  1. Cuadrado (x * x)\n";
    std::cout << "  2. Doble    (x * 2)\n";
    std::cout << "  3. Inverso  (1 / x)\n";
    std::cout << "Opcion: ";

    int opcion;
    std::cin >> opcion;

    double (*funcionElegida)(double);

    if (opcion == 1) {
        funcionElegida = cuadrado;
    } else if (opcion == 2) {
        funcionElegida = doble;
    } else if (opcion == 3) {
        funcionElegida = inverso;
    } else {
        std::cout << "Opcion invalida.\n";
        delete[] arreglo;
        return;
    }

    aplicarFuncion(arreglo, tam, funcionElegida);

    std::cout << "\nArreglo despues de aplicar la funcion:\n";
    imprimirArreglo(arreglo, tam);

    delete[] arreglo;
}

double transformarYAcumular(double* arreglo, int tam, double (*transformar)(double), double (*acumular)(double, double), double valorInicial){
    double resultado = valorInicial;

    int i = 0;
    while (i < tam) {
        double transformado = transformar(arreglo[i]);
        resultado = acumular(resultado, transformado);
        i++;
    }

    return resultado;
}

double duplicar(double x) {
    return x * 2;
}

double sumar(double acumulado, double x) {
    return acumulado + x;
}

void ejercicio3() {
    std::cout << "\nLambdas + composiciÃ³n\n";

    int tam;
    std::cout << "Tamano del arreglo: ";
    std::cin >> tam;

    double* arreglo = new double[tam];

    int i = 0;
    while (i < tam) {
        std::cout << "arreglo[" << i << "] = ";
        std::cin >> arreglo[i];
        i++;
    }

    double resultado = transformarYAcumular(arreglo, tam, duplicar, sumar, 0);

    std::cout << "\nTransformacion: cada elemento x se convierte en x*2\n";
    std::cout << "Acumulacion: se suman todos los transformados\n";
    std::cout << "Resultado final: " << resultado << "\n";

    delete[] arreglo;
}

double paso_x2(double x) { return x * 2; }
double paso_mas3(double x) { return x + 3; }
double paso_cuad (double x) { return x * x; }
double paso_mitad(double x) { return x / 2; }
double paso_menos1(double x){ return x - 1; }

void ejercicio4() {
    std::cout << "\nTransformaciones encadenadas\n";

    int tam;
    std::cout << "Tamano del arreglo: ";
    std::cin >> tam;

    double* arreglo = new double[tam];

    int i = 0;
    while (i < tam) {
        std::cout << "arreglo[" << i << "] = ";
        std::cin >> arreglo[i];
        i++;
    }

    double (*step[10])(double);
    int cantidadPasos = 0;

    std::cout << "\nArma tu step (maximo 10 pasos).\n";
    std::cout << "Funciones disponibles:\n";
    std::cout << "  1. x * 2\n";
    std::cout << "  2. x + 3\n";
    std::cout << "  3. x * x  (cuadrado)\n";
    std::cout << "  4. x / 2\n";
    std::cout << "  5. x - 1\n";
    std::cout << "  0. Terminar y ejecutar\n";

    while (cantidadPasos < 10) {
        std::cout << "Agrega paso " << (cantidadPasos + 1) << " (0 para terminar): ";
        int eleccion;
        std::cin >> eleccion;

        if (eleccion == 0) {
            break;
        } else if (eleccion == 1) {
            step[cantidadPasos] = paso_x2;
        } else if (eleccion == 2) {
            step[cantidadPasos] = paso_mas3;
        } else if (eleccion == 3) {
            step[cantidadPasos] = paso_cuad;
        } else if (eleccion == 4) {
            step[cantidadPasos] = paso_mitad;
        } else if (eleccion == 5) {
            step[cantidadPasos] = paso_menos1;
        } else {
            std::cout << "Opcion invalida, intenta de nuevo.\n";
            continue;
        }

        cantidadPasos++;
    }

    if (cantidadPasos == 0) {
        std::cout << "No agregaste ningun paso.\n";
        delete[] arreglo;
        return;
    }

    std::cout << "\nResultados:\n";
    int idx = 0;
    while (idx < tam) {
        double valor = arreglo[idx];
        std::cout << "arreglo[" << idx << "] = " << valor << "\n";

        int paso = 0;
        while (paso < cantidadPasos) {
            double antes = valor;
            valor = step[paso](valor);
            std::cout << "paso " << (paso + 1) << ": " << antes << " -> " << valor << "\n";
            paso++;
        }

        std::cout << "Resultado final: " << valor << "\n\n";
        idx++;
    }

    delete[] arreglo;
}

void menu() {
    std::cout << "\n=== MENU ===\n";
    std::cout << "1. Matriz dinamica\n";
    std::cout << "2. Punteros a funcion\n";
    std::cout << "3. Lambdas + composicion\n";
    std::cout << "4. Step encadenado\n";
    std::cout << "0. Salir\n";
    std::cout << "Opcion: ";
}

int main() {
    int opcion;
    menu();
    do {
        std::cin >> opcion;

        if (opcion == 1) {
            ejercicio1();
            menu();
        } else if (opcion == 2) {
            ejercicio2();
            menu();
        } else if (opcion == 3) {
            ejercicio3();
            menu();
        } else if (opcion == 4) {
            ejercicio4();
            menu();
        } else if (opcion == 0) {
            std::cout << "Hasta luego!\n";
        } else {
            std::cout << "Opcion no valida.\n";
        }

    } while (opcion != 0);

    return 0;
}
