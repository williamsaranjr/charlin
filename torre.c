#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define TAMANHO_TABULEIRO 8

bool validar(bool tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[linha][i] || tabuleiro[i][coluna]) {
            return false;
        }
    }
    return true;
}

void imprimir(bool tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(tabuleiro[i][j] ? "♜ " : "0 ");
        }
        printf("\n");
    }
    printf("\n");
}

void torre(bool tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coluna, int *total) {
    if (coluna == TAMANHO_TABULEIRO) {
        *total += 1;
        imprimir(tabuleiro);
        return;
    }
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (validar(tabuleiro, i, coluna)) {
            tabuleiro[i][coluna] = true;
            torre(tabuleiro, coluna + 1, total);
            tabuleiro[i][coluna] = false;
        }
    }
}

int main() {
    bool tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {false};
    int total = 0;
    torre(tabuleiro, 0, &total);
    printf("Total de soluções: %d\n", total);
    return 0;
}