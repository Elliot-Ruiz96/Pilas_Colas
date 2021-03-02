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

    cout << "Lista de canciones al inicio. \n" << endl;
    lista.imprime();

    cout << "Ingrese la dimension de la lista: " << endl;
    cin >> dim;

    cout << "\n1. Insertar. \n" << endl;
    lista.teclado(dim);

    cout << "\n2. Insertar en: \n" << endl;
    cin >> pos;
    lista.insertar_en(pos);

    cout << "\n3. Tomar: \n" << endl; //Pendiente
    cin >> pos;
    lista.tomar(pos);

    cout << "\n4. Buscar: \n" << endl;
    cin >> cancion;
    lista.buscar(cancion);

    cout << "\n5. Eliminar: \n" << endl;
    cin >> pos;
    lista.eliminar(pos);

    cout << "\n6. Mostar todo: \n" << endl;
    lista.imprime();

    cout << "\n7. Modificar: \n" << endl; //Pendiente
    lista.modificar();

    cout << "\n8. Vacio: \n" << endl;
    lista.vacio();

    cout << "\n9. Purga: \n" << endl;
    lista.purgar();

    cout << "\n10. Tamanio: \n" << endl;
    lista.tamanio();

    cout << "\n11. Tomar primero: \n" << endl; //Pendiente
    lista.tomar1();

    return 0;
}
