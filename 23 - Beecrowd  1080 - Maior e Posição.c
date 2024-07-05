#include <stdio.h>

int main() {
    int valores[100];
    int maior_valor, posicao;
    for (int i = 0; i < 100; i++) {
        scanf("%d", &valores[i]);
    }
    maior_valor = valores[0];
    posicao = 1;
    for (int i = 1; i < 100; i++) {
        if (valores[i] > maior_valor) {
            maior_valor = valores[i];
            posicao = i + 1;
        }
    }
    printf("%d\n%d\n", maior_valor, posicao);
    return 0;
}