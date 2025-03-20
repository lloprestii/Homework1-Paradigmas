#include <iostream>
#include <string>
#include <chrono>
#include "Ejercicio4.h"
using namespace std;

bool compararStringsRecursivo(const string& str1, const string& str2, size_t index) {
    if (index == str1.size() || index == str2.size()) {
        return str1.size() == str2.size();
    }
    if (str1[index] != str2[index]) {
        return false;
    }
    return compararStringsRecursivo(str1, str2, index + 1);
}

constexpr bool compararConstexpr(const char* str1, const char* str2) {
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

int main() {

    // Mido el tiempo de ejecucion de la funcion compararStringsRecursivo
    auto startExec = chrono::high_resolution_clock::now();
    bool resultado1 = compararStringsRecursivo("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.", 0);
    auto endExec = chrono::high_resolution_clock::now();
    auto tiempoEjecucion = chrono::duration_cast<chrono::nanoseconds>(endExec - startExec);

    cout << "Comparación en tiempo de ejecución: " << (resultado1 ? "Iguales" : "Diferentes") << endl;
    cout << "Tiempo de ejecución: " << tiempoEjecucion.count() << " nanosegundos" << endl;

    // Mido el tiempo de ejecucion de la funcion compararConstexpr
    auto startComp = chrono::high_resolution_clock::now();
    constexpr bool resultadoConstexpr = compararConstexpr("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.","Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.");
    auto endComp = chrono::high_resolution_clock::now();
    auto tiempoCompilacion = chrono::duration_cast<chrono::nanoseconds>(endComp - startComp);

    cout << "Comparación en tiempo de compilación: " << (resultadoConstexpr ? "Iguales" : "Diferentes") << endl;
    cout << "Tiempo de ejecución de comparación en compilación: " << tiempoCompilacion.count() << " nanosegundos" << endl;

    /*
    - Despues de hacer varios test con strings de diferente tamaño pude notar que el tiempo de ejecucion de la funcion recursiva depende mucho del tamaño de los strings.
    - Al evaluar la expresion booleana en tiempo de compliacion hace que la comparacion sea extremadamente rapida. 
    */
    
    return 0;
}
constexpr bool compararConstexpr(const char* str1, const char* str2);