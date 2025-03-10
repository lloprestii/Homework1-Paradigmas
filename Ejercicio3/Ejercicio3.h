#include <iostream>
#include <string>
using namespace std;


typedef struct nodo{
    int valor;
    struct nodo* siguiente;
}Nodo;

typedef struct lista{
    size_t size;
    nodo* head;
}lista;

Nodo* create_node(int valor){
    Nodo* nuevo = new Nodo;
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

