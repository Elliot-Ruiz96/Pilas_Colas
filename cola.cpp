#include <iostream>
#include <conio.h>
#include <stdlib.h>

//#include "list.h"

using namespace std;

struct Nodo
{
    int dato;
    // Puntero de tipo nodo ya que apunta hacia el siguiente nodo
    Nodo *siguiente;
};

void encolar(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void desencolar(Nodo *&, Nodo *&, int &);
void cimaC(Nodo *, int);

int main()
{
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;
    char rpt;

    do
    {
        cout << "\nDigite un numero: " << endl;
        cin >> dato;
        encolar(frente, fin, dato);

        cimaC(frente, dato);

        cout << "\nDesea agregar otro elemento a Pila (s/n)? " << endl;
        cin >> rpt;
    }
    while((rpt == 'S')||(rpt == 's'));

    cout <<"\nSacando elementos de la cola: " << endl;

    while (frente != NULL)
    {
        desencolar(frente, fin, dato);
        if(frente != NULL)
        {
            cout << dato << ", ";
        }
        else
        {
            cout << dato << "." << endl;
        }
        cimaC(frente, dato);
    }

    getch();
    return 0;
}

// Para insertar elementos
void encolar(Nodo *&frente, Nodo *&fin, int n)
{
    // 1 Crear espacio en memoria para el nodo
    Nodo *nuevo_nodo = new Nodo();
    // 2 Asignar el nuevo noodo al dato que se inserta
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->dato = n;
    // 3 Asignar los punteros frente y fin hacia el nuevo nodo
    if(cola_vacia(frente))
    {
        frente = nuevo_nodo;
    }
    else
    {
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\n\tElemento " << n << " agregado a COLA corretamente." << endl;
}

// Funcion para determinar si la cola esta vacia o no
bool cola_vacia(Nodo *frente)
{
    return (frente == NULL)? true : false;

//    if(frente == NULL)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
}

// Para quitar elementos
void desencolar(Nodo *&frente, Nodo *&fin, int &n)
{
    // 1 Obtener el valor del nodo
    n = frente->dato;
    // 2 Crear un nodo aux y asginar frente
    Nodo *aux = frente;
    // 3 Eliminnar el nodo de frente de cola
    if (frente == fin) //Cuando hay un solo nodo
    {
        frente = NULL;
        fin = NULL;
    }
    else // Cuando hay mas de un nodo
    {
        frente = frente->siguiente;
    }
    delete aux;
}

void cimaC(Nodo *frente, int n)
{
    Nodo *muestraC = frente;
    n = muestraC->dato;
    cout << "\nDato en la cima: " << n << "\n" << endl;
}
