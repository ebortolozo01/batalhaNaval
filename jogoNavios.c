#include <stdio.h>
#include <stdbool.h>

/*
 * Desafio: Batalha Naval - Posicionando Navios (Nível Novato)
 * Representa um tabuleiro 10x10 e posiciona dois navios de tamanho 3:
 * um horizontal e um vertical. Utiliza arrays, loops aninhados e validações básicas.
 */

// Constantes para o tabuleiro e navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3

int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR;
        }
    }

    // Coordenadas iniciais dos navios (fixas)
    int linhaNavioH = 2, colunaNavioH = 1;  // Navio horizontal
    int linhaNavioV = 4, colunaNavioV = 7;  // Navio vertical

    bool sobreposicao = false;

    // Verifica se o navio horizontal cabe
    if (colunaNavioH + TAM_NAVIO <= TAM_TABULEIRO) {
        // Verifica se há sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaNavioH][colunaNavioH + i] == NAVIO) {
                sobreposicao = true;
            }
        }
        // Posiciona se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaNavioH][colunaNavioH + i] = NAVIO;
            }
        }
    }

    // Verifica se o navio vertical cabe
    if (linhaNavioV + TAM_NAVIO <= TAM_TABULEIRO) {
        sobreposicao = false;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaNavioV + i][colunaNavioV] == NAVIO) {
                sobreposicao = true;
            }
        }
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaNavioV + i][colunaNavioV] = NAVIO;
            }
        }
    }

    // Exibição do tabuleiro
    printf("Tabuleiro 10x10 com navios posicionados (3 = navio, 0 = água):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
