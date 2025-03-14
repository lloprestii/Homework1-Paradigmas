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