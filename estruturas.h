#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct {
    int linha;
    int coluna;
} Posicao;

typedef struct {
    int id;
    int tam;
    int player;
    Posicao posI; //posição incial do navio
    Posicao posF; //posição final do navio, por ela se sabe a orientação do mesmo;
    int acertos;
} Navio;

typedef struct {
    char nome[50];
    int id;
    Navio navios[6];
    int naviosEmJogo;
    int jogadas;
} Jogador;

#endif
