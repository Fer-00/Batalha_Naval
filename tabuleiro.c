#include <stdio.h>

void inicializaTabuleiro(int tab[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			tab[i][j] = 0;
}

int checarTiro(int tab[10][10],int x, int y)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (tab[i][j] != 0 && tab[10][10] > 0 && i == x && j == y);
				return 1;
	return 0;
}

int posicionarNavio(int tab[10][10],int posI, char posF, int tam, int player)
{
	int x = posF[0] - posI[0]; //Se for positivo, tá indo para a diretia, se não, esquerda.
	int y = posF[1] - posI[1]; //Se for positivo, rá indo para cima, se não, baixo.
	if (posicaoPossivel(tab,posI,x,y,tam))
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == posI[0] && j == posI[1])
				{
					for (int k = 0; k < tam; k++)
					{
						if (x > 0 && y == 0)
							tab[i+k][j] = player;
						else if (x < 0 && y == 0)
							tab[i-k][j] = player;
						else if (x == 0 && y > 0)
							tab[i][j+k] = player;
						else if (x == 0 && y < 0)
							tab[i][j-K] = player;
						else
							continue;
					}
					return 1;
				}
			}
		}
	}
	else
		return 0;
}

int posicaoPossivel(int tab[10][10],int posI,int x, int y, int tam)
{
	if (posI[0] + x >= 10 or posI[1] + y >= 10 or posI[0] - x < 0 or posI[1] - y < 0)
		return 0;
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			for (int k = 0; k < tam; k++)
			{
				if (x > 0 && y == 0)
					if (tab[i+k][j] != 0)
						return 0;
				else if (x < 0 && y == 0)
					if (tab[i-k][j] != 0)
						return 0;
				else if (x == 0 && y > 0)
					if (tab[i][j+k] != 0)
						return 0;
				else if (x == 0 && y < 0)
					if (tab[i][j-k] != 0)
						return 0;
				else
					continue;
			}
		}
	}
	return 1;
}

int checarNavio(Navio navio)
{
	navio.acertos += 1;
	if (acertos == tam)
		return 1;
	return 0;
}

int tiro(int tab[10][10], int x, int y, int player)
{
	if (tab[x][y] != 0)
		return 2;
	else if (tab[x][y] > 0 && tab[x][y] != player)
	{
		tab[x][y] = 0;
		return 1;
	}
	else if (tab[x][y] > 0 && tab[x][y] == player)
		return 3;
	else
		return 0;
}