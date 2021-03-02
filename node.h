#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>

class Nodo
{
public:
    Nodo();
    Nodo(T);
    ~Nodo();
    Nodo *next;
    T data;
    void purga();
    void imprime_n();
};

#endif // NODE_H
