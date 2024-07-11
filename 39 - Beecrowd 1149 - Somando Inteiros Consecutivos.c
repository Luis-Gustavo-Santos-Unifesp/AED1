#include <stdio.h>

int main() {
    int A, N;

    // Leitura de A
    scanf("%d", &A);

    // Loop para ler N até ser positivo
    while (1) {
        scanf("%d", &N);
        if (N > 0) {
            break;
        }
    }

    // Calcula a soma de A + i para i variando de 0 a N-1
    int soma = 0;
    for (int i = 0; i < N; i++) {
        soma += (A + i);
    }

    // Imprime a soma
    printf("%d\n", soma);

    return 0;
}
