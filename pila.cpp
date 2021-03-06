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

void apilar(Nodo *&, int);
void desapilar(Nodo *&, int &);
void cimaP(Nodo *, int);

int pila()
{
    Nodo *pila = NULL;
    int dato;
    char rpt;

    do
    {
        cout << "Digita un numero: " << endl;
        cin >> dato;
        apilar(pila, dato);

        cimaP(pila, dato);

        cout << "Desea agregar otro elemento a Pila (s/n)? " << endl;
        cin >> rpt;
    }
    while((rpt == 'S')||(rpt == 's'));

    cout <<"\nSacando elementos de la pila: " << endl;

    // Mientras que no sea el final de la pila
    while (pila != NULL)
    {
        desapilar(pila, dato);
        if(pila != NULL)
        {
            cout << dato << ", ";
        }
        else
        {
            cout << dato << "." << endl;
        }
        cimaP(pila, dato);
    }

    getch();
    return 0;
}

// Para insertar elementos
// *&pila Cambia varias veces dentro de la funcion, n dato a agregar
void apilar(Nodo *&pila, int n)
{
    // 1 Crear el espacio en menoria para el nodo
    Nodo *nuevo_nodo = new Nodo();
    // 2 Cargar el valor dentro del nodo
    nuevo_nodo->dato = n;
    // 3 Cargar el puntero pila dentro del nodo
    nuevo_nodo->siguiente = pila;
    // 4 Asignar el nuevo nodo a pila
    pila = nuevo_nodo;

    cout << "\n\tElemento " << n << " agregado a PILA corretamente." << endl;
}

// Para quitar elementos
// n pasa por referencia debido a que va a variar
void desapilar(Nodo *&pila, int &n)
{
    // 1 Crear una variable *aux de tipo Nodo
    Nodo *aux = pila;
    // 2 Igualar el n a aux señalando a dato
    n = aux->dato;
    // 3 Pasar pila a siguiente nodo
    pila = aux->siguiente;
    // 4 Eliminar aux
    delete aux;
}

void cimaP(Nodo *pila, int n)
{
    Nodo *muestraC = pila;
    n = muestraC->dato;
    cout << "\nDato en la cima: " << n << "\n" << endl;
}
