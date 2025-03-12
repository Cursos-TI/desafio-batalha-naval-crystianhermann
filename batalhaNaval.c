#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3  

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    // Imprimir cabeçalho das colunas
    printf("   ");
    for (char c = 'A'; c < 'A' + TAMANHO; c++) {
        printf("%c ", c);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Imprimir número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {  // Navio horizontal
        if (coluna + NAVIO > TAMANHO) return 0; // Validação de limite
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Validação de sobreposição
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'V') {  // Navio vertical
        if (linha + NAVIO > TAMANHO) return 0; // Validação de limite
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Validação de sobreposição
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else {
        return 0; // Direção inválida
    }
    return 1; // Sucesso
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definição fixa das coordenadas dos navios
    int linha1 = 2, coluna1 = 3;
    int linha2 = 5, coluna2 = 6;

    // Posicionando os navios
    if (!posicionarNavio(tabuleiro, linha1, coluna1, 'H')) {
        printf("Erro ao posicionar navio horizontal!\n");
    }
    if (!posicionarNavio(tabuleiro, linha2, coluna2, 'V')) {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibir o tabuleiro final
    printf("Tabuleiro final:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}