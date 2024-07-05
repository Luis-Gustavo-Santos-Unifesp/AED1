#include <stdio.h>

int main() {

    char nome[20];
    double salarioFixo, totalVendas, receber;
    scanf("%s\n%lf\n%lf", &nome, &salarioFixo, &totalVendas);
    receber = salarioFixo + 0.15 * totalVendas;
    printf("TOTAL = R$ %.2lf\n", receber);

    return 0;
}