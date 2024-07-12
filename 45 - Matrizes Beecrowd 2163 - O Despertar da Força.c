#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int terreno[N][M];

    // Leitura dos valores da matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &terreno[i][j]);
        }
    }

    int encontrado = 0;
    int X = 0, Y = 0;

    // Verificação do padrão
    for (int i = 1; i < N - 1 && !encontrado; i++) {
        for (int j = 1; j < M - 1 && !encontrado; j++) {
            if (terreno[i][j] == 42 &&
                terreno[i-1][j] == 7 && terreno[i+1][j] == 7 &&
                terreno[i][j-1] == 7 && terreno[i][j+1] == 7 &&
                terreno[i-1][j-1] == 7 && terreno[i-1][j+1] == 7 &&
                terreno[i+1][j-1] == 7 && terreno[i+1][j+1] == 7) {
                X = i + 1;
                Y = j + 1;
                encontrado = 1;
            }
        }
    }

    printf("%d %d\n", X, Y);

    return 0;
}
