#include <stdio.h>

int maior_lucro_acumulado(int v[], int n) {
    int resultado = v[0];

    for (int i = 0; i < n; i++) {
        int lucro = 0;
        for (int j = i; j < n; j++) {
            lucro += v[j];
            if (lucro > resultado) {
                resultado = lucro;
            }
        }
    }

    return resultado;
}

int main() {
    int v[] = {3, -2, 5, -1, 6, -3, 2, -5, 4};
    int n = 9;
    int resultado = maior_lucro_acumulado(v, n);
    printf("Maior lucro acumulado: %d\n", resultado);
    return 0;
}