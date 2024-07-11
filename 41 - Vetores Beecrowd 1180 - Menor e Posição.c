#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  // Leitura do tamanho do vetor

    int X[N];  // Declaração do vetor

    // Leitura dos elementos do vetor
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    // Inicialização do menor valor e posição
    int menor_valor = X[0];
    int posicao = 0;

    // Encontra o menor valor e sua posição
    for (int i = 1; i < N; i++) {
        if (X[i] < menor_valor) {
            menor_valor = X[i];
            posicao = i;
        }
    }

    // Impressão dos resultados
    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
