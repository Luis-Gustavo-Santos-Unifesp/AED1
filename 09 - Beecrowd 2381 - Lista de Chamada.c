#include <stdlib.h>
#include <string.h>

// Função para comparar strings (utilizada no qsort)
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, K;

    // Passo 1: Ler N e K
    scanf("%d %d", &N, &K);

    // Aloca memória para armazenar os nomes dos alunos
    char **nomes = (char **)malloc(N * sizeof(char *));

    // Passo 2: Ler os nomes dos alunos e armazená-los em uma lista
    for (int i = 0; i < N; i++) {
        nomes[i] = (char *)malloc(21 * sizeof(char)); // Aloca memória para o nome (20 caracteres + terminador nulo)
        scanf("%s", nomes[i]);
    }

    // Passo 3: Ordenar a lista de nomes em ordem alfabética
    qsort(nomes, N, sizeof(char *), compare);

    // Passo 4: Encontrar o nome do aluno na posição K na lista ordenada
    char *nome_do_aluno = nomes[K - 1];

    // Passo 5: Imprimir o nome do aluno encontrado
    printf("%s\n", nome_do_aluno);

    // Libera a memória alocada
    for (int i = 0; i < N; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}