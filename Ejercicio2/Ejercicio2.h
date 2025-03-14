#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/*
Crea (o agrega lineas a) un archivo log.txt en el que se escriban mensajes con un nivel de severidad.

        0 -> DEBUG
        1 -> INFO
        2 -> WARNING
        3 -> ERROR
        4 -> CRITICAL
*/
void logMessage(string mensaje,int NivelSeveridad);


/*
Crea/agrega un mensaje de error en el archivo log.txt indicando el archivo y la linea de codigo donde ocurrio el error.
*/
void logMessage(string mensaje_de_error, string archivo, int linea_de_codigo);

/*
Crea/agrega un mensaje de acceso en el archivo log.txt indicando el mensaje de acceso y el nombre de usuario que accedio.
*/

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario);


