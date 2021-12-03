#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H

#include <iostream>

using namespace std;

template <class T>
class ArregloDinamico
{
    T *arreglo;
    size_t tam;
    size_t cont;
    const static size_t MAX = 5;
    void expandir();
public:
    ArregloDinamico();
    ~ArregloDinamico();
    void insertar_final(const T& s);
    void insertar_inicio(const T& s);
    void insertar(const T& s, size_t p);
    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);
    size_t size();
    T* buscar (const T& dato);
    ArregloDinamico<T*> buscar_todos(const T& dato);
    T operator[](size_t p)
    {
        return arreglo[p];
    }
    friend ArregloDinamico<T>& operator << (ArregloDinamico<T> &a, const T& v)
    {
        a.insertar_final(v);
        return a;
    }
    void mostrar();
    void intercambia(T arr[], size_t i, size_t j);
    void seleccion();
    void burbuja();
};

template <class T>
ArregloDinamico<T>::ArregloDinamico()  // Constructor
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
ArregloDinamico<T>::~ArregloDinamico()  // Destructor
{
    delete [] arreglo;
}

template <class T>
void ArregloDinamico<T>::insertar_final(const T& s)  // Insertar Final
{
    if (cont == tam)
    {
        expandir();
    }
    arreglo[cont] = s;
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar_inicio(const T& s)  // Insertar Inicio
{
    if (cont == tam)
    {
        expandir();
    }
    for (size_t i=cont; i>0; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = s;
    cont++;
}

template <class T>
void ArregloDinamico<T>::insertar(const T& s, size_t p)  // Insertar en una Posición
{
    if (p >= cont)
    {
        cout << "Posicion no valida" << endl;
        return;
    }
    if (cont == tam)
    {
        expandir();
    }
    for (size_t i = cont; i > p; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[p] = s;
    cont++;
}

template <class T>
void ArregloDinamico<T>::eliminar_final()  // Eliminar la Posicción Final
{
    if (cont == 0)
    {
        cout << "Arreglo vacio" << endl;
        return;
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar_inicio()  // Eliminar la Posición Inicial
{
    if (cont == 0)
    {
        cout << "Arreglo vacio" << endl;
        return;
    }
    for (size_t i=0; i < cont-1; i++)
    {
        arreglo[i]=arreglo[i+1];
    }
    cont--;
}

template <class T>
void ArregloDinamico<T>::eliminar(size_t p)  // Eliminar dato de una posición
{
    if (p >= cont)
    {
        cout << "Posicion no valida" << endl;
        return;
    }
    for (size_t i=p; i < cont-1; i++)
    {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template <class T>
size_t ArregloDinamico<T>::size()  // Tamaño del arreglo
{
    return cont;
}

template <class T>
T* ArregloDinamico<T>::buscar(const T& dato)
{
    for (size_t i=0; i<cont; i++)
    {
        if (dato==arreglo[i])
        {
            return &arreglo[i];
        }
    }
    return nullptr;
}

template <class T>
ArregloDinamico<T*> ArregloDinamico<T>::buscar_todos(const T& dato)
{
    ArregloDinamico<T*> ptrs;

    for (size_t i=0; i<cont; i++)
    {
        if (dato == arreglo[i])
        {
            ptrs.insertar_final(&arreglo[i]);
        }
    }
    return ptrs;
} 

template <class T>
void ArregloDinamico<T>::expandir()  // Expandir el arreglo
{
    T *nuevo = new T[tam+MAX];

    for (size_t i=0; i<cont; i++)
    {
        nuevo[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

template <class T>
void ArregloDinamico<T>::mostrar()  // Funcion para mostrar arreglo
{
    for (size_t i=0; i<size(); i++)
    {
        cout << arreglo[i] << "  ";
    }
}

template <class T>
void ArregloDinamico<T>::intercambia(T arr[], size_t i, size_t j)  // Intercambio de posición 
{
    T temp;
    temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

template <class T>
void ArregloDinamico<T>::seleccion()  // Algoritmo de selección
{
    for (size_t i=0; i<cont-1; i++)
    {
        size_t min = i;
        for (size_t j=i+1; j< cont; j++)
        {
            if (arreglo[j]<arreglo[min])
            {
                min=j;
            }
        }
        intercambia(arreglo, i, min);
    }
}

template <class T>
void ArregloDinamico<T>::burbuja()  // Algoritmo de burbuja
{
    for (size_t i=cont-1; i>0; i--)
    {
        for (size_t j=0; j<i; j++)
        {
            if (arreglo[j]>arreglo[j+1])
            {
                intercambia(arreglo, j, j+1);
            }
        }
    }
}

#endif