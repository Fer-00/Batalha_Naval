#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "estruturas.h"

// Inicializa matriz 10x10 com zeros
void inicializaTabuleiro(int tab[10][10]);

// Verifica se é possível colocar um navio na direção informada
int posicaoPossivel(int tab[10][10], Posicao posI, int dx, int dy, int tam);

// Posiciona navio no tabuleiro se possível
int posicionarNavio(int tab[10][10], Posicao posI, Posicao posF, int tam, int player);

// Opcional: exibir tabuleiro
void mostraTabuleiro(int tab[10][10]);

#endif