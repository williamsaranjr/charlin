#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int calcular(int v[], int n) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        soma += v[i];
    }

    return soma;
}

void imprimir(int v[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], i == n - 1 ? "]" : ", ");
    }
}

void soma(int s[], int v[], bool b[], int n, int _i, int ns, int _j, int *maior) {
    if (_i == ns) {
        int atual = calcular(s, ns);
        if (atual > *maior) {
            *maior = atual;
        }
        return;
    }
    for (int i = ns; i < n; i++) {
        for (int j = _j; j < n; j++) {
            if (b[j] == false) {
                s[_i] = v[j];
                b[j] = true;
                soma(s, v, b, n, _i + 1, i, j, maior);
                b[j] = false;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int n = argc - 1;
    int v[n];
    bool b[n];
    int s[n];

    for (int i = 0; i < n; i++) {
        v[i] = atoi(argv[i + 1]);
        b[i] = false;
    }

    int maior = v[0];

    soma(s, v, b, n, 0, 1, 0, &maior);

    printf("Maior subsequência: %d\n", maior);
    return 0;
}