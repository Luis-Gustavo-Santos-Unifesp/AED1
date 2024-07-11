#include <stdio.h>

int main() {
    int L;
    char T;
    double M[12][12];
    double resultado = 0.0;

    // Leitura da linha L e do caractere T
    scanf("%d", &L);
    scanf(" %c", &T);  // Note o espaço antes de %c para ignorar qualquer espaço em branco

    // Leitura dos elementos da matriz M
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Realização da operação na linha L
    for (int j = 0; j < 12; j++) {
        resultado += M[L][j];
    }

    // Se a operação for média, dividir a soma pelo número de elementos
    if (T == 'M') {
        resultado /= 12.0;
    }

    // Impressão do resultado com 1 casa decimal
    printf("%.1f\n", resultado);

    return 0;
}
