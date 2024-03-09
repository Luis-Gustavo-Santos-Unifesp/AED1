#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 9

bool verificaLinha(int matriz[TAMANHO][TAMANHO], int linha, int num);

bool verificaColuna(int matriz[TAMANHO][TAMANHO], int coluna, int num);

bool verificaBloco(int matriz[TAMANHO][TAMANHO], int linhaInicio, int ColunaInicio, int num);

bool validaLinhaColunaBloco(int matriz[TAMANHO][TAMANHO], int linha, int coluna, int num);

bool validaSudoku(int matriz[TAMANHO][TAMANHO]);

int main() {

    /*
    Programa l� inicialmente um n�mero n > 0 de
    matrizes na entrada. Nas linhas seguintes devem ser
    dadas as n matrizes. Cada matriz � dada em 9 linhas,
    em que cada linha cont�m 9 n�meros inteiros, separados
    por um espa�o.

    Como sa�da, o programa imprime para cada instancia
    um conjunto de 3 linhas: a primeira diz "Instancia k",
    onde k � o n�mero de cada inst�ncia. A segunda linha
    diz "SIM" se a matriz for a solu��o de um problema de
    Sudoku, e "NAO" caso contr�rio. Na terceira linha o
    programa imprime uma linha em branco.
    */

    int n;
    scanf("%d", &n);

    bool results[n];

    for (int k = 0; k < n; k++) {
        int matriz[TAMANHO][TAMANHO];
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        results[k] = validaSudoku(matriz);
    }

    for (int k = 0; k < n; k++) {
        if (results[k]) {
            printf("Instancia %d\nSIM\n\n", k + 1);
        } else {
            printf("Instancia %d\nNAO\n\n", k + 1);
        }
    }

    return 0;
}

bool verificaLinha(int matriz[TAMANHO][TAMANHO], int linha, int num) {
    for (int coluna = 0; coluna < TAMANHO; coluna++) {
        if (matriz[linha][coluna] == num) {
            return false;
        }
    }
    return true;
}

bool verificaColuna(int matriz[TAMANHO][TAMANHO], int coluna, int num) {
    for (int linha = 0; linha < TAMANHO; linha++) {
        if (matriz[linha][coluna] == num) {
            return false;
        }
    }
    return true;
}

bool verificaBloco(int matriz[TAMANHO][TAMANHO], int linhaInicio, int ColunaInicio, int num) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (matriz[linha + linhaInicio][coluna + ColunaInicio] == num) {
                return false;
            }
        }
    }
    return true;
}

bool validaLinhaColunaBloco(int matriz[TAMANHO][TAMANHO], int linha, int coluna, int num) {
    return verificaLinha(matriz, linha, num) && verificaColuna(matriz, coluna, num) &&
           verificaBloco(matriz, linha - linha % 3, coluna - coluna % 3, num);
}

bool validaSudoku(int matriz[TAMANHO][TAMANHO]) {
    for (int linha = 0; linha < TAMANHO; linha++) {
        for (int coluna = 0; coluna < TAMANHO; coluna++) {
            if (matriz[linha][coluna] != 0) {
                int num = matriz[linha][coluna];
                matriz[linha][coluna] = 0;
                if (!validaLinhaColunaBloco(matriz, linha, coluna, num)) {
                    return false;
                }
                matriz[linha][coluna] = num;
            }
        }
    }
    return true;
}
