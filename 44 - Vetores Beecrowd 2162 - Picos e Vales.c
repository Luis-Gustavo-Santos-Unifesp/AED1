#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int H[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    int padrao = 1; // Assumimos que a paisagem segue o padrão

    // Verificação do padrão
    for (int i = 1; i < N - 1; i++) {
        if (!((H[i] > H[i - 1] && H[i] > H[i + 1]) || (H[i] < H[i - 1] && H[i] < H[i + 1]))) {
            padrao = 0;
            break;
        }
    }

    // Verificação inicial para elementos consecutivos
    for (int i = 1; i < N; i++) {
        if (H[i] == H[i - 1]) {
            padrao = 0;
            break;
        }
    }

    printf("%d\n", padrao);

    return 0;
}
