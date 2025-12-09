#ifndef JOGADOR_H
#define JOGADOR_H

#include "estruturas.h"

// Lê o nome do jogador e armazena no struct
void getNome(Jogador *jogador);

// Pede uma jogada (linha, coluna)
Posicao pegaJogada();


int jogada(int tab[10][10],Jogador *jogador, Posicao pos);

// Posiciona todos os navios do jogador
int navios(Jogador *jogador, int tab[10][10]);

// Verifica se perdeu (nenhum navio restante)
int perdeu(Jogador *jogador);

#endif
