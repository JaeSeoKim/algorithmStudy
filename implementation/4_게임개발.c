#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int n, m, x, y, cp, turn = 0, cnt = 1;
	int cardinalPoint[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int **map;
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &cp);

	map = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		int *tmp = (int *)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &tmp[j]);
		}
		map[i] = tmp;
	}
	map[x][y] = 2;
	while (1)
	{
		cp--;
		if (cp < 0)
			cp = 3;
		int tx = x + cardinalPoint[cp][0];
		int ty = y + cardinalPoint[cp][1];
		if (map[tx][ty] == 0)
		{
			x = tx;
			y = ty;
			turn = 0;
			map[x][y] = 2;
			cnt++;
		}
		else
			turn++;
		if (turn == 4)
		{
			tx = x - cardinalPoint[cp][0];
			ty = y - cardinalPoint[cp][1];
			printf("%d %d %d\n", ty, tx, cp);
			if (map[ty][tx] != 1)
			{
				x = tx;
				y = ty;
			}
			else
				break;
			turn = 0;
		}
	}
	printf("%d", cnt);
}
