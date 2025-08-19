#include <stdio.h>

#define TAM 10
#define HAB 5 // tamanho fixo das matrizes de habilidade

/*
Desafio Mestre - Batalha Naval com Habilidades
- Tabuleiro 10x10.
- Navios (valor 3).
- Habilidades especiais:
    * Cone
    * Cruz
    * Octaedro
- Áreas de efeito marcadas como 5 no tabuleiro.
*/

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // Inicializa tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // ------------------ Coloca navios ------------------
    // Navio Horizontal
    int linhaH = 2, colunaH = 4;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio Vertical
    int linhaV = 5, colunaV = 7;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Navio Diagonal \.
    int linhaD1 = 0, colunaD1 = 0;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio Diagonal /.
    int linhaD2 = 0, colunaD2 = 9;
    for (i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // ------------------ Matrizes das habilidades ------------------
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // Cone (origem no topo, expandindo para baixo)
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (j >= (HAB/2 - i) && j <= (HAB/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Cruz (origem no centro)
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (i == HAB/2 || j == HAB/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Octaedro (losango) sem usar abs()
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            int distI = (i - HAB/2 >= 0) ? (i - HAB/2) : -(i - HAB/2);
            int distJ = (j - HAB/2 >= 0) ? (j - HAB/2) : -(j - HAB/2);

            if (distI + distJ <= HAB/2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ------------------ Sobreposição no tabuleiro ------------------
    // Função inline de aplicar habilidade
    int origemLinha, origemColuna;

    // Cone em (4,4)
    origemLinha = 4; origemColuna = 4;
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (cone[i][j] == 1) {
                int x = origemLinha + i - HAB/2;
                int y = origemColuna + j - HAB/2;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == 0)
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Cruz em (7,2)
    origemLinha = 7; origemColuna = 2;
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (cruz[i][j] == 1) {
                int x = origemLinha + i - HAB/2;
                int y = origemColuna + j - HAB/2;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == 0)
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Octaedro em (6,6)
    origemLinha = 6; origemColuna = 6;
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemLinha + i - HAB/2;
                int y = origemColuna + j - HAB/2;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == 0)
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // ------------------ Impressão do Tabuleiro ------------------
    printf("\n  Tabuleiro Final com Habilidades:\n\n");

    // Cabeçalho com letras
    printf("   ");
    for (i = 0; i < TAM; i++) {
        printf("%c ", letra[i]);
    }
    printf("\n");

    // Linhas do tabuleiro
    for (i = 0; i < TAM; i++) {
        printf("%d  ", i);
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);  // mostra 0, 3 ou 5
        }
        printf("\n");
    }

    return 0;
}