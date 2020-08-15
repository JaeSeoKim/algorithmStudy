#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int num[4] = {500, 100, 50, 10};
		int n = atoi(argv[1]);
		int i = 0;
		int count = 0;

		while (i < 4)
		{
			count += n / num[i];
			n = n % num[i];
			i++;
		}
		printf("%d",count);
	}
	return (0);
}
