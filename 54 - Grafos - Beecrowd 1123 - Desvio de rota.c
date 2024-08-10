#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

typedef struct {
    int vertice;
    int peso;
} Aresta;

typedef struct {
    int numVertices;
    int numArestas;
    Aresta **adjacencias;
} Grafo;

typedef struct {
    int vertice;
    int distancia;
} NoHeap;

typedef struct {
    NoHeap *dados;
    int tamanho;
    int capacidade;
} MinHeap;

Grafo *inicializaGrafo(int numVertices) {
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->numArestas = 0;
    grafo->adjacencias = (Aresta **)malloc(numVertices * sizeof(Aresta *));
    for (int i = 0; i < numVertices; i++) {
        grafo->adjacencias[i] = (Aresta *)malloc(numVertices * sizeof(Aresta));
        for (int j = 0; j < numVertices; j++) {
            grafo->adjacencias[i][j].vertice = -1;
            grafo->adjacencias[i][j].peso = INF;
        }
    }
    return grafo;
}

void insereAresta(Grafo *grafo, int origem, int destino, int peso) {
    grafo->adjacencias[origem][destino].vertice = destino;
    grafo->adjacencias[origem][destino].peso = peso;
    grafo->adjacencias[destino][origem].vertice = origem;
    grafo->adjacencias[destino][origem].peso = peso;
    grafo->numArestas++;
}

MinHeap *inicializaMinHeap(int capacidade) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->dados = (NoHeap *)malloc(capacidade * sizeof(NoHeap));
    minHeap->tamanho = 0;
    minHeap->capacidade = capacidade;
    return minHeap;
}

void insereMinHeap(MinHeap *minHeap, int vertice, int distancia) {
    if (minHeap->tamanho < minHeap->capacidade) {
        minHeap->dados[minHeap->tamanho].vertice = vertice;
        minHeap->dados[minHeap->tamanho].distancia = distancia;
        minHeap->tamanho++;
        // Heapify up
        int i = minHeap->tamanho - 1;
        while (i > 0 && minHeap->dados[i].distancia < minHeap->dados[(i - 1) / 2].distancia) {
            NoHeap temp = minHeap->dados[i];
            minHeap->dados[i] = minHeap->dados[(i - 1) / 2];
            minHeap->dados[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
}

void minHeapify(MinHeap *minHeap, int indice) {
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < minHeap->tamanho && minHeap->dados[esquerda].distancia < minHeap->dados[menor].distancia) {
        menor = esquerda;
    }
    if (direita < minHeap->tamanho && minHeap->dados[direita].distancia < minHeap->dados[menor].distancia) {
        menor = direita;
    }
    if (menor != indice) {
        NoHeap temp = minHeap->dados[indice];
        minHeap->dados[indice] = minHeap->dados[menor];
        minHeap->dados[menor] = temp;
        minHeapify(minHeap, menor);
    }
}

NoHeap extraiMinimo(MinHeap *minHeap) {
    NoHeap raiz = minHeap->dados[0];
    minHeap->dados[0] = minHeap->dados[minHeap->tamanho - 1];
    minHeap->tamanho--;
    minHeapify(minHeap, 0);
    return raiz;
}

int estaVazio(MinHeap *minHeap) {
    return minHeap->tamanho == 0;
}

int calculaMenorCaminho(Grafo *grafo, int cidadeInicial, int cidadeFinal, int numCidadesNaRota) {
    int *distancia = (int *)malloc(grafo->numVertices * sizeof(int));
    int *visitado = (int *)calloc(grafo->numVertices, sizeof(int));
    for (int i = 0; i < grafo->numVertices; i++) {
        distancia[i] = INF;
    }
    distancia[cidadeInicial] = 0;

    MinHeap *minHeap = inicializaMinHeap(grafo->numVertices);
    insereMinHeap(minHeap, cidadeInicial, 0);

    while (!estaVazio(minHeap)) {
        NoHeap noAtual = extraiMinimo(minHeap);
        int u = noAtual.vertice;

        if (visitado[u]) continue;
        visitado[u] = 1;

        for (int v = 0; v < grafo->numVertices; v++) {
            if (grafo->adjacencias[u][v].vertice != -1) {
                int peso = grafo->adjacencias[u][v].peso;
                if (u >= numCidadesNaRota || (u < numCidadesNaRota && v == u + 1)) {
                    if (distancia[u] + peso < distancia[v]) {
                        distancia[v] = distancia[u] + peso;
                        insereMinHeap(minHeap, v, distancia[v]);
                    }
                }
            }
        }
    }

    int resultado = distancia[cidadeFinal];
    free(distancia);
    free(visitado);
    free(minHeap->dados);
    free(minHeap);

    return resultado;
}

int main() {
    int N, M, C, K;
    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        Grafo *grafo = inicializaGrafo(N);

        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            insereAresta(grafo, U, V, P);
        }

        int resultado = calculaMenorCaminho(grafo, K, C - 1, C);
        printf("%d\n", resultado == INF ? -1 : resultado);

        for (int i = 0; i < N; i++) {
            free(grafo->adjacencias[i]);
        }
        free(grafo->adjacencias);
        free(grafo);
    }

    return 0;
}




