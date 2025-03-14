#include <iostream>
using namespace std;


int** Ejercicio1A(int n){
    try{
        if (n<0){
            throw "No se puede ingresar un valor negativo para el size de la matriz.";
        }
    }
    catch(const char* error){
            cout << "Error: " << error << endl;
            return NULL;
        }
    
    int** matriz = new int*[n];

    for(int i = 0; i < n; i++){
        matriz[i] = new int[n];
        for(int j = 0; j < n; j++){
            matriz[i][j] = i*n+j+1;
        }
    }

    return matriz;

}


void Ejercicio1B(int** matriz, int n){
    int elementos = n * n;

    for(int k = elementos - 1;k>=0;k--){
        int i = k / n;
        int j = k % n;
        cout << "M[" << i << "][" << j << "] = " << matriz[i][j] << endl;
    }
}
