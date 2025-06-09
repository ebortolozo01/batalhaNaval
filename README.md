# 🚢 Batalha Naval - Nível Mestre

Este projeto em C simula um tabuleiro de Batalha Naval com **posicionamento de navios** e **habilidades especiais** com áreas de efeito.

## 🎯 Objetivo

Demonstrar domínio de:
- Arrays bidimensionais
- Estruturas de repetição aninhadas
- Condicionais
- Sobreposição de matrizes
- Visualização de padrões no tabuleiro

## 🧩 Funcionalidades

- Tabuleiro 10x10
- 4 navios de tamanho 3 (horizontal, vertical, diagonal principal e secundária)
- 3 tipos de habilidades com área de efeito:
  - **Cone**: forma triangular invertida
  - **Cruz**: linha vertical e horizontal com origem no centro
  - **Octaedro**: formato de losango

Cada área de habilidade é representada por `5`, enquanto água é `0` e navios são `3`.

## 📦 Estrutura

- `tabuleiro[10][10]`: representa o campo de batalha
- `habilidade[5][5]`: matriz 5x5 para cone, cruz ou octaedro
- Áreas de habilidade não sobrescrevem navios

## 📌 Exemplo de saída visual

```
0 0 5 0 0 0 0 0 0 0
0 5 5 5 0 0 0 0 0 0
5 5 3 5 5 0 0 0 0 0
0 0 3 0 0 0 0 0 0 0
0 0 3 0 0 0 0 0 0 0
0 0 0 0 0 0 3 0 0 0
0 0 0 0 0 0 3 5 5 5
0 0 0 0 0 0 0 3 0 0
0 0 0 0 0 0 0 0 3 0
0 0 0 0 0 0 0 0 0 3
```

## ⚙️ Como compilar e executar

```bash
gcc xadrez_habilidades.c -o xadrez
./xadrez
```

## 🧠 Aprendizados

- Como construir formas geométricas com loops e condicionais
- Como centralizar e sobrepor padrões em uma matriz maior
- Visualização de jogo via terminal

---

Projeto desenvolvido como parte de uma série de desafios em C sobre lógica e programação de jogos.

