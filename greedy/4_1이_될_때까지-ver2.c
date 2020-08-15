#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k, cnt = 0;
	;
	scanf("%d %d", &n, &k);
	while (1)
	{
		cnt += n - ((n / k) * k);
		n /= k;
		if (n < k)
			break;
		cnt++;
	}
	printf("%d", cnt + n);
	return (0);
}
