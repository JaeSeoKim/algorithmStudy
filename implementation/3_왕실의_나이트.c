#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int cnt = 0;
	char pt[2];
	int steps[8][2] = {
		{1, 2},
		{-1, 2},
		{2, 1},
		{2, -1},
		{1, -2},
		{-1, -2},
		{-2, 1},
		{-2, -1},
	};

	scanf("%s", pt);
	for (int i = 0; i < 8; i ++)
	{
		int x = (pt[0] - 'a') + steps[i][0];
		int y = (pt[1] - '1') + steps[i][1];
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
			cnt++;
	}
	printf("%d", cnt);
}
