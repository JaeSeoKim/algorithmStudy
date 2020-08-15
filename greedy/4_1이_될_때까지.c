#include <stdio.h>
#include <stdlib.h>

int		main(void){
	int n, k, cnt = 0;;
	scanf("%d %d", &n, &k);
	while (n != 1)
	{
		if (n % k != 0){
			n--;
			cnt++;
		}
		else{
			n /= k;
			cnt++;
		}
	}
	printf("%d", cnt);
	return (0);
}
