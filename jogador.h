#ifndef JOGADOR_H
#define JOGADOR_H

#include "estruturas.h"

// Lê o nome do jogador e armazena no struct
void getNome(Jogador *j);

// Pede uma jogada (linha, coluna)
Posicao pegaJogada();

// Posiciona todos os navios do jogador
int navios(Jogador *j, int tab[10][10]);

// Verifica se perdeu (nenhum navio restante)
int perdeu(Jogador *j);

#endif
