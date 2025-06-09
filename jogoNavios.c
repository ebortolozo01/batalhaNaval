#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3

// Função que inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR;
        }
    }
}

// Função para verificar se há sobreposição
bool verificaSobreposicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha[], int coluna[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha[i]][coluna[i]] == NAVIO) {
            return true;
        }
    }
    return false;
}

// Função para posicionar navio dado vetores de linha e coluna
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha[], int coluna[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha[i]][coluna[i]] = NAVIO;
    }
}

// Função que exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro 10x10:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Navio 1 – Horizontal (linha 1, coluna 2 até 4)
    int linha1[TAM_NAVIO] = {1, 1, 1};
    int coluna1[TAM_NAVIO] = {2, 3, 4};

    // Navio 2 – Vertical (linha 5 até 7, coluna 0)
    int linha2[TAM_NAVIO] = {5, 6, 7};
    int coluna2[TAM_NAVIO] = {0, 0, 0};

    // Navio 3 – Diagonal Principal (linha 6,7,8 e coluna 6,7,8)
    int linha3[TAM_NAVIO] = {6, 7, 8};
    int coluna3[TAM_NAVIO] = {6, 7, 8};

    // Navio 4 – Diagonal Secundária (linha 2,3,4 e coluna 7,6,5)
    int linha4[TAM_NAVIO] = {2, 3, 4};
    int coluna4[TAM_NAVIO] = {7, 6, 5};

    // Validação e posicionamento
    if (!verificaSobreposicao(tabuleiro, linha1, coluna1))
        posicionarNavio(tabuleiro, linha1, coluna1);

    if (!verificaSobreposicao(tabuleiro, linha2, coluna2))
        posicionarNavio(tabuleiro, linha2, coluna2);

    if (!verificaSobreposicao(tabuleiro, linha3, coluna3))
        posicionarNavio(tabuleiro, linha3, coluna3);

    if (!verificaSobreposicao(tabuleiro, linha4, coluna4))
        posicionarNavio(tabuleiro, linha4, coluna4);

    // Exibição final
    exibirTabuleiro(tabuleiro);

    return 0;
}
