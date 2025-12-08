#ifndef JOGO_H
#define JOGO_H

#include "estruturas.h"

// Inicializa o jogo, posiciona navios e controla turnos
void iniciarJogo();

// Executa um turno (um jogador atira)
void turno(Jogador *atacante, Jogador *defensor, int tabDef[10][10]);

// Verifica se um jogador venceu
int jogoTerminado(Jogador *j1, Jogador *j2);

#endif
