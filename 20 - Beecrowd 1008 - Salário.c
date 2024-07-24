#include <stdio.h>

int main() {

    int n, h;
    float valorHora, salario;
    scanf("%d\n%d\n%f", &n, &h, &valorHora);
    salario = h * valorHora;
    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %.2f\n", salario);

    return 0;
}
