#include <stdio.h>
#include <stdlib.h>

int bitonic_array(int v[], int i, int j) {
    if (i == j) {
        return i;
    }
    int m = (i + j) / 2;
    if (v[m] < v[m + 1]) {
        return bitonic_array(v, m + 1, j);
    } else {
        return bitonic_array(v, i, m);
    }
}

int main(int argc, char *argv[]) {
    int n = argc - 1;
    int v[n];

    for (int i = 0; i < n; i++) {
        v[i] = atoi(argv[i + 1]);
    }

    printf("%d\n", bitonic_array(v, 0, n - 1));
}