#include "Ejercicio3.h"

/*
Implemente  una  lista  enlazada  que  utilice  nodos  que  simplemente  contengan  un 
valor y una dirección de memoria de un nodo. Adicionalmente, agregue las siguientes 
funciones para manejar la lista: 
i. create_node(): devuelve un nodo. 
ii. push_front(): inserta un nodo al frente de la lista. 
iii. push_back(): inserta un nodo al final de la lista. 
iv. insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa 
una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de 
agregar el nodo al final de la lista. 
v. erase():  borra  un  nodo  en  la  posición  que  se  le  pase  a  la  función.  Similar  a  la 
función insert(), si la posición es mayor que el largo de la lista, se debe de borrar 
el último nodo. 
vi. print_list(): imprime la lista completa, separando el valor en cada nodo con “->”. 
Presentar ejemplos que verifiquen el funcionamiento requerido en las funciones i-vi y, 
muy importante para el ejercicio, sólo utilizar smart pointers.  
*/

typedef struct Node{
    int value;
    shared_ptr<Node> next;
}Node;

typedef struct List{
    shared_ptr<Node> head;
    int size;
}List;

shared_ptr<Node> create_node(int value){
    shared_ptr<Node> node = make_shared<Node>();
    node->value = value;
    node->next = nullptr;
    return node;
}

void push_front(shared_ptr<List> lista, shared_ptr<Node> nodo){
    nodo->next = lista->head;
    lista->head = nodo;
    lista->size++;
}


