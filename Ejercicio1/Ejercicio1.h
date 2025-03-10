#include <iostream>
using namespace std;


/*
Crea una matriz de n*n rellena de números enteros consecutivos empezando por 1.
*/
int** Ejercicio1A(int n){
    int** matriz = new int*[n];

    for(int i = 0; i < n; i++){
        matriz[i] = new int[n];
        for(int j = 0; j < n; j++){
            matriz[i][j] = i*n+j+1;
        }
    }

    return matriz;

}

/*
Imprime los elementos de una matriz n*n en orden descendente.
*/
void Ejercicio1B(int** matriz, int n){
    int elementos = n * n;

    for(int k = elementos - 1;k>=0;k--){
        int i = k / n;
        int j = k % n;
        cout << "M[" << i << "][" << j << "] = " << matriz[i][j] << endl;
    }
}
