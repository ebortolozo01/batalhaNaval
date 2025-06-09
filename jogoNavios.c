#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define MAR 0
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HAB 5  // tamanho das matrizes de habilidade (5x5)

// Inicializa o tabuleiro com 0
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = MAR;
        }
    }
}

// Posiciona navios fixos (como nível anterior)
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[2][2 + i] = NAVIO;
    }
    // Navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[5 + i][7] = NAVIO;
    }
    // Diagonal principal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[6 + i][6 + i] = NAVIO;
    }
    // Diagonal secundária
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[2 + i][7 - i] = NAVIO;
    }
}

// Constrói matriz de habilidade em forma de cone (pontudo no topo)
void construirHabilidadeCone(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                hab[i][j] = 1;
            } else {
                hab[i][j] = 0;
            }
        }
    }
}

// Constrói matriz de habilidade em forma de cruz
void construirHabilidadeCruz(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                hab[i][j] = 1;
            } else {
                hab[i][j] = 0;
            }
        }
    }
}

// Constrói matriz de habilidade em forma de octaedro (losango)
void construirHabilidadeOctaedro(int hab[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                hab[i][j] = 1;
            } else {
                hab[i][j] = 0;
            }
        }
    }
}

// Sobrepõe a matriz de habilidade no tabuleiro, marcando com 5
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HAB][TAM_HAB],
                       int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tabLinha = origemLinha - TAM_HAB / 2 + i;
            int tabColuna = origemColuna - TAM_HAB / 2 + j;
            if (tabLinha >= 0 && tabLinha < TAM_TABULEIRO &&
                tabColuna >= 0 && tabColuna < TAM_TABULEIRO &&
                habilidade[i][j] == 1 &&
                tabuleiro[tabLinha][tabColuna] == MAR) {
                tabuleiro[tabLinha][tabColuna] = HABILIDADE;
            }
        }
    }
}

// Exibe o tabuleiro com formatação
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Legenda: 0=Água | 3=Navio | 5=Habilidade

");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("
");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirHabilidadeCone(cone);
    construirHabilidadeCruz(cruz);
    construirHabilidadeOctaedro(octaedro);

    // Aplicando habilidades com origem definida
    aplicarHabilidade(tabuleiro, cone, 3, 4);       // centro aproximado do cone
    aplicarHabilidade(tabuleiro, cruz, 6, 6);       // centro da cruz
    aplicarHabilidade(tabuleiro, octaedro, 1, 1);   // centro do losango

    exibirTabuleiro(tabuleiro);
    return 0;
}
