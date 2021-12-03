#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
using namespace std;

template< typename TIPONODO > class Arbol;

template< typename TIPONODO >
class NodoArbol
{
    friend class Arbol< TIPONODO >;
public:
    // Constructor
    NodoArbol(const TIPONODO &d): izquierdoPtr(0), datos(d), derechoPtr(0) {}

    TIPONODO obtenerDatos() const
    {
        return datos;
    }

private:
    NodoArbol<TIPONODO> *izquierdoPtr;
    TIPONODO datos;
    NodoArbol<TIPONODO> *derechoPtr;
};

template <typename TIPONODO> 
class Arbol
{
public:
    // Constructor
    Arbol();
    void InsertarNodo(const TIPONODO &);
    void PreOrden() const;
    void InOrden() const;
    void PostOrden() const;
private:
    NodoArbol<TIPONODO> *raizPtr;
    void asisInsertarNodo(NodoArbol<TIPONODO> **, const TIPONODO &);
    void asisPreOrden(NodoArbol<TIPONODO> *) const;
    void asisInOrden(NodoArbol<TIPONODO> *) const;
    void asisPostOrden(NodoArbol<TIPONODO> *) const;
};

template <typename TIPONODO>
Arbol<TIPONODO>::Arbol()
{
    raizPtr = 0;
}

template <typename TIPONODO>
void Arbol<TIPONODO>::InsertarNodo(const TIPONODO &valor)
{
    asisInsertarNodo(&raizPtr, valor);
}

template <typename TIPONODO>
void Arbol<TIPONODO>::asisInsertarNodo(NodoArbol<TIPONODO> **ptr, const TIPONODO &valor)
{
    if (*ptr == 0)
    {
        *ptr = new NodoArbol<TIPONODO>(valor);
    }

    else
    {
        if (valor < (*ptr)->datos)
        {
            asisInsertarNodo(&((*ptr)->izquierdoPtr), valor);
        }
        else
        {
            if (valor > (*ptr)->datos)
            {
                asisInsertarNodo(&((*ptr)->derechoPtr), valor);
            }
            else
            {
                cout << valor << " duplicado" << endl;
            }
        }
    }
}

template <typename TIPONODO>
void Arbol<TIPONODO>::PreOrden() const
{
    asisPreOrden(raizPtr);
}

template <typename TIPONODO>
void Arbol<TIPONODO>::asisPreOrden(NodoArbol<TIPONODO> *ptr) const
{
    if (ptr != 0)
    {
        cout << ptr->datos << " ";
        asisPreOrden(ptr->izquierdoPtr);
        asisPreOrden(ptr->derechoPtr);
    }
}

template <typename TIPONODO>
void Arbol<TIPONODO>::InOrden() const
{
    asisInOrden(raizPtr);
}

template <typename TIPONODO>
void Arbol<TIPONODO>::asisInOrden(NodoArbol<TIPONODO> *ptr) const
{
    if (ptr != 0)
    {
        asisInOrden(ptr->izquierdoPtr);
        cout << ptr->datos << " ";
        asisInOrden(ptr->derechoPtr);
    }
}

template <typename TIPONODO>
void Arbol<TIPONODO>::PostOrden() const
{
    asisPostOrden(raizPtr);
}

template <typename TIPONODO>
void Arbol<TIPONODO>::asisPostOrden(NodoArbol<TIPONODO> *ptr) const
{
    if (ptr != 0)
    {
        asisPostOrden(ptr->izquierdoPtr);
        asisPostOrden(ptr->derechoPtr);
        cout << ptr->datos << " ";
    }
}

#endif