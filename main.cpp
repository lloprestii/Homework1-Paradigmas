#include "Ejercicio1/Ejercicio1.cpp"
#include "Ejercicio2/Ejercicio2.cpp"
#include "Ejercicio3/Ejercicio3.cpp"

void freeMatrix(int** matriz, int n){
    for(int i = 0; i < n; i++){
        delete[] matriz[i];
    }
    delete[] matriz; 
}

int main(){
    int n = -1;
    int** matriz = Ejercicio1A(n);
    if (matriz){
        Ejercicio1B(matriz,n);
        freeMatrix(matriz,n);
    }
    logMessage("Prueba DEBUG",0);
    logMessage("Prueba INFO",1);
    logMessage("Prueba WARNING",2);
    logMessage("Prueba ERROR",3);
    logMessage("Prueba CRITICAL",4);
    logMessage("Prueba ERROR", "main.cpp", 30);
    cout << "Si se introduce un usuario diferente a 'admin' se generara un mensaje de acceso denegado en el archivo log.txt y se saldra del programa con un error." << endl;
    cout << "Ingrese un usuario: ";
    string usuario;
    cin >> usuario;

    try{
        if(usuario != "admin"){
            logMessage("Access Denied",usuario);
            throw "Usuario no valido";
        }
        else{
            logMessage("Access Granted",usuario);
            cout<<"Access Granted"<<endl;
        }
    }
    catch(const char* e){
        cout<<"Error: "<<e<<endl;
        return 1;
    }
    
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