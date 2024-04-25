#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

const int Ancho_pantalla = 80;
const int Alto_pantalla = 35;
const char Dibujo = '*';
const char Puntero = 'X';

int CoordenadaX = Ancho_pantalla / 2;
int CoordenadaY = Alto_pantalla / 2;

struct modeloTriangulo {
    int base;
    COORD coord;
};

struct modeloCuadrado {
    int lado;
    COORD coord;
};

struct modeloCirculo {
    int radio;
    COORD coord;
};

struct modeloRectangulo {
    int ancho;
    int alto;
    COORD coord;
};

vector<modeloCuadrado> cuadrados;
vector<modeloCirculo> circulos;
vector<modeloTriangulo> triangulos;
vector<modeloRectangulo> rectangulos;

void gotoxy(int x, int y, char c) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 6);
    cout << c;
}

void dibujar_cuadrado(modeloCuadrado cuadrado) {
    int size = cuadrado.lado;
    int x = cuadrado.coord.X;
    int y = cuadrado.coord.Y;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                COORD coord;
                coord.X = (x - size / 2 + j + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (y - size / 2 + i + Alto_pantalla) % Alto_pantalla;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 4);
                cout << Dibujo;
            }
        }
    }
}

void dibujar_circulo(int x, int y, int radio, char c) {
    COORD coord;
    for (int i = -radio; i <= radio; ++i) {
        for (int j = -radio; j <= radio; ++j) {
            if (i * i + j * j <= radio * radio + radio/2 && i * i + j * j >= radio * radio - radio/2) {
                coord.X = (x + j + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (y + i + Alto_pantalla) % Alto_pantalla;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                cout << c;
            }
        }
    }
}
void dibujar_triangulo(int base, int x, int y) {
    int height = base / 2 + 1;

    int startX = x - base / 2;
    int startY = y + height - 1;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < base; ++j) {
            COORD coord;
            coord.X = (startX + j + Ancho_pantalla) % Ancho_pantalla;
            coord.Y = (startY - i + Alto_pantalla) % Alto_pantalla;
            if (j >= i && j < base - i) {
                if (i == 0 || j == i || j == base - i - 1 || i == height - 1) {
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    cout << Dibujo;
                }
            }
        }
    }
}
void dibujar_rectangulo(int width, int height, int x, int y) {
    COORD coord;
    coord.X = (x - width / 2 + Ancho_pantalla) % Ancho_pantalla;
    coord.Y = (y - height / 2 + Alto_pantalla) % Alto_pantalla;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                coord.X = (x - width / 2 + j + Ancho_pantalla) % Ancho_pantalla;
                coord.Y = (y - height / 2 + i + Alto_pantalla) % Alto_pantalla;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 2);
                cout << Dibujo;
            }
        }
    }
}
void limpiar_pantalla() {
    system("cls");
}
int Menu () {
    limpiar_pantalla();
    system("color F1");
    int choice;
    cout << "\n\n\t\t\t--------------------------------------------------------------------------";
    cout << "\n\t\t\t| \t Bienvenido a programa mi UMG Seleccione una opcion: \t\t | \n";
    cout << "\t\t \t| 1. Triangulo | ";
    cout << " 2. Cuadrado |";
    cout << " 3. Rectangulo |";
    cout << " 4. Circulo |";
    cout << " 5. Esc \t | \n";
    cout << "\t\t\t--------------------------------------------------------------------------";
    cout << "\n\n \t\t ingrese su eleccion: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int base;
            cout << "Ingrese el tamanio de la base del triangulo: ";
            cin >> base;
            modeloTriangulo nuevoTriangulo;
            nuevoTriangulo.base = base;
            nuevoTriangulo.coord.X = CoordenadaX;
            nuevoTriangulo.coord.Y = CoordenadaY;
            triangulos.push_back(nuevoTriangulo);
            break;
        }
        case 2: {
            int lado;
            cout << "Ingrese el tamanio del lado del cuadrado: ";
            cin >> lado;
            modeloCuadrado nuevoCuadrado;
            nuevoCuadrado.lado = lado;
            nuevoCuadrado.coord.X = CoordenadaX;
            nuevoCuadrado.coord.Y = CoordenadaY;
            cuadrados.push_back(nuevoCuadrado);
            break;
        }
        case 3: {
            int ancho, alto;
            cout << "Ingrese el ancho del rectangulo: ";
            cin >> ancho;
            cout << "Ingrese el alto del rectangulo: ";
            cin >> alto;
            modeloRectangulo nuevoRectangulo;
            nuevoRectangulo.ancho = ancho;
            nuevoRectangulo.alto = alto;
            nuevoRectangulo.coord.X = CoordenadaX;
            nuevoRectangulo.coord.Y = CoordenadaY;
            rectangulos.push_back(nuevoRectangulo);
            break;
        }
        case 4: {
            int radio;
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            modeloCirculo nuevoCirculo;
            nuevoCirculo.radio = radio;
            nuevoCirculo.coord.X = CoordenadaX;
            nuevoCirculo.coord.Y = CoordenadaY;
            circulos.push_back(nuevoCirculo);
            break;
        }
        case 5:
            return 0;
        default:
            cout << "";
            break;
    }
    return choice;
}

void cargarCuadrados() {
    for (const auto &cuadrado : cuadrados)
        dibujar_cuadrado(cuadrado);
}

void cargarCirculos() {
    for (const auto &circulo : circulos)
        dibujar_circulo(circulo.coord.X, circulo.coord.Y, circulo.radio, Dibujo);
}

void cargarTriangulos() {
    for (const auto &triangulo : triangulos)
        dibujar_triangulo(triangulo.base, triangulo.coord.X, triangulo.coord.Y);
}

void cargarRectangulos() {
    for (const auto &rectangulo : rectangulos)
        dibujar_rectangulo(rectangulo.ancho, rectangulo.alto, rectangulo.coord.X, rectangulo.coord.Y);
}

int main() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console, &info);

    bool quit = false;
    while (!quit) {
        limpiar_pantalla();
        cargarCuadrados();
        cargarCirculos();
        cargarTriangulos();
        cargarRectangulos();
        gotoxy(CoordenadaX, CoordenadaY, Puntero);

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
                case VK_ESCAPE:
                    quit = true;
                    break;
                default:
                    if (GetKeyState(VK_F12) & 0x8000) {
                        Menu ();
                    }
                    break;
            }
        }
        Sleep(100);
    }

    return 0;
}
