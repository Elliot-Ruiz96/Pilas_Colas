#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo
{
    string dato;
    // Puntero de tipo nodo ya que apunta hacia el siguiente nodo
    Nodo *siguiente;
};

void encolar(Nodo *&, Nodo *&, string);
bool cola_vacia(Nodo *);
void desencolar(Nodo *&, Nodo *&, string &);
void cimaC(Nodo *, string);

// int main
int cola()
{
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    string nombre;
    int opcion;

    cout << "\nBienvenido a atencion a cliente, por favor, elija una opcion:" << endl;
    cout << "\n1. Ingresar un nombre." << endl;
    cout << "\n2. Sacar a la persona del inicio." << endl;
    cout << "\n3. Mostrar el nombre la persona al inicio:" << endl;
    cout << "\n4. Salir:" << endl;

    do
    {
        cout << "\nIngrese su opcion: " << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            cout << "\nPor favor, diga su nombre y lo pondremos en cola de espera. " << endl;
            cin >> nombre;
            encolar(frente, fin, nombre);
            break;
        case 2:
            desencolar(frente, fin, nombre);
            if(frente != NULL)
            {
                cout <<"\nSacando persona de la cola: " << endl;
                cout << nombre << "\n ";
            }
            else
            {
                cout <<"\nSacando a la ultima persona de la cola: " << endl;
                cout << nombre << "\n" << endl;
            }
            break;
        case 3:
            cimaC(frente, nombre);
            break;
        default:
            cout << "Opcion incorrecta. " << endl;
        }
    }
    while(opcion!=4);
    cout << "Adios!" << endl;

    getch();
    return 0;
}

// Para insertar elementos
void encolar(Nodo *&frente, Nodo *&fin, string n)
{
    // 1 Crear espacio en memoria para el nodo
    Nodo *nuevo_nodo = new Nodo();
    // 2 Asignar el nuevo noodo al dato que se inserta
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->dato = n;
    // 3 Asignar los punteros frente y fin hacia el nuevo nodo
    if(cola_vacia(frente))
    {
        cout <<"\nNo hay personas en la cola de espera: " << endl;
        frente = nuevo_nodo;
    }
    else
    {
        fin -> siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\n\t" << n << " llegando a la cola." << endl;
}

// Funcion para determinar si la cola esta vacia o no
bool cola_vacia(Nodo *frente)
{
    return (frente == NULL)? true : false;
}

// Para quitar elementos
void desencolar(Nodo *&frente, Nodo *&fin, string &n)
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

void cimaC(Nodo *frente, string n)
{
    Nodo *muestraC = frente;
    n = muestraC->dato;
    if(cola_vacia(frente))
    {
        cout <<"\nNo hay personas en la cola de espera: " << endl;
    }
    else
    {
        cout << "\nPersona al inicio de la cola: " << n << "\n" << endl;
    }
}
