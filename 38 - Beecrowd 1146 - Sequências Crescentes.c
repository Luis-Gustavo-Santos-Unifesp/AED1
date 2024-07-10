#include <stdio.h>

int main() {
    int X;

    while (1) {
        scanf("%d", &X); // Lê o próximo valor de X

        if (X == 0) {
            break; // Sai do loop se X for zero
        }

        // Imprime a sequência de 1 até X
        for (int i = 1; i <= X; i++) {
            printf("%d", i);
            if (i < X) {
                printf(" "); // Imprime espaço entre os números, exceto após o último
            }
        }
        printf("\n"); // Quebra de linha após imprimir a sequência
    }

    return 0;
}
