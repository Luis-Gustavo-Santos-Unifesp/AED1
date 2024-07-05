#include <stdio.h>

int main() {
    int N, quantia, total_cobaias = 0;
    int total_coelhos = 0, total_ratos = 0, total_sapos = 0;
    char tipo;
    float perc_coelhos, perc_ratos, perc_sapos;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %c", &quantia, &tipo);
        total_cobaias += quantia;
        if (tipo == 'C') {
            total_coelhos += quantia;
        } else if (tipo == 'R') {
            total_ratos += quantia;
        } else if (tipo == 'S') {
            total_sapos += quantia;
        }
    }
    perc_coelhos = (total_coelhos * 100.0) / total_cobaias;
    perc_ratos = (total_ratos * 100.0) / total_cobaias;
    perc_sapos = (total_sapos * 100.0) / total_cobaias;
    printf("Total: %d cobaias\n", total_cobaias);
    printf("Total de coelhos: %d\n", total_coelhos);
    printf("Total de ratos: %d\n", total_ratos);
    printf("Total de sapos: %d\n", total_sapos);
    printf("Percentual de coelhos: %.2f %%\n", perc_coelhos);
    printf("Percentual de ratos: %.2f %%\n", perc_ratos);
    printf("Percentual de sapos: %.2f %%\n", perc_sapos);
    return 0;
}