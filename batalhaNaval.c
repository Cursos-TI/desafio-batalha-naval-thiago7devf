#include <stdio.h>

/*
Desafio Aventureiro - Batalha Naval
- Tabuleiro 10x10 representado por matriz com zeros (água).
- 4 navios no total:
    * 2 retos (horizontal e vertical).
    * 2 diagonais (\ e /).
- Cada navio tem tamanho fixo de 3.
- Posições dos navios = 3.
- Garantir que:
    * navios não saiam do tabuleiro.
    * navios não se sobreponham.
*/

int main() {
    int tabuleiro[10][10]; 
    int i, j; 

    // letras do cabeçalho
    char letra[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Inicializa o tabuleiro com água 0
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // NAVIO 1: Horizontal

    int linhaH = 2;
    int colunaH = 4;

    if (colunaH + tamanhoNavio <= 10) {
        int pode = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaH][colunaH + i] == 3) pode = 0;
        }
        if (pode) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        }
    }
    // NAVIO 2: Vertical
    int linhaV = 5;
    int colunaV = 7;

    if (linhaV + tamanhoNavio <= 10) {
        int pode = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) pode = 0;
        }
        if (pode) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }
    // NAVIO 3: Diagonal \ .
    int linhaD1 = 0;
    int colunaD1 = 0;

    if (linhaD1 + tamanhoNavio <= 10 && colunaD1 + tamanhoNavio <= 10) {
        int pode = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 3) pode = 0;
        }
        if (pode) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }
    // NAVIO 4: Diagonal /.
    int linhaD2 = 0;
    int colunaD2 = 9;

    if (linhaD2 + tamanhoNavio <= 10 && colunaD2 - (tamanhoNavio - 1) >= 0) {
        int pode = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == 3) pode = 0;
        }
        if (pode) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // Impressão do Tabuleiro
    printf("\n  Tabuleiro Final:\n");

    // imprime cabeçalho letras
    printf("   ");
    for (i = 0; i < 10; i++) {
        printf("%c ", letra[i]);
    }
    printf("\n");

    // imprime linhas com índice
    for (i = 0; i < 10; i++) {
        printf("%d  ", i);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}