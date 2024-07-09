#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char valor;
    struct cel *seg;
} celula;

void Empilha(celula **topo, char valor) {
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    nova->valor = valor;
    nova->seg = *topo;
    *topo = nova;
}

char Desempilha(celula **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    celula *q = *topo;
    char valor = q->valor;
    *topo = q->seg;
    free(q);
    return valor;
}

int main() {
    int n, i, j;
    char entrada[27], saida[27];
    celula *pilha;

    while (scanf("%d", &n) && n != 0) {
        for (i = 0; i < n; i++){
            scanf("%s", &entrada[i]);
        }
        //scanf("%s", entrada);
        for (i = 0; i < n; i++){
            scanf("%s", &saida[i]);
        }
        //scanf("%s", saida);

        char movimentos[2 * n + 1];
        int movIndex = 0;
        int impossivel = 0;

        pilha = NULL;
        i = 0;
        j = 0;

        while (i < n) {
            Empilha(&pilha, entrada[i]);
            movimentos[movIndex++] = 'I';
            while (pilha != NULL && pilha->valor == saida[j]) {
                Desempilha(&pilha);
                movimentos[movIndex++] = 'R';
                j++;
            }
            i++;
        }

        while (pilha != NULL && pilha->valor == saida[j]) {
            Desempilha(&pilha);
            movimentos[movIndex++] = 'R';
            j++;
        }

        movimentos[movIndex] = '\0';

        if (j == n) {
            printf("%s\n", movimentos);
        } else {
            printf("%s Impossible\n", movimentos);
        }
    }

    return 0;
}