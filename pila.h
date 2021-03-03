#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "list.h"

using namespace std;

void encolar();
void descolar();

class Pila : public Lista
{
public:
    char caracter;
private:

};


#endif // PILA_H
