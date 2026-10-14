#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 30

void desenhaForca(int erros) {
    printf("\n  _______   \n");
    printf(" |/      |  \n");
    printf(" |      %s \n", erros >= 1 ? "( )" : "");
    printf(" |      %s \n", erros >= 3 ? "/|\\" : (erros == 2 ? " | " : ""));
    printf(" |       %s \n", erros >= 4 ? " | " : "");
    printf(" |      %s \n", erros >= 6 ? "/ \\" : (erros == 5 ? "/  " : ""));
    printf(" |          \n");
    printf("_|___       \n\n");
}

int main() {
    char palavraSecreta[TAMANHO_PALAVRA] = "PROGRAMACAO";
    int tamanho = strlen(palavraSecreta);
    char acertos[TAMANHO_PALAVRA];
    int erros = 0;
    int acertou = 0;
    char tentativa;

    for (int i = 0; i < tamanho; i++) {
        acertos[i] = '_';
    }
    acertos[tamanho] = '\0';

    printf("=========================================\n");
    printf("         JOGO DA FORCA EM C              \n");
    printf("=========================================\n");

    while (erros < MAX_TENTATIVAS && !acertou) {
        desenhaForca(erros);

        printf("Palavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", acertos[i]);
        }
        printf("\n\n");

        printf("Digite uma letra: ");
        scanf(" %c", &tentativa);
        tentativa = toupper(tentativa);

        int achou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == tentativa) {
                acertos[i] = tentativa;
                achou = 1;
            }
        }

        if (!achou) {
            erros++;
            printf("A letra '%c' não está na palavra! Tentativas restantes: %d\n", tentativa, MAX_TENTATIVAS - erros);
        }

        if (strcmp(palavraSecreta, acertos) == 0) {
            acertou = 1;
        }
    }

    desenhaForca(erros);

    if (acertou) {
        printf("Parabéns! Você venceu! A palavra era: %s\n", palavraSecreta);
    } else {
        printf("Você perdeu! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}
