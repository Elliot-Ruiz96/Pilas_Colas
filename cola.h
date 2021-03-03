#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "list.h"

using namespace std;

void apilar();
void desapilar();

class Cola : public Lista
{
public:
    string nombre;
private:

};


#endif // COLA_H
