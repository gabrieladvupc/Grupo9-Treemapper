#include "pch.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <cstdlib> // srand
#include <ctime>   //time null
#include <string>
using namespace System;
using namespace std;


//NodoArbol representa un nodo en el árbol. 
//Cada nodo tiene un valor enterno y un vector de punteros a sus nodos hijos.
struct NodoArbol {
    int dato;
    vector<NodoArbol*> hijos;
    NodoArbol(int val) : dato(val) {}
};

//Crea un árbol aleatorio con un número dado de nodos. 
//Comienza con un nodo raíz y luego agrega nodos hijos de manera aleatoria.
NodoArbol* generarArbolAleatorio(int numNodos) {
    if (numNodos <= 0) {
        return nullptr;
    }
    NodoArbol* raiz = new NodoArbol(1); // Siempre inicia en 1
    vector<NodoArbol*> nodosP; // visitar nodos o nodos por visitar
    nodosP.push_back(raiz);
    int posNodosP = 0;
    int valor = 2; // Inicia en 2 para el siguiente nodo

    while (numNodos > 1) {
        NodoArbol* actual = nodosP[posNodosP];
        int numHijos = rand() % 3 + 2; // Entre 2 y 4 hijos
        for (int i = 0; i < numHijos && numNodos > 1; ++i) {
            NodoArbol* hijo = new NodoArbol(valor++);
            actual->hijos.push_back(hijo);
            nodosP.push_back(hijo);
            numNodos--;
        }
        posNodosP++;
    }

    return raiz;
}
// OPCION 1 
/*void imprimirArbol(NodoArbol* raiz, string sede, int profundidad = 0) {
    if (!raiz) return;

    for (int i = 0; i < profundidad; ++i) {
        cout << "  " << " |_> ";
    }
    cout << raiz->dato << endl;

    for (NodoArbol* hijo : raiz->hijos) {
        imprimirArbol(hijo, sede, profundidad + 1);
    }
}*/
//OPCION 2
/*void imprimirArbol(NodoArbol* raiz, string sede, int nivel = 0) {
    if (!raiz) return;

    if (nivel != 0) {
        for (int i = 0; i < nivel - 1; ++i) {
            cout << "   ";
            if (i == nivel - 2) {
                cout << " /";
            }
        }
        cout << " |_> ";
    }

    cout << raiz->dato << endl;

    for (size_t i = 0; i < raiz->hijos.size(); ++i) {
        imprimirArbol(raiz->hijos[i], sede, nivel + 1);
        if (i < raiz->hijos.size() - 1 && nivel == 0) {
            cout << " /" << endl;
        }
    }
}*/
//OPCION 3
/*void imprimirArbol(NodoArbol* raiz, string sede, int nivel = 0) {
    if (!raiz) return;

    if (nivel != 0) {
        for (int i = 0; i < nivel - 1; ++i) {
            cout << "    ";
        }
        cout << "  ";
        if (nivel > 1) {
            cout << "\\__";
        }
    }

    cout << raiz->dato << endl;

    for (size_t i = 0; i < raiz->hijos.size(); ++i) {
        imprimirArbol(raiz->hijos[i], sede, nivel + 1);
        if (i < raiz->hijos.size() - 1 && nivel > 0) {
            cout << endl;
        }
    }
}*/
#define GREEN_COLOR "\033[32m"
#define RED_COLOR "\033[31m"
#define BLUE_COLOR "\033[34m"
#define YELLOW_COLOR "\033[33;1m"
#define RESET_COLOR "\033[0m"

void imprimir_asciiMO() {
    cout << RED_COLOR;
    cout << "     _____                 __                      .__              \n"
        "    /     \\   ____   _____/  |_  __________________|__| ____  ____  \n"
        "   /  \\ /  \\ /  _ \\ /    \\   __\\/ __ \\_  __ \\_  __ \\  |/ ___\\/  _ \\ \n"
        "  /    Y    (  <_> )   |  \\  | \\  ___/|  | \\/|  | \\/  \\  \\__(  <_> )\n"
        "  \\____|__  /\\____/|___|  /__|  \\___  >__|   |__|  |__|\\___  >____/ \n"
        "          \\/            \\/          \\/                     \\/       \n";
    cout << RESET_COLOR;
}
void imprimir_asciiSI() {
    cout << BLUE_COLOR;
    cout << " _________               .___       .__    .___              \n"
        "/   _____/____    ____   |   | _____|__| __| _/______  ____  \n"
        "\\_____  \\\\__  \\  /    \\  |   |/  ___/  |/ __ |\\_  __ \\/  _ \\ \n"
        " /        \\/ __ \\|   |  \\ |   |\\___ \\|  / /_/ | |  | \\(  <_> )\n"
        "/_______  (____  /___|  / |___/____  >__\\____ | |__|   \\____/ \n"
        "        \\/     \\/     \\/           \\/        \\/                \n";
    cout << RESET_COLOR;
}
void imprimir_asciiVILLA() {
    cout << GREEN_COLOR;
    cout << " ____   ____.___.____    .____       _____   \n"
        "\\   \\ /   /|   |    |   |    |     /  _  \\  \n"
        " \\   Y   / |   |    |   |    |    /  /_\\  \\ \n"
        "  \\     /  |   |    |___|    |___/    |    \\\n"
        "   \\___/   |___|_______ \\_______ \\____|__  /\n"
        "                       \\/       \\/       \\/ \n";
    cout << RESET_COLOR;
}
void imprimir_asciiSM() {
    cout << YELLOW_COLOR;
    cout << "   _________                  _____  .__                     .__   \n"
        "  /   _____/____    ____     /     \\ |__| ____  __ __   ____ |  |  \n"
        "  \\_____  \\\\__  \\  /    \\   /  \\ /  \\|  |/ ___\\|  |  \\_/ __ \\|  |  \n"
        "  /        \\/ __ \\|   |  \\ /    Y    \\  / /_/  >  |  /\\  ___/|  |__\n"
        " /_______  (____  /___|  / \\____|__  /__\\___  /|____/  \\___  >____/\n"
        "         \\/     \\/     \\/          \\/  /_____/             \\/      \n";
    cout << RESET_COLOR;
}
void imprimirArbol(NodoArbol* raiz, string sede, int profundidad = 0) {


    if (!raiz) return;

    // Imprimir los hijos de la raíz a los lados del padre
    if (raiz->hijos.size() > 0) {
        imprimirArbol(raiz->hijos[0], sede, profundidad + 1);
    }

    for (int i = 0; i < profundidad; ++i) {
        cout << "  " << "      ";
    }
    cout << "  " << " |_> " << raiz->dato << endl;
    for (size_t i = 1; i < raiz->hijos.size(); ++i) {
        ;
        // Imprimir los hijos a la derecha del padre
        imprimirArbol(raiz->hijos[i], sede, profundidad + 1);
    }
}
//OPCION 5
/*void imprimirArbol(NodoArbol* raiz, string sede, int profundidad = 0) {
    if (!raiz) return;

    // Imprimir los hijos de la raíz a la izquierda del padre
    imprimirArbol(raiz->hijos.size() > 0 ? raiz->hijos[0] : nullptr, sede, profundidad + 1);

    // Espacios de indentación y línea vertical
    for (int i = 0; i < profundidad - 1; ++i) {
        cout << (i == profundidad - 2 ? "|" : " ") << "      ";
    }

    // Imprimir el nodo actual
    cout << (profundidad ? "|---> " : "") << raiz->dato << endl;

    // Imprimir los hijos a la derecha del padre
    for (size_t i = 1; i < raiz->hijos.size(); ++i) {
        imprimirArbol(raiz->hijos[i], sede, profundidad + 1);
    }
}*/

// recorriendo el árbol respecto a su ancho.
void porExtension(NodoArbol* raiz, string sede) {
    if (!raiz) return;

    vector<NodoArbol*> nodosP;
    nodosP.push_back(raiz);

    for (size_t i = 0; i < nodosP.size(); ++i) {
        NodoArbol* actual = nodosP[i];

        cout << actual->dato << " ";

        for (NodoArbol* hijo : actual->hijos) {
            nodosP.push_back(hijo);
        }
    }

    cout << "(" << sede << ")" << endl;
}

//realizan recorridos en inorden y postorden respectivamente, 
// mostrando los valores de los nodos en ese orden.
// Inorden
void postorden(NodoArbol* raiz) {
    if (!raiz) return;

    for (NodoArbol* hijo : raiz->hijos) {
        postorden(hijo);
    }

    cout << raiz->dato << " ";
}

void preorden(NodoArbol* raiz) {
    if (!raiz) return;

    cout << raiz->dato << " ";

    for (NodoArbol* hijo : raiz->hijos) {
        preorden(hijo);
    }
}

void inorden(NodoArbol* raiz) {
    if (!raiz) return;

    if (raiz->hijos.size() >= 1) {
        inorden(raiz->hijos[0]);
    }

    cout << raiz->dato << " ";

    for (int i = 1; i < raiz->hijos.size(); ++i) {
        inorden(raiz->hijos[i]);
    }
}

void titulo(string sede) {
    cout << "Ruta " << sede << endl;
}

void destinoSI(string sede) {
    int numNodos;

    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    NodoArbol* arbol = generarArbolAleatorio(numNodos);
    titulo("San Isidro");
    Console::SetCursorPosition(0, 3);
    imprimir_asciiSI();
    Console::SetCursorPosition(51, 15);
    cout << "          .--------._";
    Console::SetCursorPosition(51, 16);
    cout << "         (`--'       `-.";
    Console::SetCursorPosition(51, 17);
    cout << "          `.______      `.";
    Console::SetCursorPosition(51, 18);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 19);
    cout << "    ,-'           `-.\\     |";
    Console::SetCursorPosition(51, 20);
    cout << "   //  _______ \\|    |\\";
    Console::SetCursorPosition(51, 21);
    cout << "   `--'       `-.              ";
    Console::SetCursorPosition(51, 22);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 23);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(51, 24);
    cout << "   //  _______ \\|           |\\";
    Console::SetCursorPosition(51, 25);
    cout << "   `--'       `-.               ";
    Console::SetCursorPosition(51, 26);
    cout << "         ________`     \\";
    Console::SetCursorPosition(51, 27);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(54, 28);
    cout << " //  _______ \\|           |\\";
    Console::SetCursorPosition(54, 29);
    cout << " `--'       `-.               ";
    Console::SetCursorPosition(54, 30);
    cout << "          .-----/";
    Console::SetCursorPosition(54, 31);
    cout << "         (`--'              /";
    Console::SetCursorPosition(54, 32);
    cout << "          `.______________/";

    
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 11);
    cout << " .:::::::::::::::::::::::::::::::::::::::::::::::::::.";
    Console::SetCursorPosition(0, 12);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";
    Console::SetCursorPosition(0, 13);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 14);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 15);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 16);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 17);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 18);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 19);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 20);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 21);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 22);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 23);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 24);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 25);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 26);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 27);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 28);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 29);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 30);
    cout << "||::::::::::::::::::::::::::o:::::::::::::::::::::::||";
    Console::SetCursorPosition(0, 31);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";

    Console::SetCursorPosition(2, 14);
    imprimirArbol(arbol, sede);
    cout << endl;
    Console::SetCursorPosition(0, 33);
    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;


    cout << "DESTINO: Sede San Isidro (padre): " << arbol->dato << endl;
    cout << "    Av. Canevaro: " << arbol->hijos[0]->dato << endl << endl;


    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Jr. Nazca : " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     -Av. Santa Cruz: " << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Av. Salaverry: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Jr Garcilazo de la Vega: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) {
        cout << endl;
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Av. Guillermo Prescott " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Jr. Jorge Chavez: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Jr. Yoque Yupanqui " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Av. San Felipe " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Av.Gral Salaverry: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Av.Guillermo Prescott " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Jr. Yoque Yupanqui: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Jr. C Daniel Ochea: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Jr. Huiracocha: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Jr. Cadiz: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }


    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en preorden:" << endl;
    preorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}

void destinoMO(string sede) {
    int numNodos;
    cout << "Ingrese la cantidad de nodos: ";
    cin >> numNodos;

    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    NodoArbol* arbol = generarArbolAleatorio(numNodos);
    titulo("Monterrico");
    Console::SetCursorPosition(0, 2);
    imprimir_asciiMO();
    Console::SetCursorPosition(51, 15);
    cout << "          .--------._";
    Console::SetCursorPosition(51, 16);
    cout << "         (`--'       `-.";
    Console::SetCursorPosition(51, 17);
    cout << "          `.______      `.";
    Console::SetCursorPosition(51, 18);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 19);
    cout << "    ,-'           `-.\\     |";
    Console::SetCursorPosition(51, 20);
    cout << "   //  _______ \\|    |\\";
    Console::SetCursorPosition(51, 21);
    cout << "   `--'       `-.              ";
    Console::SetCursorPosition(51, 22);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 23);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(51, 24);
    cout << "   //  _______ \\|           |\\";
    Console::SetCursorPosition(51, 25);
    cout << "   `--'       `-.               ";
    Console::SetCursorPosition(51, 26);
    cout << "         ________`     \\";
    Console::SetCursorPosition(51, 27);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(54, 28);
    cout << " //  _______ \\|           |\\";
    Console::SetCursorPosition(54, 29);
    cout << " `--'       `-.               ";
    Console::SetCursorPosition(54, 30);
    cout << "          .-----/";
    Console::SetCursorPosition(54, 31);
    cout << "         (`--'              /";
    Console::SetCursorPosition(54, 32);
    cout << "          `.______________/";
    
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 11);
    cout << " .:::::::::::::::::::::::::::::::::::::::::::::::::::.";
    Console::SetCursorPosition(0, 12);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";
    Console::SetCursorPosition(0, 13);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 14);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 15);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 16);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 17);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 18);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 19);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 20);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 21);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 22);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 23);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 24);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 25);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 26);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 27);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 28);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 29);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 30);
    cout << "||::::::::::::::::::::::::::o:::::::::::::::::::::::||";
    Console::SetCursorPosition(0, 31);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";

    Console::SetCursorPosition(2, 14);
    imprimirArbol(arbol, sede);
    cout << endl;
    Console::SetCursorPosition(0, 33);
    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;

    //muestra clase padre
    cout << "DESTINO: Sede Monterrico (padre): " << arbol->dato << endl;
    cout << "    Santiago de Surco: " << arbol->hijos[0]->dato << endl << endl;

    //se analiza si el primer hijo (0) tiene un hijo)
    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Av. 28 de Julio: " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    //mismo proceso para los demás
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     -Via Expresa: " << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Cta. Panamericana S: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Av. Dervy: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) {
        //comprobacion para que se cumpla para cada hijo
        cout << endl; //linea en blanco para separar de la siguiente ruta
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Santiago de Surco " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Av. Horacio Orteaga: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Av. 28 de Julio: " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Av. Angamos Este: " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Av Primavera: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Santiago de Surco " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Av.28 de Julio: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Via Expresa: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Av. Manuel Olguin: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Av. Lima Polo: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }


    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en preorden:" << endl;
    preorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}
void destinoVilla(string sede) {
    int numNodos;
    cout << "Ingrese la cantidad de nodos: ";
    cin >> numNodos;

    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    NodoArbol* arbol = generarArbolAleatorio(numNodos);
    titulo("Villa");
    Console::SetCursorPosition(0, 2);
    imprimir_asciiVILLA();
    Console::SetCursorPosition(51, 15);
    cout << "          .--------._";
    Console::SetCursorPosition(51, 16);
    cout << "         (`--'       `-.";
    Console::SetCursorPosition(51, 17);
    cout << "          `.______      `.";
    Console::SetCursorPosition(51, 18);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 19);
    cout << "    ,-'           `-.\\     |";
    Console::SetCursorPosition(51, 20);
    cout << "   //  _______ \\|    |\\";
    Console::SetCursorPosition(51, 21);
    cout << "   `--'       `-.              ";
    Console::SetCursorPosition(51, 22);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 23);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(51, 24);
    cout << "   //  _______ \\|           |\\";
    Console::SetCursorPosition(51, 25);
    cout << "   `--'       `-.               ";
    Console::SetCursorPosition(51, 26);
    cout << "         ________`     \\";
    Console::SetCursorPosition(51, 27);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(54, 28);
    cout << " //  _______ \\|           |\\";
    Console::SetCursorPosition(54, 29);
    cout << " `--'       `-.               ";
    Console::SetCursorPosition(54, 30);
    cout << "          .-----/";
    Console::SetCursorPosition(54, 31);
    cout << "         (`--'              /";
    Console::SetCursorPosition(54, 32);
    cout << "          `.______________/";
 
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 11);
    cout << " .:::::::::::::::::::::::::::::::::::::::::::::::::::.";
    Console::SetCursorPosition(0, 12);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";
    Console::SetCursorPosition(0, 13);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 14);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 15);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 16);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 17);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 18);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 19);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 20);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 21);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 22);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 23);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 24);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 25);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 26);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 27);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 28);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 29);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 30);
    cout << "||::::::::::::::::::::::::::o:::::::::::::::::::::::||";
    Console::SetCursorPosition(0, 31);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";

    Console::SetCursorPosition(2, 14);
    imprimirArbol(arbol, sede);
    cout << endl;
    Console::SetCursorPosition(0, 33);
    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;

    cout << "DESTINO: Sede Villa (padre): " << arbol->dato << endl;
    cout << "    Av. Jose Lavalle: " << arbol->hijos[0]->dato << endl << endl;

    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Vía Expresa: " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     -Quebrada de Armendariz: " << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Chorrillos La Herradura: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Av. José Antonio Lavalle: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) {
        cout << endl;
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Av. Jose Antonio Lavalle " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Av. Paseo de la republica: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Via Expresa: " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Quebrada de Armendatriz: " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Chorrillos de la Herradura: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Av. Alameda " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Av. Salaverry: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Av. Republica de Panama: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Av. Caminos del Inca: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Av. Jose Antonio Lavalle: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en preorden:" << endl;
    preorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}
void destinoSM(string sede) {
    int numNodos;
    cout << "Ingrese la cantidad de nodos: ";
    cin >> numNodos;

    do {
        cout << "Ingrese la cantidad de nodos: ";
        cin >> numNodos;
        if (numNodos < 10 || numNodos > 15) {
            cout << "La cantidad de nodos debe estar entre 10 y 15" << endl;
        }
    } while (numNodos < 10 || numNodos > 15);

    NodoArbol* arbol = generarArbolAleatorio(numNodos);
    titulo("San Miguel");
    Console::SetCursorPosition(0, 2);
    imprimir_asciiSM();
    Console::SetCursorPosition(51, 15);
    cout << "          .--------._";
    Console::SetCursorPosition(51, 16);
    cout << "         (`--'       `-.";
    Console::SetCursorPosition(51, 17);
    cout << "          `.______      `.";
    Console::SetCursorPosition(51, 18);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 19);
    cout << "    ,-'           `-.\\     |";
    Console::SetCursorPosition(51, 20);
    cout << "   //  _______ \\|    |\\";
    Console::SetCursorPosition(51, 21);
    cout << "   `--'       `-.              ";
    Console::SetCursorPosition(51, 22);
    cout << "       ___________`__     \\";
    Console::SetCursorPosition(51, 23);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(51, 24);
    cout << "   //  _______ \\|           |\\";
    Console::SetCursorPosition(51, 25);
    cout << "   `--'       `-.               ";
    Console::SetCursorPosition(51, 26);
    cout << "         ________`     \\";
    Console::SetCursorPosition(51, 27);
    cout << "    ,-'           `-.   \\     |";
    Console::SetCursorPosition(54, 28);
    cout << " //  _______ \\|           |\\";
    Console::SetCursorPosition(54, 29);
    cout << " `--'       `-.               ";
    Console::SetCursorPosition(54, 30);
    cout << "          .-----/";
    Console::SetCursorPosition(54, 31);
    cout << "         (`--'              /";
    Console::SetCursorPosition(54, 32);
    cout << "          `.______________/";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(0, 11);
    cout << " .:::::::::::::::::::::::::::::::::::::::::::::::::::.";
    Console::SetCursorPosition(0, 12);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";
    Console::SetCursorPosition(0, 13);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 14);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 15);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 16);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 17);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 18);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 19);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 20);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 21);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 22);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 23);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 24);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 25);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 26);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 27);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 28);
    cout << "                                                      ";
    Console::SetCursorPosition(0, 29);
    cout << "|:                                                  :|";
    Console::SetCursorPosition(0, 30);
    cout << "||::::::::::::::::::::::::::o:::::::::::::::::::::::||";
    Console::SetCursorPosition(0, 31);
    cout << " ::::::::::::::::::::::::.....::::::::::::::::::::::::";

    Console::SetCursorPosition(2, 14);
    imprimirArbol(arbol, sede);
    cout << endl;
    Console::SetCursorPosition(0, 33);
    cout << "Elementos de la \"T\" por extension:" << endl;
    porExtension(arbol, sede);
    cout << endl;

    cout << "DESTINO: San Miguel (padre): " << arbol->dato << endl;
    cout << "    Av. Auxiliar de la Marina: " << arbol->hijos[0]->dato << endl << endl;

    if (arbol->hijos[0]->hijos.size() >= 1) {
        cout << "     -Av. Talara: " << arbol->hijos[0]->hijos[0]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 2) {
        cout << "     -Av. Mariano Cornejo:  " << arbol->hijos[0]->hijos[1]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 3) {
        cout << "     -Av. Universitaria: " << arbol->hijos[0]->hijos[2]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() >= 4) {
        cout << "     -Av. Marina: " << arbol->hijos[0]->hijos[3]->dato << endl;
    }
    if (arbol->hijos[0]->hijos.size() > 0 && arbol->hijos[0]->hijos.size() <= 4) {
        cout << endl;
    }

    if (arbol->hijos.size() >= 2) {
        cout << "    Auxiliar Av. La Marina " << arbol->hijos[1]->dato << endl << endl;
        if (arbol->hijos[1]->hijos.size() >= 1) {
            cout << "     -Av. Arnaldo Marquez: " << arbol->hijos[1]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 2) {
            cout << "     -Av. Brasil: " << arbol->hijos[1]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 3) {
            cout << "     -Av. La Mar: " << arbol->hijos[1]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() >= 4) {
            cout << "     -Av. Marina: " << arbol->hijos[1]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[1]->hijos.size() > 0 && arbol->hijos[1]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    if (arbol->hijos.size() >= 3) {
        cout << "    Auxiliar Av. La Marina " << arbol->hijos[2]->dato << endl << endl;
        if (arbol->hijos[2]->hijos.size() >= 1) {
            cout << "     -Av. Arnaldo Marques: " << arbol->hijos[2]->hijos[0]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 2) {
            cout << "     -Av. Francisco Javier Mariategui: " << arbol->hijos[2]->hijos[1]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 3) {
            cout << "     -Av. Brasil: " << arbol->hijos[2]->hijos[2]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() >= 4) {
            cout << "     -Av. Marina: " << arbol->hijos[2]->hijos[3]->dato << endl;
        }
        if (arbol->hijos[2]->hijos.size() > 0 && arbol->hijos[2]->hijos.size() <= 4) {
            cout << endl;
        }
    }

    cout << "Recorrido en inorden:" << endl;
    inorden(arbol);
    cout << endl;

    cout << "Recorrido en preorden:" << endl;
    preorden(arbol);
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    postorden(arbol);
    cout << endl;
}

void marco() {
    char letra1 = 205;
    char letra2 = 186;
    char letra3 = 201;
    char letra4 = 187;
    char letra5 = 200;
    char letra6 = 188;

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 1; i <= 85; i++)
    {
        Console::SetCursorPosition(i, 1);
        cout << letra1;
        Console::SetCursorPosition(i, 28);
        cout << letra1;
    }
    for (int b = 2; b < 28; b++)
    {
        Console::SetCursorPosition(1, b);
        cout << letra2;
        Console::SetCursorPosition(85, b);
        cout << letra2;
    }
    Console::SetCursorPosition(1, 1);
    cout << letra3;
    Console::SetCursorPosition(85, 1);
    cout << letra4;
    Console::SetCursorPosition(1, 28);
    cout << letra5;
    Console::SetCursorPosition(85, 28);
    cout << letra6;
}

void marco2() {

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 1; i <= 85; i++)
    {
        Console::SetCursorPosition(i, 1);
        cout << "_";
        Console::SetCursorPosition(i, 28);
        cout << "_";
    }
    for (int b = 2; b < 28; b++)
    {
        Console::SetCursorPosition(1, b);
        cout << "|";
        Console::SetCursorPosition(85, b);
        cout << "|";
    }
    Console::SetCursorPosition(1, 1);
    cout << "+";
    Console::SetCursorPosition(85, 1);
    cout << "+";
    Console::SetCursorPosition(1, 28);
    cout << "+";
    Console::SetCursorPosition(85, 28);
    cout << "+";
}

void marco3() {

    Console::SetWindowSize(87, 30);
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    for (int i = 15; i <= 70; i++)
    {
        Console::SetCursorPosition(i, 13);
        cout << "_";
        Console::SetCursorPosition(i, 26);
        cout << "_";
    }
    for (int b = 14; b < 26; b++)
    {
        Console::SetCursorPosition(15, b);
        cout << "|";
        Console::SetCursorPosition(70, b);
        cout << "|";
    }
    Console::SetCursorPosition(15, 13);
    cout << "+";
    Console::SetCursorPosition(70, 13);
    cout << "+";
    Console::SetCursorPosition(15, 26);
    cout << "+";
    Console::SetCursorPosition(70, 26);
    cout << "+";
}


void Titulo() {
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(16, 3);
    cout << " _______            __  __     " << endl;
    Console::SetCursorPosition(16, 4);
    cout << "|__   __|          |  \\/  |    " << endl;
    Console::SetCursorPosition(16, 5);
    cout << "   | |_ __ ___  ___| \\  / | __ _ _ __  _ __   ___ _ __ " << endl;
    Console::SetCursorPosition(16, 6);
    cout << "   | | '__/ _ \\/ _ \\ |\\/| |/ _` | '_ \\| '_ \\ / _ \\ '__|" << endl;
    Console::SetCursorPosition(16, 7);
    cout << "   | | | |  __/  __/ |  | | (_| | |_) | |_) |  __/ |   " << endl;
    Console::SetCursorPosition(16, 8);
    cout << "   |_|_|  \\___|\\___|_|  |_|\\__,_| .__/| .__/ \\___|_|   " << endl;
    Console::SetCursorPosition(15, 9);
    cout << "                                 | |   | |              " << endl;
    Console::SetCursorPosition(15, 10);
    cout << "                                 |_|   |_|              " << endl;

}

void Bordeinterior() {
    char letra1 = 205;
    char letra2 = 186;
    char letra3 = 201;
    char letra4 = 187;
    char letra5 = 200;
    char letra6 = 188;

    for (int i = 15; i < 70; i++)
    {
        Console::SetCursorPosition(i, 12);
        cout << letra1;
        Console::SetCursorPosition(i, 25);
        cout << letra1;
    }
    for (int b = 13; b < 25; b++)
    {
        Console::SetCursorPosition(15, b);
        cout << letra2;
        Console::SetCursorPosition(70, b);
        cout << letra2;
    }
    Console::SetCursorPosition(15, 12);
    cout << letra3;
    Console::SetCursorPosition(70, 12);
    cout << letra4;
    Console::SetCursorPosition(15, 25);
    cout << letra5;
    Console::SetCursorPosition(70, 25);
    cout << letra6;
}
void menu() {
    char opcion;
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(76, 3);
    cout << "&&&";
    Console::SetCursorPosition(75, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(74, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(73, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(74, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(74, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(76, 9);
    cout << "}{{";
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(7, 3);
    cout << "&&&";
    Console::SetCursorPosition(6, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(5, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(4, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(5, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(5, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(7, 9);
    cout << "}{{";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(33, 10);
    cout << " .:::::::::::::::.";
    Console::SetCursorPosition(33, 11);
    cout << " ::::::.....::::::";
    Console::SetCursorPosition(33, 12);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 13);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 14);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 15);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 16);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 17);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 18);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 19);
    cout << "||:::::::::::::::||";
    Console::SetCursorPosition(33, 20);
    cout << "°:::::......::::::° ";



    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(30, 3);
    cout << " __  __              __";
    Console::SetCursorPosition(29, 4);
    cout << " |  \\/  |            /_/  ";
    Console::SetCursorPosition(29, 5);
    cout << " | \\  / | ___ _ __  _   _ ";
    Console::SetCursorPosition(29, 6);
    cout << " | |\\/| |/ _ \\ '_ \\| | | |";
    Console::SetCursorPosition(29, 7);
    cout << " | |  | |  __/ | | | |_| |";
    Console::SetCursorPosition(29, 8);
    cout << " |_|  |_|\\___|_| |_|\\__,_|";
    Console::SetCursorPosition(27, 22);
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "Digite el número de opción a realizar";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(35, 24);
    cout << "1) TreeMapper";
    Console::SetCursorPosition(35, 25);
    cout << "2) Instrucciones";
    Console::SetCursorPosition(35, 26);
    cout << "3) Salir";
}
void arbolito()
{
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(40, 13);
    cout << "####o#";
    Console::SetCursorPosition(36, 14);
    cout << "#o# \\# | _#,#";
    Console::SetCursorPosition(36, 15);
    cout << "###\\|/ # #o#";
    Console::SetCursorPosition(36, 16);
    cout << " ## {} {## #";
    Console::SetCursorPosition(39, 17);
    cout << " } { {";
    Console::SetCursorPosition(39, 18);
    cout << " , '  `";

}

void decoracion()
{

    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(76, 3);
    cout << "&&&";
    Console::SetCursorPosition(75, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(74, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(73, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(74, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(74, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(76, 9);
    cout << "}{{";
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(7, 3);
    cout << "&&&";
    Console::SetCursorPosition(6, 4);
    cout << "&&&/&";
    Console::SetCursorPosition(5, 5);
    cout << "&\/&|&&&&";
    Console::SetCursorPosition(4, 6);
    cout << "&&&\&|&/&&&";
    Console::SetCursorPosition(5, 7);
    cout << "&&&\|/&&&";
    Console::SetCursorPosition(5, 8);
    cout << "& }}{  &";
    Console::SetCursorPosition(7, 9);
    cout << "}{{";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(33, 2);
    cout << " .:::::::::::::::.";
    Console::SetCursorPosition(33, 3);
    cout << " ::::::.....::::::";
    Console::SetCursorPosition(33, 4);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 5);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 6);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 7);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 8);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 9);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 10);
    cout << "|:               :|";
    Console::SetCursorPosition(33, 11);
    cout << "||:::::::::::::::||";
    Console::SetCursorPosition(33, 12);
    cout << "°:::::......::::::° ";

    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(40, 5);
    cout << "####o#";
    Console::SetCursorPosition(36, 6);
    cout << "#o# \\# | _#,#";
    Console::SetCursorPosition(36, 7);
    cout << "###\\|/ # #o#";
    Console::SetCursorPosition(36, 8);
    cout << " ## {} {## #";
    Console::SetCursorPosition(39, 9);
    cout << " } { {";
    Console::SetCursorPosition(39, 10);
    cout << " , '  `";


}


void inicio() {
    setlocale(LC_ALL, "spanish");
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(37, 14);
    cout << "Integrantes" << endl;
    Console::SetCursorPosition(17, 15);
    cout << "----------------------------------------------------" << endl;
    Console::SetCursorPosition(17, 16);
    cout << "1. Sotomayor Barrios Lucas - U202323168" << endl;
    Console::SetCursorPosition(17, 17);
    cout << "2. Choquehuanca Núñez Luciana Carolina - U202319431" << endl;
    Console::SetCursorPosition(17, 18);
    cout << "3. Chacaliaza Vilca Christian Bernabe - U202318745" << endl;
    Console::SetCursorPosition(17, 19);
    cout << "4. Durand Valente Gabriela Andrea - U202311957" << endl;
    Console::SetCursorPosition(17, 20);
    cout << "5. Ventura Saldaña William Agustín - U202310536" << endl;
    Console::SetCursorPosition(17, 24);
    cout << "Presione dos veces Enter para empezar el programa..." << endl;
    while (cin.get() != '\n') {}
    system("cls");
}

void reloj(int x)
{
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < 4); //SEGUNDOS PARA QUE CARGUE EL PROGRAMA ;)
}


void instrucciones() {


    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(20, 2);
    cout << " _____          _                       _                        ";
    Console::SetCursorPosition(20, 3);
    cout << "|_   _|        | |                     (_)                       ";
    Console::SetCursorPosition(20, 4);
    cout << "  | | _ __  ___| |_ _ __ _   _  ___ ___ _  ___  _ __   ___  ___  ";
    Console::SetCursorPosition(20, 5);
    cout << "  | || '_ \\/ __| __| '__| | | |/ __/ __| |/ _ \\| '_ \\ / _ \\/ __| ";
    Console::SetCursorPosition(20, 6);
    cout << " _| || | | \\__ \\ |_| |  | |_| | (_| (__| | (_) | | | |  __/ \\__\\ ";
    Console::SetCursorPosition(20, 7);
    cout << " \\___/_| |_|___/\\__|_|   \\__,_|\\___\\___|_| \___/|_| |_|\\___||___/ ";

    // ahora lo que dirán las instrucciones

    Console::SetCursorPosition(6, 9);
    Console::ForegroundColor = ConsoleColor::White;
    cout << "~Instrucciones de uso~: ";
    Console::SetCursorPosition(7, 10);
    cout << "1. En el menú de inicio, elige la opcion TREEMAPPER.";
    Console::SetCursorPosition(7, 11);
    cout << "2. Espera unos segundos.";
    Console::SetCursorPosition(7, 12);
    cout << "3. Elige el campus de UPC del que quiere saber su mejor ruta. Puede elegir entre las sedes de San Isidro,                Monterrico, Villa y San Miguel.";
    Console::SetCursorPosition(7, 14);
    cout << "4. Ingresa la cantidad de nodos y espera el resultado.";
    Console::SetCursorPosition(7, 16);
    cout << "5. Ya tienes el resultado de la ruta más rapida para el campus elegido.";
    Console::SetCursorPosition(7, 18);
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "ADVERTENCIA:  Debe poner una cantidad entre 10 a 15 nodos para el correcto funcionamiento del programa.";

    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(6, 20);
    cout << "~Funcion de TREEMAPPER~";
    Console::SetCursorPosition(7, 21);
    cout << "TREEMAPPER es un software de busqueda de árboles y basada en árboles. El objetivo de esta aplicación es poder           encontrar las rutas más rapidas a las sedes de UPC evitando árboles por el camino.";
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(7, 24);
    cout << "Presione dos veces el número 1 en su teclado para ir a TREEMAPPER o dos veces el número 3 para salir.";
}


int main() {
    Bordeinterior();
    marco();
    Titulo();
    inicio();

    do {
        while (!kbhit()) {}
        char c = getch();
        if (c == '\r') {
            system("cls");
            break;
        }
    } while (true);

    marco2();
    menu();
    arbolito();


    bool salir = false;
    char opcion;

    while (!salir) {
        opcion = _getch();
        int sedeOption;
        string sede;

        switch (opcion) {
        case '1':
            Console::SetCursorPosition(17, 27);
            cout << "Has seleccionado ejecutar TreeMapper. Espere un momento.\n";
            reloj(4);
            system("cls");
            marco2();
            Console::SetCursorPosition(20, 3);
            Console::ForegroundColor = ConsoleColor::White;
            srand(time(NULL));
            marco3();
            decoracion();
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(19, 16);
            cout << "Seleccione la sede :" << endl;
            Console::SetCursorPosition(18, 17);
            Console::ForegroundColor = ConsoleColor::Red;
            cout << "(Presione el numero de opcion y despues enter)" << endl;
            Console::SetCursorPosition(20, 18);
            Console::ForegroundColor = ConsoleColor::White;
            cout << "1. SI - Sede San Isidro" << endl;
            Console::SetCursorPosition(20, 19);
            cout << "2. MO - Sede Monterrico" << endl;
            Console::SetCursorPosition(20, 20);
            cout << "3. Villa - Sede Villa" << endl;
            Console::SetCursorPosition(20, 21);
            cout << "4. SM - Sede San Miguel" << endl;
            Console::SetCursorPosition(20, 22);
            cin >> sedeOption;
            Console::Clear();

            switch (sedeOption) {
            case 1:
                sede = "SI";
                destinoSI(sede);
                break;
            case 2:
                sede = "MO";
                destinoMO(sede);
                break;
            case 3:
                sede = "Villa";
                destinoVilla(sede);
                break;
            case 4:
                sede = "SM";
                destinoSM(sede);
                break;
            default:
                cout << "Opción inválida." << endl;
                return 1;
            }
            _getch();
            break;
        case '2':
            Console::SetCursorPosition(15, 27);
            cout << "Has seleccionado la opción instrucciones. Espere un momento.\n";
            reloj(4);
            system("cls");
            instrucciones();
            _getch();
            break;
        case '3':
            Console::SetCursorPosition(25, 27);
            cout << "Has seleccionado la opción salir. Espere un momento.\n";
            reloj(4);
            system("cls");
            Console::ForegroundColor = ConsoleColor::DarkGreen;
            Console::SetCursorPosition(40, 8);
            cout << "GRACIAS POR SU ATENCION" << endl;
            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(40, 10);
            cout << " atentamente, grupo 9" << endl;
            reloj(2);
            salir = true;
            break;
        default:
            Console::SetCursorPosition(17, 27);
            cout << "Opción no válida. Por favor, selecciona una opción válida.\n";
            _getch();
            break;
        }
    }
    return 0;
}
