#include <iostream>
#include <stack>
#include <list>

using namespace std;


///////////////////////////////////////////////////////////////////////////////// Arreglo Dinamico //////////////////////////////////////////////////////////////////////////////
void menuArreglo()
{
    ArregloDinamico<string> arreglo;
            int opc;
            
            while (true)
            {
                cout << "Arreglo Dinamico de Strings" << endl;
                cout << "1) Agregar Inicio" << endl;
                cout << "2) Agregar Final" << endl;
                cout << "3) Agregar Posicion" << endl;
                cout << "4) Eliminar Inicio" << endl;
                cout << "5) Eliminar Final" << endl;
                cout << "6) Eliminar Posicion" << endl;
                cout << "7) Mostrar" << endl;
                cout << "0) Salir" << endl;
                cin >> opc; cin.ignore();

                if (opc == 1)
                {
                    string pal;
                    cout << "String: ";
                    getline(cin, pal);
                    arreglo.insertar_inicio(pal);
                }

                else if (opc == 2)
                {
                    string pal;
                    cout << "String: ";
                    getline(cin, pal);
                    arreglo.insertar_final(pal);
                }

                else if (opc == 3)
                {
                    string pal;
                    size_t pos;
                    cout << "String: ";
                    getline(cin, pal);
                    cout << "Posicion: ";
                    cin >> pos; cin.ignore();
                    arreglo.insertar(pal, pos);
                }

                else if (opc == 4)
                {
                    arreglo.eliminar_inicio();
                }

                else if (opc == 5)
                {
                    arreglo.eliminar_final();
                }

                else if (opc == 6)
                {
                    size_t pos;
                    cout << "Posicion: ";
                    cin >> pos; cin.ignore();
                    arreglo.eliminar(pos);
                }

                else if (opc == 7)
                {
                    cout << "Elementos: " << arreglo.size() << endl;
                    arreglo.mostrar();
                    cout << endl;
                }

                else if (opc == 0)
                {
                    break;
                }

                system("PAUSE");
                system("CLS");
            }
}

//////////////////////////////////////////////////////////////////////////// Lista Simplemente Ligada ///////////////////////////////////////////////////////////////////////////
void ListaSimple()
{
    ListaLigada<int> lista;

    lista.push_front(10);                                       // insertar al inicio (frente)
    lista.push_front(0);                                        // insertar al inicio (frente)
    lista.push_front(4);                                        // insertar al inicio (frente)

    lista.push_back(7);                                         // insertar al final (cola)
    lista.push_back(8);                                         // insertar al final (cola)

    cout << "Enteros insertardos al inicio: 10, 0, 4" << endl;
    cout << "Enteros insertardos al final: 7, 8" << endl;

    cout << "Cantidad: " << lista.size() << endl;               // imprime la cantidad de nodos (elementos)
    
    lista.pop_back();                                           // elimina el ultimo (cola)
    cout << "Se elimina el ultimo nodo" << endl;

    cout << "Cantidad: " << lista.size() << endl;               // imprime la cantidad de nodos (elementos)
    lista.print();                                              // recorre la lista e imprime cada nodo (elemento)

    cout << "Se eliminan los nodos" << endl; 
    lista.~ListaLigada();                                       // se eliminan todos los nodos
    cout << "Cantidad: " << lista.size() << endl;               // imprime la cantidad de nodos (elementos)

}

//////////////////////////////////////////////////////////////////////////// Lista Doblemente Ligada ///////////////////////////////////////////////////////////////////////////
void ListaDoble()
{
    ListaDobleLigada<int> enteros;

    enteros.push_front(3);
    enteros.push_front(2);
    enteros.push_front(1);

    enteros << 1 << 5 << 1;
    cout << "Enteros insertados al inicio: 3, 2, 1, 1, 5, 1" << endl;

    cout << "Cantidad: " << enteros.size() << endl;                 // imprime la cantidad de nodos (elementos)

    cout << "Elementos de la lista: " << endl;
    enteros.print();                                                // imprime el elemento de cada nodo

    enteros.remove_if(1);                                           // elimina todos los nodos que almacenan el 1

    cout << "Elimina todos los nodos que almacenan el 1" << endl;
    cout << "Cantidad: " << enteros.size() << endl;                 // imprime la cantidad de nodos (elementos)


    cout << "Elementos de la lista: " << endl;
    enteros.print();                                                // imprime el elemento de cada nodo
}

//////////////////////////////////////////////////////////////////////////////////// Pila ///////////////////////////////////////////////////////////////////////////////////// 
void Pila()
{
    stack<int> pila;

    string opc;
    while(true)
    {
        cout << "1) Apilar" << endl;
        cout << "2) Eliminar tope de pila" << endl;
        cout << "3) Mostrar" << endl;
        cout << "0) Salir" << endl;
        cout << ": ";
        getline(cin, opc);

        if (opc == "1")
        {
            int num;
            cout << "Entero: ";
            cin >> num; cin.ignore();
            pila.push(num);
        }

        else if (opc == "2")
        {
            if (!pila.empty())
            {
                pila.pop();
            }
            else if (pila.empty())
            {
                cout << "Pila vacia" << endl;
            }
        }

        else if (opc == "3")
        {
            cout << "Cantidad de Elementos apilados: " << pila.size() << endl;
            while (!pila.empty())
            {
                cout << pila.top() << endl;
                pila.pop();
            }
        }

        else if (opc == "0")
        {
            break;
        }

        system("PAUSE");
        system("CLS");
    }
}