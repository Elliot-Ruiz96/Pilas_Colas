#include "node.h"

template <typename T>

Nodo<T>::Nodo()
{
    data = NULL;
    next = NULL;
}

template <typename T>

Nodo<T>::Nodo(T data_)
{
    data = data_;
    next = NULL;
}

template <typename T>

void Nodo<T>::purga()
{
    if (next)
        next->purga();
    delete this;
}

template <typename T>

void Nodo<T>::imprime_n()
{
    cout << data << "-> ";
}

template <typename T>
Nodo<T>::~Nodo()
{

}
