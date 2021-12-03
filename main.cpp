#include <iostream>

// Estructuras
#include "ArregloDinamico.h"
#include "ListaLiga.h"
#include "listadobleligada.h"


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
            system("PAUSE");
            system("CLS");
        }

        else if (opc == "2")
        {
            cout << "Ejemplo Lista Simplemente Ligada" << endl;
            ListaSimple();
            system("PAUSE");
            system("CLS");
        }

        else if (opc == "3")
        {
            cout << "Ejemplo Lista Doblemente Ligada" << endl;
            ListaDoble();
            system("PAUSE");
            system("CLS");
        }

        else if (opc == "5")
        {
            Pila();
            system("PAUSE");
            system("CLS");
        }


        else if (opc == "0")
        {
            break;
        }
    }
    
    return 0;
}
