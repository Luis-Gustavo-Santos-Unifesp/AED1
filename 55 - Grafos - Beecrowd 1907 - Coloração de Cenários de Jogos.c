#include <stdio.h>

#define MAX 1024

// Movimentos possíveis (esquerda, direita, para cima, para baixo)
int movimentos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Estrutura para representar a fila da BFS
typedef struct {
    int x, y;
} Posicao;

Posicao fila[MAX * MAX];
int frente, tras;

// Função para inicializar a fila
void inicializar_fila() {
    frente = tras = 0;
}

// Função para adicionar um elemento à fila
void enfileirar(int x, int y) {
    fila[tras++] = (Posicao){x, y};
}

// Função para remover um elemento da fila
Posicao desenfileirar() {
    return fila[frente++];
}

// Função para verificar se a fila está vazia
int fila_vazia() {
    return frente == tras;
}

// Função para realizar a BFS e marcar todos os pixels conectados
void bfs(int x, int y, int N, int M, char imagem[N][M], int visitado[N][M]) {
    inicializar_fila();
    enfileirar(x, y);
    visitado[x][y] = 1;

    while (!fila_vazia()) {
        Posicao p = desenfileirar();

        for (int i = 0; i < 4; i++) {
            int novo_x = p.x + movimentos[i][0];
            int novo_y = p.y + movimentos[i][1];

            if (novo_x >= 0 && novo_x < N && novo_y >= 0 && novo_y < M && 
                imagem[novo_x][novo_y] == '.' && !visitado[novo_x][novo_y]) {
                visitado[novo_x][novo_y] = 1;
                enfileirar(novo_x, novo_y);
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char imagem[N][M];
    int visitado[N][M];

    // Leitura da imagem e inicialização da matriz de visitados
    for (int i = 0; i < N; i++) {
        scanf("%s", imagem[i]);
        for (int j = 0; j < M; j++) {
            visitado[i][j] = 0;
        }
    }

    int cliques = 0;

    // Percorre todos os pixels da imagem
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (imagem[i][j] == '.' && !visitado[i][j]) {
                bfs(i, j, N, M, imagem, visitado);
                cliques++;
            }
        }
    }

    printf("%d\n", cliques);
    return 0;
}
