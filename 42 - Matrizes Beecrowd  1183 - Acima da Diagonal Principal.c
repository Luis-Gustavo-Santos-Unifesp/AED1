#include <stdio.h>

int main() {
    char O;
    double M[12][12];
    double resultado = 0.0;
    int contador = 0;

    // Leitura da operação (Soma ou Média)
    scanf(" %c", &O);

    // Leitura dos elementos da matriz M
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Cálculo da soma dos elementos acima da diagonal principal
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            resultado += M[i][j];
            contador++;
        }
    }

    // Se a operação for média, dividir a soma pelo número de elementos
    if (O == 'M') {
        resultado /= contador;
    }

    // Impressão do resultado com 1 casa decimal
    printf("%.1f\n", resultado);

    return 0;
}
