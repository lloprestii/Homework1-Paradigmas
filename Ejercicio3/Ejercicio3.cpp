#include "Ejercicio3.h"
#include <iostream>
#include <memory>
using namespace std;

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

int main(){
    shared_ptr<List> lista = make_shared<List>();
    shared_ptr<Node> nodo1 = create_node(1);
    shared_ptr<Node> nodo2 = create_node(2);
    shared_ptr<Node> nodo3 = create_node(3);
    shared_ptr<Node> nodo4 = create_node(4);
    shared_ptr<Node> nodo5 = create_node(5);
    shared_ptr<Node> nodo6 = create_node(6);
    shared_ptr<Node> nodo7 = create_node(7);
    shared_ptr<Node> nodo8 = create_node(8);
    shared_ptr<Node> nodo9 = create_node(9);
    shared_ptr<Node> nodo10 = create_node(10);
    push_front(lista, nodo1);
    push_front(lista, nodo2);
    push_front(lista, nodo3);
    push_front(lista, nodo4);
    push_front(lista, nodo5);
    push_front(lista, nodo6);
    push_front(lista, nodo7);
    push_front(lista, nodo8);
    push_front(lista, nodo9);
    push_front(lista, nodo10);
    print_list(lista);
    shared_ptr<Node> nodo11 = create_node(11);
    push_back(lista, nodo11);
    print_list(lista);
    shared_ptr<Node> nodo12 = create_node(12);
    insert(lista, nodo12, 5);
    print_list(lista);
    erase(lista, 5);
    print_list(lista);
    erase(lista, 100);
    print_list(lista);
    return 0;
}