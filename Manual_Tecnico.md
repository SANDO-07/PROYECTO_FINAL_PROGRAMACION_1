# Manual de tecnico:

Para realizar el programa en el encabezado se utilizaron las siguientes librerias para que pudieran funcionar: 

/*Uitlizamos las siguientes librerias*/

#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

/* * iostream: Proporciona las funciones de entrada y salida estándar de C++, como cout y cin, para interactuar con la consola.

* windows.h: Proporciona funciones y estructuras de datos para interactuar con el sistema operativo Windows, incluyendo manejo de ventanas, entrada y salida de consola, entre otros.

* cmath: Contiene funciones matemáticas estándar, como sqrt, sin, cos, pow, entre otras, para realizar cálculos matemáticos.

* conio.h: Proporciona funciones para leer caracteres desde la consola y controlar la entrada y salida de caracteres. Es comúnmente utilizada para funciones como getch() para leer una tecla sin necesidad de presionar Enter.

* vector: Define la clase de contenedor vector, que es una matriz dinámica que puede crecer y encogerse automáticamente según sea necesario. Es útil para almacenar colecciones de elementos de tamaño variable.

* string: Proporciona una clase de cadena de caracteres (string) y funciones relacionadas para manipular y trabajar con cadenas de caracteres de manera eficiente.

* fstream: Proporciona clases y funciones para leer y escribir archivos en disco. Permite la manipulación de archivos de texto y binarios mediante flujos de entrada (ifstream) y flujos de salida (ofstream).

* sstream: Define las clases stringstream que permiten la manipulación de cadenas de caracteres como si fueran flujos de entrada y salida. Es útil para convertir entre diferentes tipos de datos y manipular cadenas de caracteres. */

/*### using namespace std;
se utiliza para indicar al compilador que utilice el espacio de nombres estándar std. */
using namespace std;

/* Colocamos el Ancho de Pantalla*/
const int Ancho_pantalla = 50;
/* Colocamos el Alto de Pantalla */
const int Alto_pantalla = 25;
/* Colocamos el Color de la figura 15 = Color Blanco */
int Color_De_Figura = 15;
/* Colocamos el caracter para nuestro puntero*/
char Puntero = '+';
/*Colocamos el nuevo Caracter*/
char NuevoCaracter = '*';
/*Declaramos una cadena para almacenar la ruta de nuestro archivo*/
string fullPath;

/*Coordenada en X para inciar en el centro de la pantalla*/
int CoordenadaX = Ancho_pantalla / 2;
/*Coordenada en Y para inciar en el centro de la pantalla*/
int CoordenadaY = Alto_pantalla / 2;

/*Utilizamos nuestras estructuras para poder almacenar nuestras variables*/
/*Colocamos el ID ya que esto nos va a servir para guardar y cargar las figuras*/
/*colocamos como entero: base, lado,ancho, alto segun el requerimiento de la figura*/
/*Colocamos como Char la orientacion para que se puedan dibujar las figuras*/
/*solicitamos las coordenadas en X & en Y*/
/*Pedimos el color de la figura*/
/*Colocamos como char el nuevo Caracter*/
/*Estos datos dependen de la figura la cual se va a dibujar en pantalla*/
//Estructuras
struct modeloTriangulo {
    int id = 1;
    int base;
    char orientacion;
    COORD coord;
    int Color;
    char NuevoCaracter;
};
struct modeloCuadrado {
    int id = 2;
    int lado;
    char orientacion;
    COORD coord;
    int Color;
    char NuevoCaracter;
};
struct modeloRectangulo {
    int id = 3;
    int ancho;
    int alto;
    char orientacion;
    COORD coord;
    int Color;
    char NuevoCaracter;
};
struct modeloCirculo {
    int id = 4;
    int radio;
    COORD coord;
    int Color;
    char NuevoCaracter;
};
struct modeloLinea {
    int id = 5;
    int longitud;
    char orientacion;
    COORD coord;
    int Color;
    char NuevoCaracter;
};
struct modeloRombo {
    int id = 6;
    int lado;
    char orientacion;
    COORD coord;
    int Color;
    char NuevoCaracter;
};
struct modeloHexagono {
    int id = 7;
    int lado;
    COORD coord;
    int Color;
    char NuevoCaracter;

};

/* Utilizamos vectores los cuales contendran nuestras figuras*/
//VECTORES UTILIZADOS
vector<modeloHexagono> hexagonos;
vector<modeloTriangulo> triangulos;
vector<modeloCuadrado> cuadrados;
vector<modeloRectangulo> rectangulos;
vector<modeloCirculo> circulos;
vector<modeloLinea> lineas;
vector<modeloRombo> rombos;

/*Creamos un un bucle para mantener el programa en ejecucion hasta que el usuario decida salir*/
bool quit = false;

/*Diseñamos la funcion gotoxy para mover el cursor de la consola a una posicion especifica y luego imprimir un 
caracter en esa posicion*/
// FORMAS EN QUE SE DIBUJAN LAS FIGURAS
void gotoxy(int x, int y, char Puntero, char NuevoCaracter) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 15);
    cout << NuevoCaracter;
}
/*Forma en la que se dibuja el triangulo segun sus requerimientos*/
void dibujar_triangulo(int base, int x, int y,int Color, char NuevoCaracter ,char orientacion) {
    int altura = (base + 1) / 2;

    switch (orientacion) {
        case 'a': {
            int startX = (x - (altura - 1) + Ancho_pantalla) % Ancho_pantalla;
            for (int i = 0; i < altura; ++i) {
                for (int j = 0; j < 2 * altura - 1; ++j) {
                    if ((j == altura - i - 1) || (j == altura + i - 1) || (i == altura - 1)) {
                        COORD coord;
                        coord.X = (startX + j + Ancho_pantalla) % Ancho_pantalla;
                        coord.Y = (y + i + Alto_pantalla) % Alto_pantalla;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                        cout << NuevoCaracter;
                    }
                }
            }
            break;
        }
        case 'b': {
    int startX = (x - (altura - 1) + Ancho_pantalla) % Ancho_pantalla;
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < 2 * altura - 1; ++j) {
            if ((j == altura - i - 1) || (j == altura + i - 1) || (i == altura - 1)) {
                COORD coord;
                coord.X = (startX + j + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (y + (altura - 1 - i) + Alto_pantalla) % Alto_pantalla;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                cout << NuevoCaracter;
            }
        }
    }
    break;
}

        case 'd': {
            int startY = (y - (altura - 1) + Alto_pantalla) % Alto_pantalla;
            for (int i = 0; i < altura; ++i) {
                for (int j = 0; j < 2 * altura - 1; ++j) {
                    if ((j == altura - i - 1) || (j == altura + i - 1) || (i == altura - 1)) {
                        COORD coord;
                        coord.X = (x + i + Ancho_pantalla) % Ancho_pantalla;
                        coord.Y = (startY + j + Alto_pantalla) % Alto_pantalla;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                        cout << NuevoCaracter;
                    }
                }
            }
            break;
        }
        case 'i': {
            int startY = (y - (altura - 1) + Alto_pantalla) % Alto_pantalla;
            for (int i = 0; i < altura; ++i) {
                for (int j = 0; j < 2 * altura - 1; ++j) {
                    if ((j == altura - i - 1) || (j == altura + i - 1) || (i == altura - 1)) {
                        COORD coord;
                        coord.X = (x - i + Ancho_pantalla) % Ancho_pantalla;
                        coord.Y = (startY + j + Alto_pantalla) % Alto_pantalla;
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                        cout << NuevoCaracter;
                    }
                }
            }
            break;
        }
    }
}

/*Forma en la que se dibuja el cuadrado con  sus requerimientos*/
void dibujar_cuadrado(modeloCuadrado cuadrado, int Color, char NuevoCaracter , char orientecion) {
    int size = cuadrado.lado;
    int x = (cuadrado.coord.X + Ancho_pantalla) % Ancho_pantalla;
    int y = (cuadrado.coord.Y + Alto_pantalla) % Alto_pantalla;
    char orientacion = cuadrado.orientacion;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                COORD coord;

                switch (orientacion) {
                    case 'a':
                        coord.X = (x + j + Ancho_pantalla) % Ancho_pantalla;
                        coord.Y = (y - i + Alto_pantalla) % Alto_pantalla;
                        break;
                    case 'b':
                        coord.X = (x + j + Ancho_pantalla) % Ancho_pantalla;
                        coord.Y = (y + i + Alto_pantalla) % Alto_pantalla;
                        break;
                    case 'd':
                        coord.X = (x + i + Ancho_pantalla) % Ancho_pantalla;
                        coord.Y = (y + j + Alto_pantalla) % Alto_pantalla;
                        break;
                    case 'i':
                        coord.X = (x - i + Ancho_pantalla) % Ancho_pantalla;
                        coord.Y = (y + j + Alto_pantalla) % Alto_pantalla;
                        break;
                }

                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                cout << NuevoCaracter;
            }
        }
    }
}
/*Forma en la que se dibuja el rectangulo con  sus requerimientos*/
void dibujar_rectangulo(int ancho, int altura, int x, int y, int Color, char NuevoCaracter ,char orientacion) {
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < ancho; ++j) {
            if (i == 0 || i == altura - 1 || j == 0 || j == ancho - 1) {
                COORD coord;
                coord.X = (x + j + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (y + i + Alto_pantalla) % Alto_pantalla;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
                cout << NuevoCaracter;
            }
        }
    }
}
/*Forma en la que se dibuja el circulo con  sus requerimientos*/
void dibujar_circulo(int x, int y, int radio,int Color, char c) {
    COORD coord;
    for (int i = -radio; i <= radio; ++i) {
        for (int j = -radio; j <= radio; ++j) {
            if (i * i + j * j <= radio * radio + radio / 2 && i * i + j * j >= radio * radio - radio / 2) {
                coord.X = (x + j + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (y + i + Alto_pantalla) % Alto_pantalla;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                cout << c;
            }
        }
    }
}
/*Forma en la que se dibuja la linea con  sus requerimientos*/
void dibujar_linea(modeloLinea linea, int Color, char NuevoCaracter) {
    COORD coord = linea.coord;
    int longitud = linea.longitud;
    char orientacion = linea.orientacion;

    for (int i = 0; i < longitud; ++i) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
        cout << NuevoCaracter;

        switch (orientacion) {
            case 'a':
                coord.Y = (coord.Y - 1 + Alto_pantalla) % Alto_pantalla;
                break;
            case 'b':
                coord.Y = (coord.Y + 1 + Alto_pantalla) % Alto_pantalla;
                break;
            case 'd':
                coord.X = (coord.X + 1 + Ancho_pantalla) % Ancho_pantalla;
                break;
            case 'i':
                coord.X = (coord.X - 1 + Ancho_pantalla) % Ancho_pantalla;
                break;
            case 'q':
                coord.X = (coord.X - 1 + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (coord.Y - 1 + Alto_pantalla) % Alto_pantalla;
                break;
            case 'e':
                coord.X = (coord.X + 1 + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (coord.Y - 1 + Alto_pantalla) % Alto_pantalla;
                break;
            case 'z':
                coord.X = (coord.X - 1 + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (coord.Y + 1 + Alto_pantalla) % Alto_pantalla;
                break;
            case 'c':
                coord.X = (coord.X + 1 + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (coord.Y + 1 + Alto_pantalla) % Alto_pantalla;
                break;
        }
    }
}
/*Forma en la que se dibuja el rombo con  sus requerimientos*/
void dibujar_rombo(modeloRombo rombo, int Color, char NuevoCaracter) {
    int lado = rombo.lado;
    int x = (rombo.coord.X + Ancho_pantalla) % Ancho_pantalla;
    int y = (rombo.coord.Y + Alto_pantalla) % Alto_pantalla;
    char orientacion = rombo.orientacion;

    if (orientacion == 'a') {
        for (int i = 0; i < lado; ++i) {
            for (int j = 0; j < lado; ++j) {
                if (i + j == lado / 2 || j - i == lado / 2 || i - j == lado / 2 || i + j == 3 * (lado / 2) ||
                    (lado % 2 == 0 && (i + j == lado / 2 - 1 || j - i == lado / 2 - 1 || i - j == lado / 2 - 1 || i + j == 3 * (lado / 2) + 1)) &&
                    (i + j == lado / 2 || j - i == -lado / 2 || i - j == -lado / 2 || i + j == 3 * (lado / 2))) {
                    COORD coord;
                    coord.X = (x + j + Ancho_pantalla) % Ancho_pantalla;
                    coord.Y = (y + i + Alto_pantalla) % Alto_pantalla;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                    cout << NuevoCaracter;
                }
            }
        }
    } else if (orientacion == 'b') {
        for (int i = lado - 1; i >= 0; --i) {
            for (int j = 0; j < lado; ++j) {
                if (i + j == lado / 2 || j - i == lado / 2 || i - j == lado / 2 || i + j == 3 * (lado / 2) ||
                    (lado % 2 == 0 && (i + j == lado / 2 - 1 || j - i == lado / 2 - 1 || i - j == lado / 2 - 1 || i + j == 3 * (lado / 2) + 1)) &&
                    (i + j == lado / 2 || j - i == -lado / 2 || i - j == -lado / 2 || i + j == 3 * (lado / 2))) {
                    COORD coord;
                    coord.X = (x + j + Ancho_pantalla) % Ancho_pantalla;
                    coord.Y = (y + i + Alto_pantalla) % Alto_pantalla;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), Color);
                    cout << NuevoCaracter;
                }
            }
        }
    }
}
/*Forma en la que se dibuja el Hexagono con  sus requerimientos*/
void dibujar_hexagono(modeloHexagono hexagono, int Color, char NuevoCaracter) {
    int lado = hexagono.lado;
    int x = (hexagono.coord.X + Ancho_pantalla) % Ancho_pantalla;
    int y = (hexagono.coord.Y + Alto_pantalla) % Alto_pantalla;

    int centroX = x + lado;
    int centroY = y + lado;

    int apotema = static_cast<int>(round(lado * sqrt(3) / 2.0));

    for (int dy = -apotema; dy <= apotema; dy++) {
        for (int dx = -lado; dx <= lado; dx++) {
            if (abs(dy) <= apotema - (apotema * abs(dx) / lado)) {
                COORD coord;
                coord.X = (centroX + dx + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (centroY + dy + Alto_pantalla) % Alto_pantalla;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
                cout << NuevoCaracter;
            }
        }
    }
}

/*Creamos una funcion una funcion cuyo objetivo es mostrar el color actual seleccionado por la consola */
void mostrar_color_actual(int color) {
    switch (color) {
        case 1:
            cout << "\x1b[31m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Rojo\n" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        case 2:
            cout << "\x1b[34m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Azul" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        case 3:
            cout << "\x1b[32m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Verde" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        case 4:
            cout << "\x1b[33m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Amarillo" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        case 5:
            cout << "\x1b[36m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Cian" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        case 6:
            cout << "\x1b[35m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Magenta" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        case 7:
            cout << "\x1b[0m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Blanco" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        case 8:
            cout << "\x1b[90m";
            cout << "\n\n\n\t\t\t\t\t\t Color actual: Gris" << endl;
            cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
            cout << "\t\t\t\t\t\t\t( o.o )" << endl;
            cout << "\t\t\t\t\t\t\t > ^ < " << endl;
            cout << "\n\n\t\t\t\t\t\tEspere unos segundos..." << endl;
            break;
        default:
            cout << "\x1b[0m";
            cout << "\t\t\t\t\n\n\n Color actual: Se mantendra el color" << endl;
            break;
    }
}

/*Funcion diseñada para permitir al usuario cambiar el caracter*/

void cambiar_caracter(char NuevoCaracter) {
    cin >> NuevoCaracter;
}


/*Creamos esta funcion para eliminar todas las figuras en un momento dado, como limpiar pantalla*/
// BORRAR FIGURAS
void borrar_dibujos() {
    triangulos.clear();
    cuadrados.clear();
    rectangulos.clear();
    circulos.clear();
    lineas.clear();
    rombos.clear();
    hexagonos.clear();
}
/*Funcion para que cuando el usuario la llame limpie todo en la pantalla*/
void limpiar_pantalla() {
    system("cls");
}

/*Creamos nuestro menu*/
// Menu
void Menu() {
    cout << "\n\t\t___________________________________________________________________________________________\n";
    cout << "\t\t|\t\t\t\t\t\t\t\t\t\t\t  |";
    cout << "\n\t\t| F1. Triangulo  - ";
    cout << " F2. Cuadrado - ";
    cout << " F3. Rectangulo - ";
    cout << " F4. Circulo ";
    cout << " F5. Linea  -";
    cout << " F6. Rombo |\n";
    cout << "\t\t| F7. Hexagono -";
    cout << "  F8. Nuevo Caracter -";
    cout << " F9. Limpiar Pantalla  -";
    cout << "    F10. Color de caracter  |\n";
    cout << "\t\t| F12. Grabar Pantalla -";
    cout << " Ctrl + A . abrir archivo y mostrar en pantalla    -";
    cout << "    9. Salir  |\n";
    cout << "\t\t|_________________________________________________________________________________________|";
}


/*Creamos una funcion para permitir al usuario ingresar informacion sobre la figura*/
// FORMULARIO DE FIGURAS
void accionF1() {
    int base;
    char orientacion;
    cout << "\n *Ingrese el tamanio de la base del triangulo: ";
    cin >> base;
    cout << "\n *Seleccione la orientacion del triangulo:\n";
    cout << " a: Arriba\n b: Abajo\n d: Derecha\n i: Izquierda\n";
    cin >> orientacion;
    modeloTriangulo nuevoTriangulo;
    nuevoTriangulo.base = base;
    nuevoTriangulo.orientacion = orientacion;
    nuevoTriangulo.coord.X = CoordenadaX;
    nuevoTriangulo.coord.Y = CoordenadaY;
    nuevoTriangulo.Color = Color_De_Figura;
    nuevoTriangulo.NuevoCaracter = Puntero;
    triangulos.push_back(nuevoTriangulo);
}

/*Creamos una funcion para permitir al usuario ingresar informacion sobre la figura*/
void accionF2() {
    int lado;
    char orientacion;
    cout << "\n *Ingrese el tamanio del lado del cuadrado: ";
    cin >> lado;
    cout << "\n *Seleccione la orientacion del cuadrado:\n";
    cout << " a: Arriba\n b: Abajo\n d: Derecha\n i: Izquierda\n";
    cin >> orientacion;

    modeloCuadrado nuevoCuadrado;
    nuevoCuadrado.lado = lado;
    nuevoCuadrado.orientacion = orientacion;
    nuevoCuadrado.coord.X = CoordenadaX;
    nuevoCuadrado.coord.Y = CoordenadaY;
    nuevoCuadrado.Color = Color_De_Figura;
    nuevoCuadrado.NuevoCaracter = Puntero;
    cuadrados.push_back(nuevoCuadrado);
}

/*Creamos una funcion para permitir al usuario ingresar informacion sobre la figura*/
void accionF3() {
    int ancho, alto;
    char orientacion;
    cout << "\n *Ingrese el ancho del rectangulo: ";
    cin >> ancho;
    cout << "\n *Ingrese el alto del rectangulo: ";
    cin >> alto;
    cout << "\n *Seleccione la orientacion del rectangulo:\n";
    cout << " a: Arriba\n b: Abajo\n";
    cin >> orientacion;
    modeloRectangulo nuevoRectangulo;
    nuevoRectangulo.ancho = ancho;
    nuevoRectangulo.alto = alto;
    nuevoRectangulo.coord.X = CoordenadaX;
    nuevoRectangulo.coord.Y = CoordenadaY;
    nuevoRectangulo.orientacion = orientacion;
    nuevoRectangulo.Color = Color_De_Figura;
    nuevoRectangulo.NuevoCaracter = Puntero;
    rectangulos.push_back(nuevoRectangulo);
}

/*Creamos una funcion para permitir al usuario ingresar informacion sobre la figura*/
void accionF4() {
    int radio;
    cout << "\n *Ingrese el radio del circulo: ";
    cin >> radio;
    modeloCirculo nuevoCirculo;
    nuevoCirculo.radio = radio;
    nuevoCirculo.coord.X = CoordenadaX;
    nuevoCirculo.coord.Y = CoordenadaY;
    nuevoCirculo.Color = Color_De_Figura;
    nuevoCirculo.NuevoCaracter = Puntero;
    circulos.push_back(nuevoCirculo);
}

/*Creamos una funcion para permitir al usuario ingresar informacion sobre la figura*/
void accionF5() {
    modeloLinea nuevaLinea;
    cout << "\n *Ingrese la longitud de la linea: ";
    cin >> nuevaLinea.longitud;
    cout << "\n *Seleccione la orientacion de la linea:\n";
    cout << " a: Arriba\n b: Abajo\n d: Derecha\n i: Izquierda\n";
    cout << " q: Diagonal Izquierda Arriba\n e: Diagonal Derecha Arriba\n";
    cout << " z: Diagonal Izquierda Abajo\n c: Diagonal Derecha Abajo\n";
    cin >> nuevaLinea.orientacion;
    nuevaLinea.coord.X = CoordenadaX;
    nuevaLinea.coord.Y = CoordenadaY;
    nuevaLinea.Color = Color_De_Figura;
    nuevaLinea.NuevoCaracter = Puntero;
    lineas.push_back(nuevaLinea);
}

/*Creamos una funcion para permitir al usuario ingresar informacion sobre la figura*/
void accionF6() {
    int lado;
    char orientacion;
    cout << "\n *Ingrese la longitud de un lado del rombo: ";
    cin >> lado;
    cout << "\n *Seleccione la orientacion del rombo (a: Arriba, b: Abajo): ";
    cin >> orientacion;
    modeloRombo nuevoRombo;
    nuevoRombo.lado = lado;
    nuevoRombo.orientacion = orientacion;
    nuevoRombo.coord.X = CoordenadaX;
    nuevoRombo.coord.Y = CoordenadaY;
    nuevoRombo.Color = Color_De_Figura;
    nuevoRombo.NuevoCaracter = Puntero;
    rombos.push_back(nuevoRombo);
}

/*Creamos una funcion para permitir al usuario ingresar informacion sobre la figura*/
void accionF7() {
    int lado;
    cout << "\n *Ingrese el tamanio de un lado del hexagono: ";
    cin >> lado;
    modeloHexagono nuevoHexagono;
    nuevoHexagono.lado = lado;
    nuevoHexagono.coord.X = CoordenadaX;
    nuevoHexagono.coord.Y = CoordenadaY;
    nuevoHexagono.Color = Color_De_Figura;
    nuevoHexagono.NuevoCaracter = Puntero;
    hexagonos.push_back(nuevoHexagono);
}

/*Creamos una funcion para permitir al usuario cambiar el caracter de la nueva figura*/
void accionF8() {
    system("cls");
    char NuevoCaracter;
    cout << "\n\n\n\n\n\t\t\t\tIngrese el nuevo caracter que deseas utilizar: ";
    cin >> NuevoCaracter;
    Puntero = NuevoCaracter;
    cout << "\n\n\n\n\n\t\t\t\t\t Tu caracter ha sido actualizado!" << endl;
    cout << "\x1b[33m";
    cout << "\n\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
    cout << "\t\t\t\t\t\t\t( o.o )" << endl;
    cout << "\t\t\t\t\t\t\t > ^ < " << endl;
    cout << "\x1b[91m";
    cout << "\n\n\t\t\t\t\t\t      CARGANDO . . ." << endl;
    cin.get();
    Sleep (3000);

}

/*Creamos una funcion para permitir al usuario cambiar de color a la nueva figura*/
void accionF10() {
    limpiar_pantalla();
    int color;
    cout << "Elige el color para el puntero:" << endl;
    cout << "1. Rojo" << endl;
    cout << "2. Azul" << endl;
    cout << "3. Verde" << endl;
    cout << "4. Amarillo" << endl;
    cout << "5. Cian" << endl;
    cout << "6. Magenta" << endl;
    cout << "7. Blanco" << endl;
    cout << "8. Gris" << endl;
    cin >> color;
    switch (color) {
        case 1:
            Color_De_Figura = 12;
            break;
        case 2:
            Color_De_Figura = 9;
            break;
        case 3:
            Color_De_Figura = 10;
            break;
        case 4:
            Color_De_Figura = 14;
            break;
        case 5:
            Color_De_Figura = 11;
            break;
        case 6:
            Color_De_Figura = 13;
            break;
        case 7:
            Color_De_Figura = 15;
            break;
        case 8:
            Color_De_Figura = 8;
            break;
        default:
            cout << "Opcion no valida, Se mantendra el color." << endl;
            break;
    }
    mostrar_color_actual(color);
    Sleep (3000);
}

/*Creamos una funcion para permitir al usuario guardar las figuras en pantalla*/
void accionF12() {
    string rutaArchivo;
    string rutaCompleta;
    string nombreArchivo;
    cout << "\x1b[32m";
    cout << "1)Escribe el nombre del archivo \n\t\t\t  2)Cuando coloques el nombre termina con.txt: ";
    cin >> nombreArchivo;
    cout << "\t\t\t  3)Escribir la ruta donde quieres guardar el archivo ejemplo ./: ";
    cin >> rutaArchivo;

    rutaCompleta = rutaArchivo + "/" + nombreArchivo;

                ofstream archivo;
                archivo.open(rutaCompleta, ios::out);

                if (archivo.is_open()) {

                    for (const auto &triangulo : triangulos) {
                        archivo << triangulo.id << ";" << triangulo.base << ";" << triangulo.orientacion << ";" << triangulo.coord.X << ";" << triangulo.coord.Y << ";" << triangulo.Color << ";" << triangulo.NuevoCaracter <<"\n";
                    }
                    for (const auto &cuadrado : cuadrados){
                          archivo << cuadrado.id << ";" << cuadrado.orientacion << ";" << cuadrado.coord.X << ";" << cuadrado.coord.Y << ";" << cuadrado.Color << ";" << cuadrado.NuevoCaracter <<"\n";
                     }
                    for (const auto &rectangulo : rectangulos){
                        archivo << rectangulo.id << ";" << rectangulo.ancho << ";" << rectangulo.alto << ";" << rectangulo.orientacion << ";" << rectangulo.coord.X << ";" << rectangulo.coord.Y << ";" << rectangulo.Color << ";" << rectangulo.NuevoCaracter << "\n";
                    }
                    for (const auto &circulo : circulos){
                        archivo << circulo.id << ";" << circulo.radio << ";" << circulo.coord.X << ";" << circulo.coord.Y << ";" << circulo.Color << ";" << circulo.NuevoCaracter << "\n";
                    }
                    for (const auto &linea : lineas){
                        archivo << linea.id << ";" << linea.longitud << ";" << linea.orientacion << ";" << linea.coord.X << ";" << linea.coord.Y << ";" << linea.Color << ";" << linea.NuevoCaracter << "\n";
                    }
                    for (const auto &rombo : rombos){
                        archivo << rombo.id << ";" << rombo.lado << ";" << rombo.orientacion << ";" << rombo.coord.X << ";" << rombo.coord.Y << ";" << rombo.Color << ";" << rombo.NuevoCaracter << "\n";
                    }
                    for (const auto &hexagono : hexagonos){
                        archivo << hexagono.id << ";" << hexagono.lado << ";" << hexagono.coord.X << ";" << hexagono.coord.Y << ";" << hexagono.Color << ";" << hexagono.NuevoCaracter << "\n";
                    }
                    archivo.close();
                    cout << "\x1b[37m" << endl;
                    cout << "\t\t\t  Las Figuras se guardaron correctamente" << endl;
                    Sleep(5000);
                    } else {
                    cout << "\x1b[37m" << endl;
                    cout << "\t\t\t  No se pudieron guardas las figuras"<< endl;
                    Sleep(5000);
                }

}

/*Creamos una funcion para permitir al usuario cargar las figuras previamente guardadas*/
void AccionCtrlA () {
    string ruta;
                cout <<"BIENVENIDO A CARGAR FIGURAS" << endl;
                cout<<"\t\t\t *Escribe la ruta del archivo \n *\t\t\t *Ejemplo: ./varias.txt \n\t\t\t\t"<<endl;
                cin >> ruta;
                ifstream archivo;
                archivo.open(ruta, ios::in);
                if (archivo.fail()) {
                    cout << "\t\t\t El archivo no fue encontrado o no existe" << endl;
                    Sleep(5000);
                } else {

                    triangulos.clear();
                    cuadrados.clear();
                    rectangulos.clear();
                    circulos.clear();
                    lineas.clear();
                    rombos.clear();
                    hexagonos.clear();

                    string figura;
                    while (getline(archivo, figura)) {
                        stringstream token(figura);
                        string campo;

                        getline(token, campo, ';');
                        int id = stoi(campo);

if (id == 1) {
            getline(token, campo, ';');
            int base = std::stoi(campo);

            getline(token, campo, ';');
            char orientacion = campo[0];

            getline(token, campo, ';');
            int CoordenadaX = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaY = std::stoi(campo);

            getline(token, campo, ';');
            int Color = std::stoi(campo);

            getline(token, campo);
            char NuevoCaracter = campo[0];

            modeloTriangulo nuevoTriangulo;
            nuevoTriangulo.base = base;
            nuevoTriangulo.orientacion = orientacion;
            nuevoTriangulo.coord.X = CoordenadaX;
            nuevoTriangulo.coord.Y = CoordenadaY;
            nuevoTriangulo.Color = Color;
            nuevoTriangulo.NuevoCaracter = NuevoCaracter;

            triangulos.push_back(nuevoTriangulo);
           } else if (id == 2) {
            getline(token, campo, ';');
            int lado = std::stoi(campo);

            getline(token, campo, ';');
            char orientacion = campo[0];

            getline(token, campo, ';');
            int CoordenadaX = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaY = std::stoi(campo);

            getline(token, campo, ';');
            int Color = std::stoi(campo);

            getline(token, campo);
            char NuevoCaracter = campo[0];

            modeloCuadrado nuevoCuadrado;
            nuevoCuadrado.lado = lado;
            nuevoCuadrado.orientacion = orientacion;
            nuevoCuadrado.coord.X = CoordenadaX;
            nuevoCuadrado.coord.Y = CoordenadaY;
            nuevoCuadrado.Color = Color;
            nuevoCuadrado.NuevoCaracter = NuevoCaracter;

            cuadrados.push_back(nuevoCuadrado);
        } else if (id == 3) {
            getline(token, campo, ';');
            int ancho = std::stoi(campo);

            getline(token, campo, ';');
            int alto = std::stoi(campo);

            getline(token, campo, ';');
            char orientacion = campo[0];

            getline(token, campo, ';');
            int CoordenadaX = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaY = std::stoi(campo);

            getline(token, campo, ';');
            int Color = std::stoi(campo);

            getline(token, campo);
            char NuevoCaracter = campo[0];

            modeloRectangulo nuevoRectangulo;
            nuevoRectangulo.ancho = ancho;
            nuevoRectangulo.alto = alto;
            nuevoRectangulo.orientacion = orientacion;
            nuevoRectangulo.coord.X = CoordenadaX;
            nuevoRectangulo.coord.Y = CoordenadaY;
            nuevoRectangulo.Color = Color;
            nuevoRectangulo.NuevoCaracter = NuevoCaracter;

            rectangulos.push_back(nuevoRectangulo);
        } else if (id == 4) {
            getline(token, campo, ';');
            int radio = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaX = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaY = std::stoi(campo);

            getline(token, campo, ';');
            int Color = std::stoi(campo);

            getline(token, campo);
            char NuevoCaracter = campo[0];

            modeloCirculo nuevoCirculo;
            nuevoCirculo.radio = radio;
            nuevoCirculo.coord.X = CoordenadaX;
            nuevoCirculo.coord.Y = CoordenadaY;
            nuevoCirculo.Color = Color;
            nuevoCirculo.NuevoCaracter = NuevoCaracter;

            circulos.push_back(nuevoCirculo);
        } else if (id == 5) {
            getline(token, campo, ';');
            int longitud = std::stoi(campo);

            getline(token, campo, ';');
            char orientacion = campo[0];

            getline(token, campo, ';');
            int CoordenadaX = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaY = std::stoi(campo);

            getline(token, campo, ';');
            int Color = std::stoi(campo);

            getline(token, campo);
            char NuevoCaracter = campo[0];

            modeloLinea nuevaLinea;
            nuevaLinea.longitud = longitud;
            nuevaLinea.orientacion = orientacion;
            nuevaLinea.coord.X = CoordenadaX;
            nuevaLinea.coord.Y = CoordenadaY;
            nuevaLinea.Color = Color;
            nuevaLinea.NuevoCaracter = NuevoCaracter;

            lineas.push_back(nuevaLinea);
        } else if (id == 6) {
            getline(token, campo, ';');
            int lado = std::stoi(campo);

            getline(token, campo, ';');
            char orientacion = campo[0];

            getline(token, campo, ';');
            int CoordenadaX = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaY = std::stoi(campo);

            getline(token, campo, ';');
            int Color = std::stoi(campo);

            getline(token, campo);
            char NuevoCaracter = campo[0];

            modeloRombo nuevoRombo;
            nuevoRombo.lado = lado;
            nuevoRombo.orientacion = orientacion;
            nuevoRombo.coord.X = CoordenadaX;
            nuevoRombo.coord.Y = CoordenadaY;
            nuevoRombo.Color = Color;
            nuevoRombo.NuevoCaracter = NuevoCaracter;

            rombos.push_back(nuevoRombo);
        } else if (id == 7) {
            getline(token, campo, ';');
            int lado = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaX = std::stoi(campo);

            getline(token, campo, ';');
            int CoordenadaY = std::stoi(campo);

            getline(token, campo, ';');
            int Color = std::stoi(campo);

            getline(token, campo);
            char NuevoCaracter = campo[0];

            modeloHexagono nuevoHexagono;
            nuevoHexagono.lado = lado;
            nuevoHexagono.coord.X = CoordenadaX;
            nuevoHexagono.coord.Y = CoordenadaY;
            nuevoHexagono.Color = Color;
            nuevoHexagono.NuevoCaracter = NuevoCaracter;

            hexagonos.push_back(nuevoHexagono);
        }
    }
                    archivo.close();
                    cout << "\t\t\t *Las figuras fueron cargadas correctamente: " << endl;
                    cout << "\x1b[35m";
                    cout << "\n\n\n\t\t\t\t\t\t\t /\\_/\\ " << endl;
                    cout << "\t\t\t\t\t\t\t( o.o )" << endl;
                    cout << "\t\t\t\t\t\t\t > ^ < " << endl;
                    cout << "\x1b[0m";
                    cout << "\n\n\t\t\t\t\t\t       Cargando..." << endl;
                    Sleep(7000);

                }
}


// CARGANDO FIGURAS
/*Creamos una funcion para cargar las figuras almacenadas en los vectores, llamamos la funcion 
dibujar para que se dibuje en la pantalla*/
void cargarCuadrados() {
    for (const auto &cuadrado : cuadrados)
        dibujar_cuadrado(cuadrado, cuadrado.Color, cuadrado.NuevoCaracter ,cuadrado.orientacion);
}

/*Creamos una funcion para cargar las figuras almacenadas en los vectores, llamamos la funcion 
dibujar para que se dibuje en la pantalla*/
void cargarCirculos() {
    for (const auto &circulo : circulos)
        dibujar_circulo(circulo.coord.X, circulo.coord.Y, circulo.radio, circulo.Color ,circulo.NuevoCaracter);
}

/*Creamos una funcion para cargar las figuras almacenadas en los vectores, llamamos la funcion 
dibujar para que se dibuje en la pantalla*/
void cargarTriangulos() {
    for (const auto &triangulo : triangulos)
        dibujar_triangulo(triangulo.base, triangulo.coord.X, triangulo.coord.Y, triangulo.Color, triangulo.NuevoCaracter, triangulo.orientacion);
}

/*Creamos una funcion para cargar las figuras almacenadas en los vectores, llamamos la funcion 
dibujar para que se dibuje en la pantalla*/
void cargarRectangulos() {
   for (const auto& rect : rectangulos) {
    dibujar_rectangulo(rect.ancho, rect.alto, rect.coord.X, rect.coord.Y, rect.Color, rect.NuevoCaracter, rect.orientacion);
}
}

/*Creamos una funcion para cargar las figuras almacenadas en los vectores, llamamos la funcion 
dibujar para que se dibuje en la pantalla*/
void cargarLineas() {
    for (const auto &linea : lineas)
        dibujar_linea(linea, linea.Color, linea.NuevoCaracter);
}

/*Creamos una funcion para cargar las figuras almacenadas en los vectores, llamamos la funcion 
dibujar para que se dibuje en la pantalla*/
void cargarRombos() {
    for (const auto &rombo : rombos)
        dibujar_rombo(rombo, rombo.Color, rombo.NuevoCaracter);
}

/*Creamos una funcion para cargar las figuras almacenadas en los vectores, llamamos la funcion 
dibujar para que se dibuje en la pantalla*/
void cargarHexagonos() {
    for (const auto &hexagono : hexagonos)
        dibujar_hexagono(hexagono, hexagono.Color, hexagono.NuevoCaracter);
}
/*Creamos nuestras funciones de teclas para que al momento de que el usuario las presione realice una accion*/
// OPCIONES DE TECLAS
int main() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &info);

    while (!quit) {
        limpiar_pantalla();
        Menu();
        cargarTriangulos();
        cargarCuadrados();
        cargarRectangulos();
        cargarCirculos();
        cargarLineas();
        cargarRombos();
        cargarHexagonos();
        gotoxy(CoordenadaX, CoordenadaY, Puntero, NuevoCaracter);
        Sleep(50);

        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'a':
                    CoordenadaX = (CoordenadaX - 1 + Ancho_pantalla) % Ancho_pantalla;
                    break;
                case 'd':
                    CoordenadaX = (CoordenadaX + 1 + Ancho_pantalla) % Ancho_pantalla;
                    break;
                case 'w':
                    CoordenadaY = (CoordenadaY - 1 + Alto_pantalla) % Alto_pantalla;
                    break;
                case 's':
                    CoordenadaY = (CoordenadaY + 1 + Alto_pantalla) % Alto_pantalla;
                    break;
                case '9':
                    quit = true;
                    system("color F1");
                    cout << "\x1b[31m";
                    cout << "\n\n\t\t\t\t ........................¶.........¶.......................... " << endl;
                    cout << "\t\t\t\t .........................¶.........¶......................... " << endl;
                    cout << "\t\t\t\t ....................¶....¶..........¶...¶.................... " << endl;
                    cout << "\t\t\t\t .....................¶..¶¶..........¶¶..¶.................... " << endl;
                    cout << "\t\t\t\t .....................¶¶.¶¶¶.......¶¶¶.¶¶..................... " << endl;
                    cout << "\t\t\t\t ............¶.......¶¶...¶¶.....¶¶¶...¶¶......¶.............. " << endl;
                    cout << "\t\t\t\t ............¶¶......¶¶...¶¶¶.....¶¶¶...¶¶......¶¶............ " << endl;
                    cout << "\t\t\t\t ...........¶¶......¶¶....¶¶¶¶...¶¶¶¶....¶¶......¶¶........... " << endl;
                    cout << "\t\t\t\t ...........¶¶.....¶¶¶....¶¶¶¶..¶¶¶¶¶....¶¶¶.....¶¶¶.......... " << endl;
                    cout << "\t\t\t\t ........¶..¶¶¶....¶¶¶¶....¶¶¶¶...¶¶¶¶....¶¶¶¶...¶¶¶¶..¶...... " << endl;
                    cout << "\t\t\t\t .......¶¶.¶¶¶¶¶..¶¶¶¶...¶¶¶¶¶...¶¶¶¶¶...¶¶¶¶..¶¶¶¶¶.¶¶....... " << endl;
                    cout << "\t\t\t\t .......¶¶.¶¶¶¶¶..¶¶¶¶¶¶¶¶¶¶¶.....¶¶¶¶¶¶¶¶¶¶¶..¶¶¶¶¶.¶¶....... " << endl;
                    cout << "\t\t\t\t .......¶¶.¶¶¶¶¶..¶¶¶¶¶¶¶¶¶¶¶.....¶¶¶¶¶¶¶¶¶¶¶..¶¶¶¶¶.¶¶....... " << endl;
                    cout << "\t\t\t\t ......¶¶¶..¶¶¶¶...¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶...¶¶¶¶..¶¶¶...... " << endl;
                    cout << "\t\t\t\t .....¶¶¶¶..¶¶¶¶...¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶...¶¶¶¶..¶¶¶¶..... " << endl;
                    cout << "\t\t\t\t ....¶¶¶¶...¶¶¶¶¶.¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶.¶¶¶¶¶...¶¶¶¶.... " << endl;
                    cout << "\t\t\t\t ...¶¶¶¶....¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶...¶¶¶¶.... " << endl;
                    cout << "\t\t\t\t ...¶¶¶¶¶..¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶..¶¶¶¶.... " << endl;
                    cout << "\t\t\t\t ....¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶.... " << endl;
                    cout << "\t\t\t\t ....¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶.... " << endl;
                    cout << "\t\t\t\t .....¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶..... " << endl;
                    cout << "\t\t\t\t .....¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶..... " << endl;
                    cout << "\t\t\t\t ......¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶...... " << endl;
                    cout << "\t\t\t\t .....¶¶¶¶¶...........¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶...........¶¶¶¶¶..... " << endl;
                    cout << "\t\t\t\t .....¶¶¶¶¶¶.............¶¶¶¶¶¶¶¶¶¶¶¶¶.............¶¶¶¶¶¶..... " << endl;
                    cout << "\t\t\t\t ......¶¶¶¶¶¶¶..............¶¶¶¶¶¶¶¶¶.............¶¶¶¶¶¶...... " << endl;
                    cout << "\t\t\t\t .......¶¶¶¶¶¶¶¶.............¶¶¶¶¶..............¶¶¶¶¶¶¶¶...... " << endl;
                    cout << "\t\t\t\t ........¶¶¶¶¶¶¶¶¶¶...........¶¶¶...........¶¶¶¶¶¶¶¶¶¶........ " << endl;
                    cout << "\t\t\t\t ...........¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶........... " << endl;
                    cout << "\t\t\t\t ..............¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶...¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶.............. " << endl;
                    cout << "\t\t\t\t ..................¶¶¶¶¶¶¶¶¶¶.....¶¶¶¶¶¶¶¶¶¶.................. " << endl;
                    cout << "\t\t\t\t ...................¶¶¶¶¶¶¶¶.......¶¶¶¶¶¶¶¶................... " << endl;
                    cout << "\t\t\t\t ..................¶¶¶¶¶¶¶¶¶.......¶¶¶¶¶¶¶¶¶.................. " << endl;
                    cout << "\t\t\t\t ..................¶¶¶¶¶¶¶¶¶.¶¶¶¶¶.¶¶¶¶¶¶¶¶¶.................. " << endl;
                    cout << "\t\t\t\t .................¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶................. " << endl;
                    cout << "\t\t\t\t .................¶¶¶..¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶..¶¶¶................. " << endl;
                    cout << "\t\t\t\t ..................¶¶..¶¶¶¶..¶¶¶¶¶..¶¶¶¶..¶¶.................. " << endl;
                    cout << "\t\t\t\t ......................¶¶¶¶..¶¶¶¶¶..¶¶¶¶...................... " << endl;
                    cout << "\x1b[34m";
                    cout << "\n\n\t\t\t\t\t\t       FIN DEL PROGRAMA \n\n\n" << endl;;
                    break;
                default:
                    if (GetKeyState(VK_F1) & 0x8000) {
                        accionF1();
                    }
                    if (GetKeyState(VK_F2) & 0x8000) {
                        accionF2();
                    }
                    if (GetKeyState(VK_F3) & 0x8000) {
                        accionF3();
                    }
                    if (GetKeyState(VK_F4) & 0x8000) {
                        accionF4();
                    }
                    if (GetKeyState(VK_F5) & 0x8000) {
                        accionF5();
                    }
                    if (GetKeyState(VK_F6) & 0x8000) {
                        accionF6();
                    }
                    if (GetKeyState(VK_F7) & 0x8000) {
                        accionF7();
                    }
                     if (GetKeyState(VK_F8) & 0x8000) {
                        accionF8();
                    }
                    if (GetKeyState(VK_F9) & 0x8000) {
                        borrar_dibujos();
                    }
                    if (GetKeyState(VK_F10) & 0x8000) {
                        accionF10();
                    }
                    if (GetKeyState(VK_F12) & 0x8000) {
                        accionF12();
                    }

                    if ((GetAsyncKeyState (VK_CONTROL) & 0x8000) && (GetAsyncKeyState (0x41) & 0x8000)) {
                       AccionCtrlA();
                       }

                    break;
            }
        }
        Sleep(100);
    }
    return 0;
}
