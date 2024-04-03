/*
Hoje é a inauguração de um grande supermercado em sua cidade, e todos estão muito excitados com os baixos preços prometidos.

Este supermercado tem N funcionários que trabalham no caixa, identificados por números de 1 a N, onde cada funcionário leva um determinado tempo vi para processar um item de um cliente. Ou seja, se um cliente tem cj itens em sua cesta, um determinado funcionário levará vi*cj segundos para processar todos os itens deste cliente.

Quando um cliente entra na fila para ser atendido ele espera até que um funcionário esteja livre para o atendê-lo. Se mais de um funcionário estiverem livres ao mesmo tempo, o cliente será atendido pelo funcionário de menor número de identificação. Tal funcionário só estará livre novamente após processar todos os itens deste cliente.

Há M clientes na fila para serem atendidos, cada um com um determinado número de itens na sua cesta. Dadas as informações sobre os funcionários nos caixas e os clientes, o gerente pediu sua ajuda para descobrir quanto tempo levará para que todos os clientes sejam atendidos.

Entrada
A primeira linha conterá dois inteiros N e M, indicando o número de funcionários no caixa e o número de clientes, respectivamente (1 ≤ N ≤ M ≤ 104).

Em seguida haverá N inteiros vi, indicando quanto tempo leva para o i-ésimo funcionário processar um item (1 ≤ vi ≤ 100, para todo 1 ≤ i ≤ N).

Em seguida haverá M inteiros cj, indicando quantos itens o j-ésimo cliente tem em sua cesta (1 ≤ cj ≤ 100, para todo 1 ≤ j ≤ M).

Saída
Imprima uma linha contendo um inteiro, indicando quanto tempo levará para que todos os clientes sejam atendidos.
  */
#include <stdio.h>
#include <stdlib.h>

//Ainda só consegui resolver com vetores. Estou trabalhando em uma versão com a criação de uma estrutura de dados do tipo fila para os clientes
int main() {
    int N, M, i, j;
    scanf("%d %d", &N, &M);

    int *funcionarios = (int*) malloc(N * sizeof(int));
    int *clientes = (int*) malloc(M * sizeof(int));

    // Lendo os tempos dos funcionários
    for (i = 0; i < N; i++) {
        scanf("%d", &funcionarios[i]);
    }

    // Lendo o número de itens na cesta de cada cliente
    for (i = 0; i < M; i++) {
        scanf("%d", &clientes[i]);
    }

    // Inicializando o tempo de processamento acumulado de cada funcionário
    long long *tempo_acumulado = (long long*) calloc(N, sizeof(long long));

    // Atendendo os clientes
    long long tempo_total = 0; // Usamos long long para evitar estouro de int
    for (i = 0; i < M; i++) {
        // Encontrando o funcionário com o menor tempo de processamento acumulado
        int idx_funcionario_min = 0;
        for (j = 1; j < N; j++) {
            if (tempo_acumulado[j] < tempo_acumulado[idx_funcionario_min]) {
                idx_funcionario_min = j;
            }
        }
        // Atribuindo o cliente ao funcionário e atualizando o tempo de processamento acumulado
        tempo_acumulado[idx_funcionario_min] += (long long) clientes[i] * funcionarios[idx_funcionario_min];
        // Atualizando o tempo total de atendimento
        if (tempo_acumulado[idx_funcionario_min] > tempo_total) {
            tempo_total = tempo_acumulado[idx_funcionario_min];
        }
    }

    printf("%lld\n", tempo_total);

    free(funcionarios);
    free(clientes);
    free(tempo_acumulado);

    return 0;
}
