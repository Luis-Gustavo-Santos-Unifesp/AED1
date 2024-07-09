#include <stdio.h>
#include <stdlib.h>

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

int VerificaParenteses(char expressao[]) {
    celula *pilha = NULL;
    int i = 0;

    while (expressao[i] != '\0') {
        if (expressao[i] == '(') {
            Empilha(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (pilha == NULL || Desempilha(&pilha) != '(') {
                return 0; // Encontrou um ')' sem '(' correspondente
            }
        }
        i++;
    }

    if (pilha != NULL) {
        return 0; // Ainda há '(' não fechados
    }

    return 1; // Todos os parênteses estão corretos
}

int main() {
    char expressao[1001];

    while (scanf("%[^\n]%*c", expressao) != EOF) {
        if (VerificaParenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        if (expressao[0] == '\0') {
            break; // Parar ao encontrar uma linha em branco
        }
    }

    return 0;
}
