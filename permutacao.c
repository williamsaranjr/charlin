#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void imprimir(char *v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", v[i]);
    }
    printf("\n");
}

void permutar(char *s[], char *v[], bool b[], int n, int _i) {
    if (_i == n) {
        imprimir(s, n);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == false) {
            s[_i] = v[i];
            b[i] = true;
            permutar(s, v, b, n, _i + 1);
            b[i] = false;
        }
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    char *v[] = {
        "Barcelona", "Real Madrid", "Bayern", "Juventus"
    };
    bool b[n];
    char *s[] = {
        " ", " ", " ", " "
    };

    for (int i = 0; i < n; i++) {
        b[i] = false;
    }

    permutar(s, v, b, n, 0);
    return 0;
}