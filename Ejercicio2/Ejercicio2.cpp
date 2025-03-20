#include "Ejercicio2.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void logMessage(string mensaje,int NivelSeveridad){
    /*
        0 -> DEBUG
        1 -> INFO
        2 -> WARNING
        3 -> ERROR
        4 -> CRITICAL
    */
    string severidad;
    switch(NivelSeveridad){
        case 0:
            severidad = "DEBUG";
            break;
        case 1:
            severidad = "INFO";
            break;
        case 2:
            severidad = "WARNING";
            break;
        case 3:
            severidad = "ERROR";
            break;
        case 4:
            severidad = "CRITICAL";
            break;
        default:
            cout<<"El nivel de severidad ingresado no es correcto";
            return;
    }
   ofstream outFile("log.txt",ios::app);
    if(outFile.is_open()){
         outFile << "[" << severidad << "] " << mensaje << endl;
         outFile.close();
    }
}

void logMessage(string mensaje_de_error, string archivo, int linea_de_codigo){
    ofstream outFile("log.txt",ios::app);
    if(outFile.is_open()){
         outFile << "[ERROR] " << mensaje_de_error << " en el archivo " << archivo << " en la linea " << linea_de_codigo << endl;
         outFile.close();
    }
}

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream outFile("log.txt",ios::app);
    if(outFile.is_open()){
        outFile << "[SECURITY] " << Mensaje_De_Acceso << " por el usuario " << Nombre_de_Usuario << endl;
        outFile.close();
    }
}

int main(){
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
    return 0;
}