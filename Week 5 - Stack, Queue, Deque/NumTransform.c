#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct
{
    int a, b;
    int step;
    char ops[MAX];
} State;

// Kiểm tra trạng thái đã tồn tại hay chưa
int visited[31][31] = {0};

// Thêm trạng thái mới vào hàng đợi
void enqueue(State *queue, int *rear, State newState)
{
    queue[*rear] = newState;
    (*rear)++;
}

// Lấy trạng thái đầu tiên trong hàng đợi
State dequeue(State *queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

// Kiểm tra trạng thái có hợp lệ hay không
int isValid(int a, int b)
{
    return a >= 0 && a <= 30 && b >= 0 && b <= 30;
}

void BFS(int c, int d, int x, int y)
{
    State queue[MAX];
    int front = 0, rear = 0;

    State start;
    start.a = c;
    start.b = d;
    start.step = 0;
    sprintf(start.ops, "(%d %d)", c, d); // Thêm trạng thái ban đầu vào lịch sử thao tác
    enqueue(queue, &rear, start);
    visited[c][d] = 1;

    while (front < rear)
    {
        State current = dequeue(queue, &front);

        if (current.a == x && current.b == y)
        {
            printf("%d %s\n", current.step, current.ops);
            return;
        }

        State newState;
        if (current.a >= current.b)
        { // Thao tác I
            newState = (State){current.a - current.b, current.b, current.step + 1, ""};
            sprintf(newState.ops, "%s (%d %d)", current.ops, newState.a, newState.b);
            if (!visited[newState.a][newState.b])
            {
                enqueue(queue, &rear, newState);
                visited[newState.a][newState.b] = 1;
            }
        }

        newState = (State){current.a + current.b, current.b, current.step + 1, ""};
        sprintf(newState.ops, "%s (%d %d)", current.ops, newState.a, newState.b);
        if (isValid(newState.a, newState.b) && !visited[newState.a][newState.b])
        {
            enqueue(queue, &rear, newState);
            visited[newState.a][newState.b] = 1;
        }

        newState = (State){current.b, current.a, current.step + 1, ""};
        sprintf(newState.ops, "%s (%d %d)", current.ops, newState.a, newState.b);
        if (!visited[newState.a][newState.b])
        {
            enqueue(queue, &rear, newState);
            visited[newState.a][newState.b] = 1;
        }
    }

    printf("-1\n");
}

int main()
{
    int c, d, x, y;
    scanf("%d %d %d %d", &c, &d, &x, &y);
    BFS(c, d, x, y);
    return 0;
}
