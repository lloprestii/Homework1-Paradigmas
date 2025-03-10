#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/*
Crea (o agrega lineas a) un archivo log.txt en el que se escriban mensajes con un nivel de severidad.
*/
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

/*
Crea/agrega un mensaje de error en el archivo log.txt indicando el archivo y la linea de codigo donde ocurrio el error.
*/
void logMessage(string mensaje_de_error, string archivo, int linea_de_codigo){
    ofstream outFile("log.txt",ios::app);
    if(outFile.is_open()){
         outFile << "[ERROR] " << mensaje_de_error << " en el archivo " << archivo << " en la linea " << linea_de_codigo << endl;
         outFile.close();
    }
}

/*
Crea/agrega un mensaje de acceso en el archivo log.txt indicando el mensaje de acceso y el nombre de usuario que accedio.
*/

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream outFile("log.txt",ios::app);
    if(outFile.is_open()){
        outFile << "[SECURITY] " << Mensaje_De_Acceso << " por el usuario " << Nombre_de_Usuario << endl;
        outFile.close();
    }
}


