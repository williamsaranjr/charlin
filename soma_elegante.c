#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void imprimir(int s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

void soma(int s[], int v[], bool b[], int n, int _i, int *maior) {
    if (_i == n) {
        int atual = 0;
        // Realiza a soma da permutação
        for (int i = 0; i < n - 1; i++) {
            atual+= abs(s[i] - s[i + 1]);
        }
        // Atualiza o maior valor
        if (atual > *maior) {
            *maior = atual;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        // Se o valor não foi utilizado
        if (b[i] == false) {
            s[_i] = v[i];
            b[i] = true;
            soma(s, v, b, n, _i + 1, maior);
            b[i] = false;
        }
    }
}

int main() {
    int v[] = {4, 2, 1, 5};
    bool b[] = {false, false, false, false};
    int s[4];
    int maior = 0;
    soma(s, v, b, 4, 0, &maior);
    printf("Soma permutada elegante: %d\n", maior);
}