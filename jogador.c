#include <stdio.h>

void nome(Jogador jogador)
{
	char[50] nome;
	fgets(none, 50, stdin);
	nome[strlen(nome)] = '\0';
	strcpy(jogador.nome,nome);
}

int jogada(Jogador jogador, Posicao pos)
{
	//passar posição e player;
	//várias funções no tabuleiro,checar necessidade de todas

	jogador.jogadas++;

}

Posicao pegaJogada();
	Posicao tiro;
	int x, y = 0;
	printf("Linha de tiro:\n");
	scanf("%d",&x);
	printf("Coluna de tiro:\n");
	scanf("%d",&y);
	tiro = {x,y};
	return tiro;

int navios(Navio navio, Jogador jogador)
{
	int x, y = 0;
	Posicao posI,posF = {0,0};
	printf("Você tem um navio de tamanho 4, dois de tamanho 3 e três de tamanho 2");
	for (int i = 0; i < 6; i++)
	{
		printf("X inicial:\n");
		scanf("%d",&x);
		printf("Y inicial:\n");
		scanf("%d",&y);
		posI = {x,y};
		printf("X final:\n");
		scanf("%d",&x);
		printf("Y final:\n");
		scanf("%d",&y);
		posF = {x,y};
		//posicionarNavio tabuleiro.c
	}
}

int perdeu(Jogador jogador)
{
	if (jogador.naviosEmJogo == 0)
		return 1;
	return 0;
}