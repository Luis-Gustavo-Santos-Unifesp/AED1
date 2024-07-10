#include <stdio.h>

int main() {
    int X, Y;
    scanf("%d %d", &X, &Y); // Lê os valores de X e Y

    int count = 1; // Inicia o contador de números

    // Loop para imprimir as sequências
    while (count <= Y) {
        // Imprime X números por linha
        for (int i = 0; i < X; i++) {
            if (count > Y) break; // Para caso tenha ultrapassado Y
            printf("%d", count);
            if (i < X - 1) {
                printf(" "); // Imprime espaço entre os números
            }
            count++;
        }
        printf("\n"); // Quebra de linha após cada sequência completa
    }

    return 0;
}
