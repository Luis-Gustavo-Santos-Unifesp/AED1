#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int horas_por_presente;
} Grupo;

// Função para calcular a quantidade de presentes por dia
int calcularPresentes(int num_elfos, char elfos[][20], char grupos_elfos[][20], int horas[], Grupo grupos[], int num_grupos) {
    int total_presentes = 0;
    int horas_nao_utilizadas[num_grupos];

    // Inicializar o array de horas não utilizadas
    for (int i = 0; i < num_grupos; i++) {
        horas_nao_utilizadas[i] = 0;
    }

    // Para cada elfo
    for (int i = 0; i < num_elfos; i++) {
        int presentes_elfo = 0;
        // Procurar o grupo correspondente na lista de grupos
        for (int j = 0; j < num_grupos; j++) {
            if (strcmp(grupos_elfos[i], grupos[j].nome) == 0) {
                // Calcular quantos presentes ele contribui
                presentes_elfo = (horas[i] / grupos[j].horas_por_presente);
                total_presentes += presentes_elfo;

                // Calcular horas não utilizadas e acumular
                int horas_restantes = horas[i] % grupos[j].horas_por_presente;
                horas_nao_utilizadas[j] += horas_restantes;

                break; // Encontrou o grupo, pode parar de procurar
            }
        }
    }

    // Calcular presentes adicionais a partir das horas não utilizadas
    for (int i = 0; i < num_grupos; i++) {
        total_presentes += (horas_nao_utilizadas[i] / grupos[i].horas_por_presente);
    }

    return total_presentes;
}

int main() {
    int N;
    scanf("%d", &N);

    char elfos[N][20]; // Array de nomes dos elfos
    char grupos_elfos[N][20]; // Array de grupos dos elfos
    int horas[N]; // Array de horas dos elfos

    // Leitura dos elfos
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d", elfos[i], grupos_elfos[i], &horas[i]);
    }

    // Inicializar os grupos de trabalho e suas horas necessárias por presente
    Grupo grupos[] = {
        {"bonecos", 8},
        {"arquitetos", 4},
        {"musicos", 6},
        {"desenhistas", 12}
    };
    int num_grupos = sizeof(grupos) / sizeof(Grupo);

    // Calcular a quantidade de presentes por dia
    int presentes_por_dia = calcularPresentes(N, elfos, grupos_elfos, horas, grupos, num_grupos);

    // Imprimir o resultado
    printf("%d\n", presentes_por_dia);

    return 0;
}
