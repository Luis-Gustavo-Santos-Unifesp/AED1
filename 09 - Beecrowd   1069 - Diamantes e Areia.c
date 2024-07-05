#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de pilha
typedef struct {
    int top;
    int capacity;
    char *array;
} Stack;

// Função para criar uma nova pilha
Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Função para empurrar um elemento para a pilha
void push(Stack *stack, char item) {
    stack->array[++stack->top] = item;
}

// Função para remover um elemento do topo da pilha
char pop(Stack *stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

// Função para contar os diamantes possíveis
int countDiamonds(char *s) {
    Stack *stack = createStack(strlen(s));
    int diamonds = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '<') {
            push(stack, '<');
        } else if (s[i] == '>') {
            if (!isEmpty(stack) && stack->array[stack->top] == '<') {
                diamonds++;
                pop(stack);
            }
        }
    }

    free(stack->array);
    free(stack);
    return diamonds;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Limpar o buffer

    char **inputs = (char **)malloc(N * sizeof(char *));
    int *results = (int *)malloc(N * sizeof(int));

    // Ler todas as entradas
    for (int i = 0; i < N; i++) {
        char *s = (char *)malloc(1001 * sizeof(char));
        fgets(s, 1001, stdin);
        inputs[i] = s;
        results[i] = countDiamonds(s);
    }

    // Imprimir as saídas
    for (int i = 0; i < N; i++) {
        printf("%d\n", results[i]);
        free(inputs[i]); // Liberar memória alocada para cada entrada
    }

    free(inputs); // Liberar memória alocada para a matriz de entradas
    free(results); // Liberar memória alocada para o array de resultados

    return 0;
}