#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar()
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void mostrarRegras()
{
    limparTela();
    printf("=========== REGRAS DA BATALHA NAVAL ===========\n\n");
    printf("1) Cada jogador possui um tabuleiro 10x10.\n");
    printf("2) Cada jogador posiciona:\n");
    printf("   - 1 navio de tamanho 4\n");
    printf("   - 2 navios de tamanho 3\n");
    printf("   - 3 navios de tamanho 2\n\n");
    printf("3) Os jogadores atiram alternadamente.\n");
    printf("4) O objetivo é afundar todos os navios inimigos.\n");
    printf("5) Legenda do tabuleiro:\n");
    printf("   - 0 = água\n");
    printf("   - 1 ou 2 = navios\n");
    printf("   - -1 = tiro na água\n");
    printf("   - -2 = navio acertado\n\n");
    printf("6) Vence quem destruir todos os navios do oponente.\n\n");
    pausar();
}

int main()
{
    int opcao;

    while (1)
    {
        limparTela();

        printf("=========== BATALHA NAVAL ===========\n\n");
        printf("1 - Iniciar jogo\n");
        printf("2 - Regras\n");
        printf("3 - Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // consume '\n'

        switch (opcao)
        {
            case 1:
                limparTela();
                iniciarJogo();
                pausar();
                break;

            case 2:
                mostrarRegras();
                break;

            case 3:
                limparTela();
                printf("Saindo do jogo... Até logo!\n");
                return 0;

            default:
                printf("Opção inválida!\n");
                pausar();
        }
    }

    return 0;
}
