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

void push_back(shared_ptr<List> lista, shared_ptr<Node> nodo){
    shared_ptr<Node> current = lista->head;
    if(current == nullptr){
        lista->head = nodo;
        lista->size++;
        return;
    }
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = nodo;
    lista->size++;
}

void insert(shared_ptr<List> lista, shared_ptr<Node> nodo, int position){
    if (position < 0){
        cout << "La posicion es menor a 0, se agrega al inicio de la lista" << endl;
        push_front(lista, nodo);
        return;
    }
    if(position > lista->size){
        cout << "La posicion es mayor al largo de la lista, se agrega al final de la lista" << endl;
        push_back(lista, nodo);
        return;
    }
    shared_ptr<Node> current = lista->head;
    if(position == 0){
        push_front(lista, nodo);
        return;
    }
    for(int i = 0; i < position - 1; i++){
        current = current->next;
    }
    nodo->next = current->next;
    current->next = nodo;
    lista->size++;
}

void erase(shared_ptr<List> lista, int position){
    if(position < 0){
        cout << "La posicion es menor a 0, se borra el primer nodo de la lista" << endl;
        lista->head = lista->head->next;
        lista->size--;
        return;
    }
    if(position >= lista->size){
        cout << "La posicion es mayor al largo de la lista, se borra el ultimo nodo de la lista" << endl;
        shared_ptr<Node> current = lista->head;
        while(current->next->next != nullptr){
            current = current->next;
        }
        current->next = nullptr;
        lista->size--;
        return;
    }
    shared_ptr<Node> current = lista->head;
    for(int i = 0; i < position - 1; i++){
        current = current->next;
    }
    current->next = current->next->next;
    lista->size--;
}

void print_list(shared_ptr<List> lista){
    shared_ptr<Node> current = lista->head;
    while(current != nullptr){
        cout << current->value;
        if(current->next != nullptr){
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}
