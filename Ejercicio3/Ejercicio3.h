#include <iostream>
#include <string>
#include <memory>
using namespace std;

typedef struct Node Node;

typedef struct List List;

/*
Devuelve un nodo.
*/
shared_ptr<Node> create_node(int value);

/*
Inserta un nodo al frente de la lista. 
*/
void push_front(shared_ptr<List> lista, shared_ptr<Node> nodo);

/*
Inserta un nodo al final de la lista.
*/
void push_back(shared_ptr<List> lista, shared_ptr<Node> nodo);

/*
Inserta un nodo en la posición que se le pase a la función. Si se le pasa 
una posición mayor al largo de la lista, lo indica y agrega al final de la lista
*/
void insert(shared_ptr<List> lista, shared_ptr<Node> nodo, int position);

/*
Borra  un  nodo  en  la  posición  que  se  le  pase  a  la  función.  Similar  a  la 
función insert(), si la posición es mayor que el largo de la lista, se debe de borrar 
el último nodo. 
*/
void erase(shared_ptr<List> lista, int position);

/*
Imprime la lista completa, separando el valor en cada nodo con “->”. 
*/
void print_list(shared_ptr<List> lista);