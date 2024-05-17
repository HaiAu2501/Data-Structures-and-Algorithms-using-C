#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x, y, dist;
} QueueNode;

typedef struct
{
    QueueNode *nodes;
    int front, rear, size, capacity;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->nodes = (QueueNode *)malloc(capacity * sizeof(QueueNode));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    return queue;
}

void enqueue(Queue *queue, int x, int y, int dist)
{
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->nodes[queue->rear].x = x;
    queue->nodes[queue->rear].y = y;
    queue->nodes[queue->rear].dist = dist;
    queue->size++;
}

QueueNode dequeue(Queue *queue)
{
    QueueNode node = queue->nodes[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return node;
}

int isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

void freeQueue(Queue *queue)
{
    free(queue->nodes);
    free(queue);
}

int main()
{
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    int **maze = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    // BFS initialization
    Queue *queue = createQueue(n * m);
    int **visited = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        visited[i] = (int *)calloc(m, sizeof(int));
    }
    r--;
    c--; // Convert to 0-indexed
    enqueue(queue, r, c, 0);
    visited[r][c] = 1;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int found = -1;

    while (!isEmpty(queue))
    {
        QueueNode node = dequeue(queue);
        // Check if it's on the boundary
        if (node.x == 0 || node.x == n - 1 || node.y == 0 || node.y == m - 1)
        {
            found = node.dist + 1;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = node.x + directions[i][0];
            int ny = node.y + directions[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && !visited[nx][ny])
            {
                enqueue(queue, nx, ny, node.dist + 1);
                visited[nx][ny] = 1;
            }
        }
    }

    printf("%d\n", found);

    for (int i = 0; i < n; i++)
    {
        free(maze[i]);
        free(visited[i]);
    }
    free(maze);
    free(visited);
    freeQueue(queue);

    return 0;
}
