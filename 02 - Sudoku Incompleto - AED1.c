#include <stdbool.h>
#include <stdio.h>

#define SIZE 9

bool checkRow(int grid[SIZE][SIZE], int row, int num) {
  for (int col = 0; col < SIZE; col++) {
    if (grid[row][col] == num) {
      return false;
    }
  }
  return true;
}

bool checkCol(int grid[SIZE][SIZE], int col, int num) {
  for (int row = 0; row < SIZE; row++) {
    if (grid[row][col] == num) {
      return false;
    }
  }
  return true;
}

bool checkBox(int grid[SIZE][SIZE], int startRow, int startCol, int num) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (grid[row + startRow][col + startCol] == num) {
        return false;
      }
    }
  }
  return true;
}

bool isValidMove(int grid[SIZE][SIZE], int row, int col, int num) {
  return checkRow(grid, row, num) && checkCol(grid, col, num) &&
         checkBox(grid, row - row % 3, col - col % 3, num);
}

bool isSudokuValid(int grid[SIZE][SIZE]) {
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      if (grid[row][col] != 0) {
        int num = grid[row][col];
        grid[row][col] = 0;
        if (!isValidMove(grid, row, col, num)) {
          return false;
        }
        grid[row][col] = num;
      }
    }
  }
  return true;
}

int main() {
  int n = 1, opcao, l, c, palpite, qtdZeros = 0;
  // scanf("%d", &n);

  for (int k = 0; k < n; k++) {
    int grid[SIZE][SIZE];

    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");

    // Verificando se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return 1;
    }

    // Lendo os valores do arquivo e preenchendo a matriz
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        fscanf(arquivo, "%d", &grid[i][j]);
        if(grid[i][j] == 0) qtdZeros++;
      }
    }

    // Fechando o arquivo
    fclose(arquivo);

    while(qtdZeros > 0){
      // Exibindo a matriz atual
      printf("Matriz atual:\n");
      for (int i = 0; i < SIZE; i++) {
          for (int j = 0; j < SIZE; j++) {
              printf("%d ", grid[i][j]);
          }
          printf("\n");
      }
      printf("\nDigite linha coluna palpite para substituir um zero\nda matriz acima (ex. 1 5 7): ");
      scanf("%d %d %d", &l, &c, &palpite);
      grid[l-1][c-1] = palpite;
      if (isSudokuValid(grid)) {
          printf("Palpite válido!\n\n");
          qtdZeros--;
      } else {
          grid[l-1][c-1] = 0;
          printf("Palpite inválido!\n\n");
      }
    }
    printf("\nVocê completou o Sudoku corretamente! Parabéns!");
  }

  return 0;
}
