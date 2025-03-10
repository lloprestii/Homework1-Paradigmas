#include "Ejercicio1/Ejercicio1.h"
#include "Ejercicio2/Ejercicio2.h"

void freeMatrix(int** matriz, int n){
    for(int i = 0; i < n; i++){
        delete[] matriz[i];
    }
    delete[] matriz; 
}

int main(){
    int** matriz = Ejercicio1A(3);
    Ejercicio1B(matriz,3);
    freeMatrix(matriz,3);
    logMessage("Prueba DEBUG",0);
    logMessage("Prueba INFO",1);
    logMessage("Prueba WARNING",2);
    logMessage("Prueba ERROR",3);
    logMessage("Prueba CRITICAL",4);
    logMessage("Prueba ERROR", "main.cpp", 30);
    cout << "Si se introduce un usuario diferente a 'admin' se generara un mensaje de acceso denegado en el archivo log.txt y se saldra del programa con error 1" << endl;
    cout << "Ingrese un usuario: ";
    string usuario;
    cin >> usuario;
    if (usuario != "admin"){
        logMessage("Access Denied", usuario);
        return 1;
    }

    else{
        logMessage("Access Granted", usuario);
    }
}
