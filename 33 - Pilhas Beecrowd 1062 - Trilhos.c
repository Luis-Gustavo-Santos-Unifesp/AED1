#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void Empilha(celula **topo, int valor) {
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    nova->valor = valor;
    nova->seg = *topo;
    *topo = nova;
}

int Desempilha(celula **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    celula *q = *topo;
    int valor = q->valor;
    *topo = q->seg;
    free(q);
    return valor;
}

int verificaPermutacao(int *vagao, int n) {
    celula *pilha = NULL;
    int i = 0, j = 0;

    for (i = 1; i <= n; i++) {
        Empilha(&pilha, i);

        while (pilha != NULL && pilha->valor == vagao[j]) {
            Desempilha(&pilha);
            j++;
        }
    }

    return (pilha == NULL);
}

int main() {
    int n, i;
    int vagao[1000];

    while (scanf("%d", &n) && n != 0) {
        while (1) {
            for (i = 0; i < n; i++) {
                scanf("%d", &vagao[i]);
                if (vagao[0] == 0) break;
            }
            if (vagao[0] == 0) break;

            if (verificaPermutacao(vagao, n)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }

    return 0;
}
