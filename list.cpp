#include "list.h"

using namespace std;
template <typename T>

Lista<T>::Lista()
{
    m_num_nodos = 0;
    m_inicio = NULL;
}

template <typename T>

void Lista<T>::insertar_inicio(T data_)
{
    Nodo<T> *nodo_nuevo = new Nodo<T> (data_);
    Nodo<T> *temp = m_inicio;
    if (!m_inicio)
    {
        m_inicio = nodo_nuevo;
    }
    else
    {
        nodo_nuevo->next = m_inicio;
        m_inicio = nodo_nuevo;
    }
    m_num_nodos++;
}

template <typename T>

void Lista<T>::insertar_en(int pos)
{
    T cancion;
    Nodo<T> *temp = m_inicio;
    Nodo<T> *temp1 = temp ->next;
    if (pos < 1 || pos > m_num_nodos)
    {
        cout << "Fuera de rango" << endl;
    }
    else if (pos == 1)
    {
        cout << "Ingresa la cancion " <<endl;
        cin >> cancion;
        m_inicio = temp -> next;
    }
    else
    {
        for (int i = 2; i <= pos; i++)
        {
            if (i == pos)
            {
                cout << "Ingresa la cancion " <<endl;
                cin >> cancion;
                Nodo<T> *aux_nodo = temp1;
                temp->next = temp1->next;
                m_num_nodos++;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

template <typename T>

void Lista<T>::tomar(int pos)
{

}

template <typename T>

void Lista<T>::buscar(T data_)
{
    Nodo<T> *temp = m_inicio;
    int cont = 1;
    int cont2 = 0;

    while (temp)
    {
        if (temp->data == data_)
        {
            cout << "\nEl dato se encuentra en la posicion: " << cont << endl;
            cont2++;
        }
        temp = temp->next;
        cont++;
    }
    if (cont2 == 0)
    {
        cout << "\n-1" << endl;
    }
    cout << endl << endl;
}

template <typename T>

void Lista<T>::eliminar(int pos)
{
    Nodo<T> *temp = m_inicio;
    Nodo<T> *temp1 = temp->next;
    if (pos < 1 || pos > m_num_nodos)
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int i = 1; i <= pos; i++)
        {
            if (i == pos)
            {
                Nodo<T> *aux_nodo = temp1;
                temp->next = temp1->next;
                delete aux_nodo;
                m_num_nodos--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

template <typename T>

void Lista<T>::modificar()
{

}

template <typename T>

void Lista<T>::vacio()
{
    cout << "\n" << (m_num_nodos==0);
}

template <typename T>

void Lista<T>::purgar()
{
    m_inicio->purga();
    m_inicio = 0;
}

template <typename T>

void Lista<T>::tamanio()
{
    cout << "\nHay " << m_num_nodos << " elementos en la lista." << endl;
}

template <typename T>

void Lista<T>::tomar1()
{

}

template<typename T>
void Lista<T>::imprime()
{
    Nodo<T> *temp = m_inicio;
    if (!m_inicio)
    {
        cout << "La Lista esta vacia. " << endl;
    }
    else
    {
        while (temp)
        {
            temp->imprime_n();
            temp = temp->next;
            if (!temp->next)
            {
                cout << "NULL";
                temp = temp->next;
            }
        }
    }
  cout << endl ;
}

template<typename T>

void Lista<T>::teclado(int dim)
{
    T cancion;
    for (int k = 1; k <= dim; k++)
    {
        cout << "Ingresa la cancion: " << k << "/" << dim << endl;
        cin >> cancion;
        insertar_final(cancion);
    }
}


template <typename T>

void Lista<T>::insertar_final(T data_)
{
    Nodo<T> *nodo_nuevo = new Nodo<T> (data_);
    Nodo<T> *temp = m_inicio;
    if (!m_inicio)
    {
        m_inicio = nodo_nuevo;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next=nodo_nuevo;
    }
    m_num_nodos = m_num_nodos +1;
}

template<typename T>
Lista<T>::~Lista()
{

}
