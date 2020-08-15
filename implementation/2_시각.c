#include <stdlib.h>
#include <stdio.h>

int includeThree(int n)
{
	if (n % 10 == 3 || n / 10 == 3)
		return 1;
	return 0;
}

int main(void)
{
	int n, cnt = 0;
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				if (includeThree(i) || includeThree(j) || includeThree(k))
					cnt++;
			}
		}
	}
	printf("%d", cnt);

	return (0);
}
