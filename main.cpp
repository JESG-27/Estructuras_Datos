#include <iostream>

// Estructuras
#include "ArregloDinamico.h"
#include "ListaLiga.h"
#include "listadobleligada.h"
#include "ListaCircular.h"
#include "pila.h"
#include "cola.h"
#include "Arbol.h"
#include "Grafo.h"


#include "Estructuras.h"
using namespace std;

int main()
{
    string opc;
    while (true)
    {
        cout << endl << "<<< Estructuras de Datos >>>" << endl;
        cout << "1) Arreglo Dinamico" << endl;
        cout << "2) Lista Simplemente Ligada" << endl;
        cout << "3) Lista Doblemente Ligada" << endl;
        cout << "4) Listas Circulares" << endl;
        cout << "5) Pila" << endl;
        cout << "6) Cola" << endl;
        cout << "7) Arbol Binario de Busqueda" << endl;
        cout << "8) Grafo" << endl;
        cout << "0) Salir" << endl;
        cout << endl;
        cout << ": ";
        getline(cin, opc);

        if (opc == "1")
        {
            menuArreglo();
        }

        else if (opc == "2")
        {
            cout << "Ejemplo Lista Simplemente Ligada" << endl;
            ListaSimple();
        }

        else if (opc == "3")
        {
            cout << "Ejemplo Lista Doblemente Ligada" << endl;
            ListaDoble();
        }

        else if (opc == "4")
        {
            cout << "Ejemplo Lista Circular" << endl;
            ListaCir();
        }

        else if (opc == "5")
        {
            menuPila();
        }

        else if (opc == "6")
        {
            menuCola();
        }

        else if (opc == "7")
        {
            ArbolBin();
        }

        else if (opc == "8")
        {
            funGrafo();
        }

        else if (opc == "0")
        {
            break;
        }

        system ("PAUSE");
        system ("CLS");
    }
    
    return 0;
}
