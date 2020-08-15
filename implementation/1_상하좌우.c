#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int ft_strlen(char *str)
{
	return (sizeof(str) / sizeof(char));
}

char *ft_append(char *arr, char c)
{
	char *result;
	int i = 0;

	result = (char *)malloc(sizeof(char) * (ft_strlen(arr) + 1));
	while (arr[i])
	{
		result[i] = arr[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	free(arr);
	return result;
}

void ft_getline(char **arr, char sep)
{
	int i = 0;
	char buf;
	*arr = (char *)malloc(sizeof(char) * 1);
	**arr = '\0';
	while (0 < read(1, &buf, 1))
	{
		if (buf == sep)
			continue;
		if (buf == '\n')
			break;
		*arr = ft_append(*arr, buf);
	}
}

int main(void)
{
	int n;
	char *arr;
	int x = 1, y = 1;
	scanf("%d", &n);
	ft_getline(&arr, ' ');

	for (int i = 0; i < ft_strlen(arr); i++)
	{
		switch (arr[i])
		{
		case 'L':
			if (x > 1)
				x--;
			break;
		case 'R':
			if (x < n)
				x++;
			break;
		case 'D':
			if (y < n)
				y++;
			break;
		case 'U':
			if (y > 1)
				y--;
			break;
		default:
			break;
		}
	}
	printf("%d %d", y, x);
}
