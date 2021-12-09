#include <iostream>

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
                    cout << "Capacidad: " << arreglo.capacidad() << endl;
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
    lista.print();
    
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

    enteros.insert(0, 3);                                           // Insertar un 0 en la posicion 3
    cout << "Se inserta el 0 en la posicion 3"<< endl;
    enteros.print();
    cout << "Cantidad: " << enteros.size() << endl;

    int *ptr_02 = enteros.find(0);                                  // buscar un elemento
    if (ptr_02)
    {         
        *ptr_02 = 10;                                               // Lo cambia por 10
    }
    cout << "Se busca el 0, si lo encuentra lo cambia por un 10" << endl;

    enteros.remove_if(1);                                           // elimina todos los nodos que almacenan el 1

    cout << "Elimina todos los nodos que almacenan el 1" << endl;
    cout << "Cantidad: " << enteros.size() << endl;                 // imprime la cantidad de nodos (elementos)

    cout << "Elementos de la lista: " << endl;
    enteros.print();                                                // imprime el elemento de cada nodo
}

///////////////////////////////////////////////////////////////////////////// Listas Circulares ///////////////////////////////////////////////////////////////////////////////
void ListaCir()
{
    ListaCircular<int> Lista;

    Lista.push_front(4);
    Lista.push_front(3);
    Lista.push_front(2);
    Lista.push_front(1);

    Lista.push_back(5);
    Lista.push_back(6);

    cout << "Enteros insertados al inicio: 4, 3, 2, 1" << endl;
    cout << "Enteros insertados al final: 5, 6" << endl << endl;

    cout << "Cantidad de Nodos: " << Lista.size() << endl;
    Lista.print();

    cout << "Direccion en memoria del 4: " << Lista.find(4) << endl;

    cout << "Nodo anterior del Nodo inicial: ";
    Lista.ant_head();
    cout << endl;
    cout << "Nodo sig del Nodo final: ";
    Lista.sig_tail();
    cout << endl << endl;

    cout << "Elimina el primer y el ultimo nodo" << endl;
    Lista.pop_front();
    Lista.pop_back();

    Lista.print();
    cout << "Nodo anterior del Nodo inicial: ";
    Lista.ant_head();
    cout << endl;
    cout << "Nodo sig del Nodo final: ";
    Lista.sig_tail();
    cout << endl << endl;
}

//////////////////////////////////////////////////////////////////////////////////// Pila ///////////////////////////////////////////////////////////////////////////////////// 
void menuPila()
{
    Pila<int> pila;

    string opc;
    while(true)
    {
        cout << "1) Apilar" << endl;
        cout << "2) Eliminar tope de pila" << endl;
        cout << "3) Desapilar" << endl;
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
                cout << *pila.top() << endl;
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

/////////////////////////////////////////////////////////////////////////////////// Cola //////////////////////////////////////////////////////////////////////////////////////
void menuCola()
{
    Cola<int> cola;

    string opc;
    while(true)
    {
        cout << "1) Encolar" << endl;
        cout << "2) Eliminar frente de cola" << endl;
        cout << "3) Desencolar" << endl;
        cout << "0) Salir" << endl;
        cout << ": ";
        getline(cin, opc);

        if (opc == "1")
        {
            int num;
            cout << "Entero: ";
            cin >> num; cin.ignore();
            cola.push(num);
        }

        else if (opc == "2")
        {
            if (!cola.empty())
            {
                cola.pop();
            }
            else if (cola.empty())
            {
                cout << "Cola vacia" << endl;
            }
        }

        else if (opc == "3")
        {
            cout << "Cantidad de Elementos encolados: " << cola.size() << endl;
            
            while (!cola.empty())
            {
                cout << *cola.front() << endl;
                cola.pop();
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

//////////////////////////////////////////////////////////////////////////////// Arbol Binario ////////////////////////////////////////////////////////////////////////////////
void ArbolBin()
{
    Arbol<int> arbol;
    int valor;

    cout << "Ingrese 10 numeros enteros:" << endl;

    for (size_t i=0; i<10; i++)
    {
        cin >> valor; cin.ignore();
        arbol.InsertarNodo(valor);
    }

    cout << "Recorrido PreOrden" << endl;
    arbol.PreOrden();
    cout << endl;

    cout << "Recorrido InOrden" << endl;
    arbol.InOrden();
    cout << endl;

    cout << "Recorrido PostOrden" << endl;
    arbol.PostOrden();
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////// Grafo ////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream &out, const Grafo &grafo)
{
    for (auto const &vertice: grafo) {
        out << vertice.first << ": ";
        out << "[";
        for (size_t i = 0; i < vertice.second.size(); i++) {
            out << vertice.second[i];
            if (i != vertice.second.size() - 1) {
                out << ", ";
            }
        }
        out << "]";
        out << endl;
    }

    return out;
}

void funGrafo()
{
    Grafo grafo;

    grafo["A"] = {"B", "C", "D"};
    grafo["B"] = {"A", "H"};
    grafo["C"] = {"A", "G", "F"};
    grafo["D"] = {"A", "E"};
    grafo["E"] = {"D", "K"};
    grafo["F"] = {"C", "J"};
    grafo["G"] = {"C", "J"};
    grafo["H"] = {"B", "I"};
    grafo["I"] = {"H", "J"};
    grafo["J"] = {"F", "G", "I", "K"};
    grafo["K"] = {"E", "J"};

    cout << grafo;

    cout << "Profundidad" << endl;
    vector<string> recorrido = busqueda_profundidad(grafo);

    for (auto const &vertice: recorrido) {
        cout << vertice << endl;
    }

    cout << "Amplitud" << endl;
    vector<string> recorrido_2 = busqueda_amplitud(grafo);

    for (auto const &vertice: recorrido_2) {
        cout << vertice << endl;
    }
}