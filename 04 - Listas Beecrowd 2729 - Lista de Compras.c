/*
Entrada
A primeira linha de entrada contém um inteiro N (N < 100) que indica a quantidade de casos de teste que vem a seguir, ou melhor, a quantidade de listas de compras que Valentina quer organizar. Cada lista de compra consiste de uma única linha que contém de 1 a 1000 itens ou palavras compostas apenas de letras minúsculas (de 1 a 20 letras), sem acentos e separadas por um espaço.

Saída
A saída contém N linhas, cada uma representando uma das listas de compras de Valentina, sem itens repetidos e em ordem alfabética.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_PALAVRA 21 // 20 caracteres + 1 para o caractere nulo

struct Item {
    char nome[TAM_MAX_PALAVRA];
    struct Item* prox;
};

struct Item* novoItem(char* nome);
void insere(struct Item** ref_cabeca, char* nome);
void imprime(struct Item* node);

int main(void) {
    int N;
    char *linha;
    size_t tamanho_max_linha = 1000 * (TAM_MAX_PALAVRA + 1); // Tamanho máximo da linha considerando 1000 palavras de até 20 caracteres cada

    linha = (char*)malloc(tamanho_max_linha * sizeof(char)); // Aloca memória para a linha de entrada
    if (linha == NULL) {
        printf("Erro: Falha ao alocar memória para linha.\n");
        return 1;
    }

    struct Item* cabeca = NULL;

    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        fgets(linha, tamanho_max_linha, stdin);
        linha[strcspn(linha, "\n")] = 0;

        // Limpa a lista para cada nova linha
        cabeca = NULL;

        char *token = strtok(linha, " ");
        while (token != NULL) {
            insere(&cabeca, token);
            token = strtok(NULL, " ");
        }
        imprime(cabeca);
    }

    free(linha); // Libera a memória alocada para a linha de entrada
    return 0;
}

struct Item* novoItem(char* nome) {
    struct Item* novoItem = (struct Item*)malloc(sizeof(struct Item));
    if (novoItem == NULL) {
        printf("Erro: Falha ao alocar memória para novoItem.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novoItem->nome, nome); // Usando strcpy para copiar a palavra completa
    novoItem->prox = NULL;
    return novoItem;
}

void insere(struct Item** ref_cabeca, char* nome) {
    struct Item* novo_item = novoItem(nome);
    struct Item* anterior = NULL;
    struct Item* atual = *ref_cabeca;

    if (*ref_cabeca == NULL || strcmp(novo_item->nome, atual->nome) < 0) {
        novo_item->prox = *ref_cabeca;
        *ref_cabeca = novo_item;
        return;
    }

    while (atual != NULL && strcmp(atual->nome, novo_item->nome) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        novo_item->prox = *ref_cabeca;
        *ref_cabeca = novo_item;
    } else {
        anterior->prox = novo_item;
        novo_item->prox = atual;
    }
}

void imprime(struct Item* node) {
    struct Item* atual = node;
    struct Item* proximo;

    while (atual != NULL) {
        printf("%s", atual->nome);
        proximo = atual->prox;

        // Avança até o próximo item diferente
        while (proximo != NULL && strcmp(atual->nome, proximo->nome) == 0) {
            proximo = proximo->prox;
        }

        atual = proximo;

        if (atual != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}
