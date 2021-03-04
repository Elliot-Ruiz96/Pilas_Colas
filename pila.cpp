#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo
{
    char dato;
    // Puntero de tipo nodo ya que apunta hacia el siguiente nodo
    Nodo *siguiente;
};

void apilar(Nodo *&, char);
void desapilar(Nodo *&, char &);
void cimaP(Nodo *, char);


int main()
{
    Nodo *pila = NULL;
    char dato;
    int num, num_nodos;

    cout << "\nBienvenido al analizador de sintaxis" << endl;
    cout << "\nIngrese el numero de caracteres a verificar: " << endl;
    cin >> num;

    if(num % 2 == 0)
    {
        cout << "Digite un caracter([] () {}): " << endl;
        for (num_nodos = 1; num_nodos <= num ; num_nodos++)
        {
            cin >> dato;
            apilar(pila, dato);
            cimaP(pila, dato);
        }
    }
    else
    {
        cout << "Incorrecto, no podras abrir y cerrar todos los caracteres" << endl;
    }

    // Mientras que no sea el final de la pila
    cout <<"\nElminando todos los caracteres desde la cima: " << endl;
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
    }

    getch();
    return 0;
}

// Para insertar elementos
// *&pila Cambia varias veces dentro de la funcion, n dato a agregar
void apilar(Nodo *&pila, char n)
{
    // 1 Crear el espacio en menoria para el nodo
    Nodo *nuevo_nodo = new Nodo();
    // 2 Cargar el valor dentro del nodo
    nuevo_nodo->dato = n;
    // 3 Cargar el puntero pila dentro del nodo
    nuevo_nodo->siguiente = pila;
    // 4 Asignar el nuevo nodo a pila
    pila = nuevo_nodo;
}

// Para quitar elementos
// n pasa por referencia debido a que va a variar
void desapilar(Nodo *&pila, char &n)
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

void cimaP(Nodo *pila, char n)
{
    Nodo *muestraC = pila;
    n = muestraC->dato;
    cout << "\nCaracter en la cima: " << n << "\n" << endl;
}
