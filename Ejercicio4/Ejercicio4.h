#include <iostream>
#include <string>
using namespace std;

/*
Esta funcion compara dos strings de manera recursiva en tiempo de ejecución.
Si los strings son iguales devuelve true(1) y si son diferentes devuelve false(0).
*/
bool compararStringsRecursivo(const string& str1, const string& str2, size_t index = 0);

/*
Esta funcion compara dos strings de manera constante en tiempo de compilación.
Si los strings son iguales devuelve true(1) y si son diferentes devuelve false(0).
*/
constexpr bool compararConstexpr(const char* str1, const char* str2);

