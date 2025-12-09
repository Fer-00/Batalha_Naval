#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

void inicializaTabuleiro(int tab[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			tab[i][j] = 0;
}

void mostraTabuleiro(int tab[10][10])
{
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int checarTiro(int tab[10][10],int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (tab[i][j] > 0 && i == x && j == y)
				return 1;
	return 0;
}

int posicaoPossivel(int tab[10][10],Posicao posI,int dx, int dy, int tam)
{	
	int x = posI.linha;
	int y = posI.coluna;

	if (x >= 10 || y >= 10 || x < 0 || y < 0)
		return 0;

    for (int k = 0; k < tam; k++)
    {
        x = posI.linha + k * dx;
        y = posI.coluna + k * dy;

        if (x < 0 || x >= 10 || y < 0 || y >= 10)
            return 0;

        if (tab[x][y] != 0)
            return 0;
    }

    return 1;
}

int posicionarNavio(int tab[10][10],Posicao posI, Posicao posF, int tam, int player)
{
	int dist = abs(posF.linha - posI.linha) + abs(posF.coluna - posI.coluna) + 1;

	if (dist != tam) {
    	printf("Tamanho informado não bate com a distância!\n");
    	return 0;
	}

	int dx  = posF.linha - posI.linha; //Se for positivo, tá indo para a diretia, se não, esquerda.
	int dy = posF.coluna - posI.coluna; //Se for positivo, rá indo para cima, se não, baixo.

	// Normaliza direção em -1(sentido negativo), 0(eixo travado) ou 1(sentido positito)
	if (dx != 0) dx = (dx > 0 ? 1 : -1);
	if (dy != 0) dy = (dy > 0 ? 1 : -1);

	if (posicaoPossivel(tab,posI,dx,dy,tam))
	{
		for (int k = 0; k < tam; k++)
		{
			int x = posI.linha + k * dx;
			int y = posI.coluna + k * dy;
			tab[x][y] = player;
		}
			return 1;
	}
	else
		return 0;
}

int checarNavio(Navio *navio)
{
	navio->acertos += 1;
	if (navio->acertos == navio->tam)
		return 1;
	return 0;
}

int tiro(int tab[10][10], Posicao t, int player)
{
	if (tab[t.linha][t.coluna] == 0)
		return 3;
	else if (tab[t.linha][t.coluna] < 0)
		return 5;
	else if (tab[t.linha][t.coluna] > 0 && tab[t.linha][t.coluna] != player)
		return tab[t.linha][t.coluna];
	else if (tab[t.linha][t.coluna] > 0 && tab[t.linha][t.coluna] == player)
		return 4;
	else
		return 0;
}