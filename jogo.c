#include <stdio.h>
#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "estruturas.h"

void turno(Jogador *atacante, Jogador *defensor, int tab[10][10])
{
    printf("\n----- Turno de %s -----\n", atacante->nome);

    Posicao tiro = pegaJogada();

    if (tiro.linha < 0 || tiro.linha >= 10 || tiro.coluna < 0 || tiro.coluna >= 10)
    {
        printf("Tiro fora do tabuleiro! Turno perdido!\n");
        return;
    }

    int jogar = jogada(tab,atacante,tiro);
    
    if (jogar == 3)
        printf("Tiro na água! Turno perdido.\n");

    else if(jogar == 5)
    {
        printf("Local já acertado!\nTurno perdido\n");
    }
    else if (jogar == defensor->id)
    {
        printf("Acertou um navio!\n");

        // Atualiza navio acertado
        for (int i = 0; i < 6; i++)
        {
            Navio *n = &defensor->navios[i];

            // Verifica se o tiro está dentro dos limites do navio
            int dx = (n->posF.linha - n->posI.linha) == 0 ? 0 :
                     (n->posF.linha - n->posI.linha > 0 ? 1 : -1);
            int dy = (n->posF.coluna - n->posI.coluna) == 0 ? 0 :
                     (n->posF.coluna - n->posI.coluna > 0 ? 1 : -1);

            for (int k = 0; k < n->tam; k++)
            {
                int x = n->posI.linha + k * dx;
                int y = n->posI.coluna + k * dy;

                if (x == tiro.linha && y == tiro.coluna)
                {
                    if (checarNavio(n))
                    {
                        printf("Navio inimigo afundado!\n");
                        defensor->naviosEmJogo--;
                    }
                    return;
                }
            }
        }
    }
    else if(jogar == 4)
        printf("Atirou no seu próprio navio\n");
    else
        printf("Erro inesperado no tabuleiro.\n");
}

int jogoTerminado(Jogador *j1, Jogador *j2)
{
    if (perdeu(j1))
    {
        printf("\n%s venceu o jogo!\n", j2->nome);
        return 1;
    }
    if (perdeu(j2))
    {
        printf("\n%s venceu o jogo!\n", j1->nome);
        return 1;
    }
    return 0;
}

void iniciarJogo()
{
    Jogador j1, j2; //jogador 1 e jogador 2

    printf("=== Batalha Naval ===\n\n");

    printf("Nome do Jogador 1: ");
    getNome(&j1);
    j1.id = 1;

    printf("Nome do Jogador 2: ");
    getNome(&j2);
    j2.id = 2;

    int tab1[10][10];
    int tab2[10][10];

    inicializaTabuleiro(tab1);
    inicializaTabuleiro(tab2);

    printf("\n--- %s, posicione seus navios ---\n", j1.nome);
    navios(&j1, tab1);

    printf("\n--- %s, posicione seus navios ---\n", j2.nome);
    navios(&j2, tab2);

    printf("\nTodos os navios foram posicionados! Vamos começar.\n");

    while (!jogoTerminado(&j1, &j2))
    {
        turno(&j1, &j2, tab2);
        if (jogoTerminado(&j1, &j2)) break;

        turno(&j2, &j1, tab1);
    }

    printf("\nJogo encerrado.\n");
}