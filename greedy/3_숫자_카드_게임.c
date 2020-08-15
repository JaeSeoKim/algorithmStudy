#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int n, m, result = 0;
	scanf("%d %d", &n, &m);
	int **arr = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++){
		int *tmp = (int *)malloc(sizeof(int) *m);
		for (int j = 0; j < m; j ++)
		{
			scanf("%d", &tmp[j]);
		}
		arr[i] = tmp;
	}
	for (int i = 0; i < n; i++){
		int tmp = 10000;
		for (int j = 0; j < m; j++)
			if (arr[i][j] < tmp)
				tmp = arr[i][j];
		if (result < tmp)
			result = tmp;
	}
	printf("%d", result);
	return (0);
}
