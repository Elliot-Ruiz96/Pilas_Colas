#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "node.h"
#include "node.cpp"

using namespace std;

template <class T>

class Lista
{
public:
    Lista();
    ~Lista();
    void insertar_inicio(T);
    void insertar_en(int);
    void tomar(int);
    void buscar(T);
    void eliminar(int);
    void modificar(int);
    void vacio();
    void purgar();
    void tamanio();
    void tomar1();
    void imprime();
    void teclado(int);
    void teclado2(int);
    void insertar_final(T);
private:
    Nodo<T> *m_inicio;
    int m_num_nodos;
};

#endif // LIST_H
