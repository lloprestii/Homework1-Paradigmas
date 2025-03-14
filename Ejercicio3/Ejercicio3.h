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

