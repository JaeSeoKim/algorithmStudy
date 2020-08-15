#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int n, m, k, top = 0, second = 0, result = 0;
	scanf("%d %d %d", &n, &m, &k);
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++){
		int tmp;
		scanf("%d", &tmp);
		arr[i] = tmp;
	}

	for (int i = 0; i < n; i++){
		if (arr[i] > top)
			top = arr[i];
	}
	for (int i = 0; i < n; i++){
		if (arr[i] < top && arr[i] > second)
			second = arr[i];
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (i % (k+1) == 0)
			result += second;
		else
			result += top;
	}
	printf("%d", result);
	return (0);
}
