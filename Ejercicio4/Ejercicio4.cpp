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
    auto startTime = chrono::high_resolution_clock::now();
    bool resultado1 = compararStringsRecursivo("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.", 0);
    auto endTime = chrono::high_resolution_clock::now();
    auto tiempoRecursivo = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);

    cout << "Comparacion en tiempo de ejecucion: " << (resultado1 ? "Iguales" : "Diferentes") << endl;
    cout << "Tiempo de ejecucion: " << tiempoRecursivo.count() << " nanosegundos" << endl;

    // Mido el tiempo de ejecucion de la funcion compararConstexpr
    auto startTime_ = chrono::high_resolution_clock::now();
    constexpr bool resultadoConstexpr = compararConstexpr("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.","Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras purus sapien, ullamcorper eget dignissim quis, vestibulum sit amet tellus.");
    auto endTime_ = chrono::high_resolution_clock::now();
    auto tiempoCompilacion = chrono::duration_cast<chrono::nanoseconds>(endTime_ - startTime_);

    cout << "Comparacion en tiempo de compilacion: " << (resultadoConstexpr ? "Iguales" : "Diferentes") << endl;
    cout << "Tiempo de ejecucion de comparacion en compilacion: " << tiempoCompilacion.count() << " nanosegundos" << endl;

    /*
    - Despues de hacer varios test con strings de diferente tamaño pude notar que el tiempo de ejecucion de la funcion recursiva depende mucho del tamaño de los strings.
    - Al evaluar la expresion booleana en tiempo de compliacion hace que la comparacion sea extremadamente rapida. 
    */
    
    return 0;
}
constexpr bool compararConstexpr(const char* str1, const char* str2);