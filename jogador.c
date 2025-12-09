#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "tabuleiro.h"

void getNome(Jogador *jogador)
{
	printf("Nome do jogador:\n");
	fgets(jogador->nome, 50, stdin);
    jogador->nome[strcspn(jogador->nome, "\n")] = 0; // remove \n
}

int jogada(int tab[10][10], Jogador *jogador, Posicao pos) 
{

    int x = pos.linha;
    int y = pos.coluna;

    jogador->jogadas++;

    int aux = tiro(tab,pos,jogador->id);

    // tiro na água
    if (aux == 3) {
        tab[x][y] = -1;
        return 3;
    }

    // já acertado antes
    else if (aux == 5)
        return 5;

    // acertou navio
    else if (aux != jogador->id)
    {
    	tab[x][y] = -2;
	    return aux;
    }
    // acertou seu próprio navio
	else if (aux == jogador->id)
		return 4;
	else
		return 12;
}

Posicao pegaJogada()
{
	Posicao tiro;
	printf("Linha de tiro:\n");
	scanf("%d",&tiro.linha);
	printf("Coluna de tiro:\n");
	scanf("%d",&tiro.coluna);
	return tiro;
}

int navios(Jogador *jogador, int tab[10][10])
{
	int tamanhos[6] = {4,3,3,2,2,2};
	Posicao posI,posF;
	printf("Você tem um navio de tamanho 4, dois de tamanho 3 e três de tamanho 2. \n");
	for (int i = 0; i < 6; i++)
	{
		printf("Coloque o navio de tamanho %d:\n",tamanhos[i]);
		printf("X inicial:\n");
		scanf("%d",&posI.linha);
		printf("Y inicial:\n");
		scanf("%d",&posI.coluna);
		printf("X final:\n");
		scanf("%d",&posF.linha);
		printf("Y final:\n");
		scanf("%d",&posF.coluna);

		if (!posicionarNavio(tab,posI,posF,tamanhos[i],jogador->id))
		{
			printf("Posição inválida, tente novamente:\n");
			i--;
		}

		jogador->navios[i].id = i;
		jogador->navios[i].tam = tamanhos[i];
		jogador->navios[i].player = jogador->id;
		jogador->navios[i].posI = posI;
		jogador->navios[i].posF = posF;
		jogador->navios[i].acertos = 0;
	}
	jogador->naviosEmJogo = 6;
	return 1;
}

int perdeu(Jogador *jogador)
{
	if (jogador->naviosEmJogo == 0)
		return 1;
	return 0;
}