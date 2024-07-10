#include <stdio.h>

// Função para calcular a soma de números ímpares entre X e Y
int soma_impares(int X, int Y) {
    int soma = 0;
    // Garante que X seja o menor e Y o maior
    if (X > Y) {
        int temp = X;
        X = Y;
        Y = temp;
    }
    // Percorre os números de X a Y e soma os ímpares
    for (int i = X + 1; i < Y; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    return soma;
}

int main() {
    int N;
    scanf("%d", &N); // Lê o número de casos de teste

    for (int caso = 0; caso < N; caso++) {
        int X, Y;
        scanf("%d %d", &X, &Y); // Lê os valores X e Y

        // Calcula a soma de ímpares entre X e Y
        int resultado = soma_impares(X, Y);

        // Imprime o resultado para este caso de teste
        printf("%d\n", resultado);
    }

    return 0;
}
