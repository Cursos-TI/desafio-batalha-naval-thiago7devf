#include <stdio.h>

/*
Desafio novato de batalha naval
- Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval. Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. Inicialize todas as posições do tabuleiro com o valor 0, representando água.
 
Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.
 
Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console. Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios. A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios. 
Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização
*/

int main() {
    int tabuleiro[10][10]; // define o tamanho do tabuleiro
    int i, j; // linha e coluna

    // define as letrs do tabuleiro final
    char letra [10] = {'A','B','C','D','E','G','H','I','J','K'};

    // Inicializa "escrevendo" todo o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // Coordenadas iniciais do navio horizontal
    int linhaH = 2;
    int colunaH = 4;

    // Coordenadas iniciais do navio vertical
    int linhaV = 5;
    int colunaV = 7;

    // Posiciona o navio horizontal (se couber)
    if (colunaH + tamanhoNavio <= 10) {
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal nao cabe no tabuleiro!\n");
    }

    // Posiciona o navio vertical (se couber e não sobrepor)
    if (linhaV + tamanhoNavio <= 10) {
        int podePosicionar = 1;
        for (i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 3) {
                podePosicionar = 0;
                break;
            }
        }

        if (podePosicionar == 1) {
            for (i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: navio vertical sobrepoe outro navio!\n");
        }
    } else {
        printf("Erro: navio vertical nao cabe no tabuleiro!\n");
    }

    // Imprime o tabuleiro pronto
    printf("\n  Tabuleiro Final:\n");

    // imprime as letras do tabuleiro
    printf("  ");
    for (i = 0; i < 10; i++){
        printf("%c ", letra[i]);
    }
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("%d " , i);// imprime os numeros do tabuleiro
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}