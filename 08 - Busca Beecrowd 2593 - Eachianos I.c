#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int find_position(const char *text, const char *word);

int main() {
    char text[10001];
    char text_copy[10001];
    char words[128][51];
    int **positions;
    int n;

    // Lendo o texto
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Removendo a quebra de linha
    strcpy(text_copy, text); // Copiando o texto para text_copy

    // Lendo a quantidade de palavras
    scanf("%d", &n);

    // Alocando memória para positions
    positions = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        positions[i] = (int *)malloc(10001 * sizeof(int));
    }

    // Lendo as palavras
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Encontrando as posições das palavras no texto
    for (int i = 0; i < n; i++) {
        int j = 0;
        char *token = strtok(text_copy, " ");
        int pos = 0; // Posição atual no texto

        while (token != NULL) {
            int found_pos = find_position(token, words[i]);

            if (found_pos != -1) {
                positions[i][j++] = pos + found_pos;
            }

            pos += strlen(token) + 1; // Atualiza a posição no texto considerando o token atual e um espaço

            token = strtok(NULL, " ");
        }

        if (j == 0) {
            printf("-1\n"); // Palavra não encontrada
        } else {
            for (int k = 0; k < j; k++) {
                printf("%d", positions[i][k]);
                if (j > 1 && k != j-1){
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Restaurando text_copy para a próxima palavra
        strcpy(text_copy, text);
    }

    // Liberando memória alocada para positions
    for (int i = 0; i < n; i++) {
        free(positions[i]);
    }
    free(positions);

    return 0;
}

// Função para encontrar a primeira posição de uma palavra em um texto
int find_position(const char *text, const char *word) {
    const char *found = strstr(text, word);

    if (found) {
        // Verifica se é uma palavra completa
        if ((found == text || isspace(*(found - 1))) &&
            (*(found + strlen(word)) == '\0' || isspace(*(found + strlen(word))))) {
            return found - text;
        }
    }
    return -1;
}
