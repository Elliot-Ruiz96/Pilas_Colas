#include <iostream>
#include "list.h"
#include "list.cpp"

using namespace std;

int main()
{
    Lista<string> lista;
    string cancion;
    int dim;
    int pos;

    cout << "Lista de canciones al inicio." << endl;
    lista.imprime();

    cout << "Ingrese la dimension de la lista: " << endl;
    cin >> dim;

    cout << "\n1. Insertar. \n" << endl;
    lista.teclado(dim);
    lista.imprime();

    cout << "\n2. Insertar en: \n" << endl;
    cin >> pos;
    lista.insertar_en(pos);
    lista.imprime();

    cout << "\n3. Tomar: \n" << endl;
    cin >> pos;
    lista.tomar(pos);

    cout << "\n4. Buscar: \n" << endl;
    cin >> cancion;
    lista.buscar(cancion);

    cout << "\n5. Eliminar: \n" << endl;
    cin >> pos;
    lista.eliminar(pos);
    lista.imprime();

    cout << "\n6. Mostar todo: \n" << endl;
    lista.imprime();

    cout << "\n7. Modificar: \n" << endl; //Pendiente
    cin >> pos;
    lista.modificar(pos);
    lista.imprime();

    cout << "\n8. Vacio: \n" << endl;
    lista.vacio();
    lista.imprime();

    cout << "\n9. Purga: \n" << endl;
    lista.purgar();

    cout << "\n10. Tamanio: \n" << endl;
    lista.tamanio();
    lista.imprime();

    cout << "\n11. Tomar primero: \n" << endl; //Pendiente
    lista.tomar1();

    return 0;
}
