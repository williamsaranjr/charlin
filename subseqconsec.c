#include <stdio.h>

int numero_subsequencias(int v[], int n) {
    int resultado = 1;
    
    for (int i = 0; i < n - 1; i++) {
        if (v[i] != v[i + 1]) {
            resultado++;
        }
    }

    return resultado;
}

int main() {
    int v[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, -1, -2};
    int resultado = numero_subsequencias(v, sizeof(v) / sizeof(int));
    printf("Número de subsequências: %d\n", resultado);
    return 0;
}