#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, z;  // x e y são cidades, z é o peso da aresta (distância)
} Aresta;

int *pai, *tamanho;  // Union-Find arrays

// Função para encontrar o representante do conjunto
int find(int u) {
    if (u != pai[u]) {
        pai[u] = find(pai[u]);  // Compressão de caminho
    }
    return pai[u];
}

// Função para unir dois conjuntos
void unir(int u, int v) {
    int raiz_u = find(u);
    int raiz_v = find(v);
    if (raiz_u != raiz_v) {
        if (tamanho[raiz_u] > tamanho[raiz_v]) {
            pai[raiz_v] = raiz_u;
        } else if (tamanho[raiz_u] < tamanho[raiz_v]) {
            pai[raiz_u] = raiz_v;
        } else {
            pai[raiz_v] = raiz_u;
            tamanho[raiz_u]++;
        }
    }
}

// Função de comparação para ordenar as arestas pelo peso
int compara(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->z - arestaB->z;
}

int main() {
    int M, N;

    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;  // Condição de parada

        Aresta arestas[N];
        pai = (int *)malloc(M * sizeof(int));
        tamanho = (int *)malloc(M * sizeof(int));

        // Inicializar Union-Find
        for (int i = 0; i < M; i++) {
            pai[i] = i;
            tamanho[i] = 0;
        }

        // Ler as arestas
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].x, &arestas[i].y, &arestas[i].z);
        }

        // Ordenar as arestas pelo peso
        qsort(arestas, N, sizeof(Aresta), compara);

        long long custo_total = 0;  // Soma das distâncias da árvore espalhada mínima

        // Aplicar o algoritmo de Kruskal
        for (int i = 0; i < N; i++) {
            int u = arestas[i].x;
            int v = arestas[i].y;
            int peso = arestas[i].z;

            // Se os vértices não estão no mesmo conjunto, une-os e adiciona o peso
            if (find(u) != find(v)) {
                unir(u, v);
                custo_total += peso;
            }
        }

        printf("%lld\n", custo_total);  // Imprime o custo total da árvore geradora mínima

        free(pai);
        free(tamanho);
    }

    return 0;
}
