#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_MAXIMO 300

// Estrutura de nó da pilha
typedef struct No {
    char dado;
    struct No* prox;
} No;

// Estrutura da pilha
typedef struct {
    No* topo;
} Pilha;

// Inicialização da pilha
void inicializar(Pilha* p) {
    p->topo = NULL;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha* p) {
    return p->topo == NULL;
}

// Função para empilhar um elemento
void empilhar(Pilha* p, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = valor;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

// Função para desempilhar um elemento
char desempilhar(Pilha* p) {
    if (estaVazia(p)) {
        printf("Subfluxo de pilha\n");
        exit(EXIT_FAILURE);
    }
    No* temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

// Função para obter o topo da pilha sem removê-lo
char topo(Pilha* p) {
    if (estaVazia(p)) {
        printf("Subfluxo de pilha\n");
        exit(EXIT_FAILURE);
    }
    return p->topo->dado;
}

// Função que verifica se um caractere é um operador
int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Função que verifica a precedência dos operadores
int precedencia(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return -1;
}

// Função para converter expressão infix para postfix
void infixParaPostfix(char *expressao, char *resultado) {
    Pilha pilha;
    inicializar(&pilha);

    int tamanho = strlen(expressao);
    int j = 0;

    for (int i = 0; i < tamanho; i++) {
        char atual = expressao[i];

        if (isalnum(atual)) { // Se for uma letra ou número
            resultado[j++] = atual;
        } else if (atual == '(') {
            empilhar(&pilha, atual);
        } else if (atual == ')') {
            while (!estaVazia(&pilha) && topo(&pilha) != '(') {
                resultado[j++] = desempilhar(&pilha);
            }
            if (!estaVazia(&pilha) && topo(&pilha) != '(') {
                printf("Expressão inválida\n");
                exit(EXIT_FAILURE);
            } else {
                desempilhar(&pilha);
            }
        } else { // Se for um operador
            while (!estaVazia(&pilha) && precedencia(atual) <= precedencia(topo(&pilha))) {
                resultado[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, atual);
        }
    }

    // Desempilhar qualquer operador restante na pilha
    while (!estaVazia(&pilha)) {
        resultado[j++] = desempilhar(&pilha);
    }

    resultado[j] = '\0'; // Terminador de string
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Para consumir a quebra de linha após N

    char resultados[N][TAMANHO_MAXIMO]; // Definindo tamanho do array de resultados de acordo com o número de casos de teste

    for (int i = 0; i < N; i++) {
        char expressao[TAMANHO_MAXIMO];
        fgets(expressao, TAMANHO_MAXIMO, stdin);
        infixParaPostfix(expressao, resultados[i]);
    }

    // Imprimir resultados
    for (int i = 0; i < N; i++) {
        printf("%s", resultados[i]);
    }

    return 0;
}
