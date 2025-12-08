#include <stdio.h>
#include <string.h>
#include "estruturas.h"
#include "tabuleiro.h"

void nome(Jogador *jogador)
{
	printf("Nome do jogador:\n");
	fgets(j.nome, 50, stdin);
	j.nome[strlen(j.nome)] = '\0';
}

int jogada(Jogador *jogador, Posicao pos)
{
	//passar posição e player;
	//várias funções no tabuleiro,checar necessidade de todas

	jogador->jogadas++;

}

Posicao pegaJogada();
	Posicao tiro;
	printf("Linha de tiro:\n");
	scanf("%d",&tiro.linha);
	printf("Coluna de tiro:\n");
	scanf("%d",&tiro.coluna);
	return tiro;

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

		if (!posicionarNavio(tab,posI,posF,tamanhos[i],jogador.player))
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