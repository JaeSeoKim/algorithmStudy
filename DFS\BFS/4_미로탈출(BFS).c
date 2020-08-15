#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int x;
	int y;
	struct _node *next;
} NODE;

typedef struct _queue
{
	NODE *front;
	NODE *rear;
	int cnt;
} QUEUE;

int g_n, g_m;

QUEUE queue;

void initQueue(int x, int y)
{
	NODE *front = (NODE *)malloc(sizeof(NODE));
	front->x = x;
	front->y = y;
	front->next = NULL;
	queue.front = front;
	queue.rear = front;
	queue.cnt = 1;
}

int *fr_getline()
{
	int *buf = (int *)malloc(sizeof(int) * g_m);
	for (int i = 0; i < g_m; i++)
	{
		scanf("%1d", &buf[i]);
	}
	return buf;
}

void append(int x, int y)
{
	NODE *node = (NODE *)malloc(sizeof(NODE));
	node->x = x;
	node->y = y;
	node->next = NULL;
	if (queue.front == NULL)
	{
		queue.front = node;
		queue.rear = node;
	}
	else
	{
		queue.rear->next = node;
		queue.rear = node;
	}
	queue.cnt++;
}

NODE *popleft()
{
	NODE *tmp = queue.front;
	queue.front = queue.front->next;
	queue.cnt--;
	return tmp;
}

int main(void)
{
	scanf("%d %d", &g_n, &g_m);

	int **map = (int **)malloc(sizeof(int *) * g_n);
	for (int i = 0; i < g_n; i++)
		map[i] = fr_getline();
	initQueue(0, 0);
	int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	while (queue.cnt)
	{
		NODE *node = popleft();
		for (int i = 0; i < 4; i++)
		{
			int nx = node->x - mv[i][0];
			int ny = node->y - mv[i][1];
			if (nx >= 0 && ny >= 0 && nx < g_n && ny < g_m && map[nx][ny] == 1)
			{
				map[nx][ny] = map[node->x][node->y] + 1;
				append(nx, ny);
			}
		}
		free(node);
	}
	printf("%d", map[g_n - 1][g_m - 1]);
	for (int i = 0; i < g_n; i++)
		free(map[i]);
	free(map);
	return 0;
}
