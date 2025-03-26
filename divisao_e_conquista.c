#include <stdlib.h>
#include <stdio.h>

void imprimir(int v[], int _i, int j) {
    for (int i = _i; i < j; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int maior(int v[], int i, int j) {
    if (i == j) {
        return v[i];
    }

    int m = (i + j) / 2;
    int esq = maior(v, i, m);
    int dir = maior(v, m + 1, j);
    return esq > dir ? esq : dir;
}

int main(int argc, char *argv[]) {
    int v[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        v[i] = atoi(argv[i + 1]);
    }
    int resultado = maior(v, 0, argc - 2);
    printf("Maior valor: %d\n", resultado);
    return 0;
}