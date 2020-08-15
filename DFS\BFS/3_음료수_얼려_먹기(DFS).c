#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g_n, g_m;

char *fr_getline()
{
	char *buf = (char *)malloc(sizeof(char) * g_m);
	scanf("%s", buf);
	return buf;
}

int dfs(char ***map, int x, int y)
{
	if (x >= g_n || y >= g_m || x < 0 || y < 0)
		return 0;
	if ((*map)[x][y] == '0')
	{
		(*map)[x][y] = '1';
		dfs(map, x, y + 1);
		dfs(map, x, y - 1);
		dfs(map, x + 1, y);
		dfs(map, x - 1, y);
		return 1;
	}
	return 0;
}

int main(void)
{
	int cnt = 0;
	char **map;
	scanf("%d %d", &g_n, &g_m);
	map = (char **)malloc(sizeof(char *) * g_n);
	for (int i = 0; i < g_n; i++)
	{
		char *tmp = fr_getline();
		map[i] = tmp;
	}
	for (int i = 0; i < g_n; i++)
	{
		for (int j = 0; j < g_m; j++)
		{
			if (dfs(&map, i, j))
				cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
