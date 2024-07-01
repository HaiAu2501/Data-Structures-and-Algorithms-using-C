#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Tìm đường đi ngắn nhất từ một điểm đến biên của một mê cung.
 | - Đầu vào: Mê cung kích thước R x C, vị trí ban đầu r, c.
 | - Mê cung: 0 là đường đi được đi qua, 1 là tường, có thể đi lên, xuống, trái, phải.
 | - Đầu ra: Độ dài đường đi ngắn nhất từ điểm ban đầu đến biên của mê cung, -1 nếu không tìm thấy.
 | - Ví dụ:
 | + Input:
 |   5 5 2 2
 |   0 1 0 0 0
 |   0 1 0 1 0
 |   0 0 0 1 0
 |   1 1 1 1 0
 |   0 0 0 0 0
 | + Output: 2 với đường đi (2, 2) -> (2, 1) -> (2, 0) hoặc (2, 2) -> (1, 2) -> (0, 2).
 */

/* THUẬT TOÁN:
 | - Sử dụng BFS để tìm đường đi ngắn nhất từ một điểm đến biên của mê cung.
 | - Sử dụng hàng đợi để lưu các ô cần xét.
 | - Mỗi lần lấy một ô ra khỏi hàng đợi, xét 4 ô xung quanh nó, nếu là ô trống thì thêm vào hàng đợi và đánh dấu đã xét.
 | - Khi gặp biên của mê cung, trả về độ dài đường đi.
 | - Nếu không tìm thấy đường đi, trả về -1.
 */

// Các biến toàn cục
int R, C, sr, sc;
int **maze;
int **visited;

/* Một node trong hàng đợi chứa tọa độ x, y (x là hàng, y là cột).
 | - Trong trường hợp này, ta triển khai hàng đợi bằng danh sách liên kết đơn với 2 con trỏ front và rear.
 | + front: trỏ đến node đầu tiên trong hàng đợi.
 | + rear: trỏ đến node cuối cùng trong hàng đợi.
 | - Thao tác enqueue: O(1)
 | - Thao tác dequeue: O(1)
 | - Các triển khai này đơn giản hơn so với danh sách liên kết đôi và không ảnh hưởng đến thuật toán BFS.
 */
typedef struct Node
{
    int x, y, dist; // dist: độ dài đường đi từ điểm ban đầu
    struct Node *next;
} Node;

// Hàng đợi
typedef struct Queue
{
    Node *front, *rear;
} Queue;

// Khởi tạo hàng đợi
Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Tạo một node mới
Node *createNode(int x, int y, int dist)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->dist = dist;
    newNode->next = NULL;
    return newNode;
}

// Thêm một node vào cuối hàng đợi
void enqueue(Queue *q, int x, int y, int dist)
{
    Node *newNode = createNode(x, y, dist);

    if (q->front == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Lấy node ở đầu hàng đợi và xóa nó
Node *dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        return temp;
    }
}

// Kiểm tra xem một ô có nằm trong mê cung không
int isValid(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

// Tìm đường đi ngắn nhất từ một điểm đến biên của mê cung
int shortestPath(int **maze, int sr, int sc)
{
    // Khởi tạo mảng visited
    visited = (int **)malloc(R * sizeof(int *));
    for (int i = 0; i < R; i++)
    {
        visited[i] = (int *)malloc(C * sizeof(int));
        for (int j = 0; j < C; j++)
        {
            visited[i][j] = 0;
        }
    }

    // Khởi tạo hàng đợi
    Queue *q = initQueue();
    enqueue(q, sr, sc, 0);
    visited[sr][sc] = 1;

    // Dịch chuyển 4 hướng: trên, dưới, trái, phải
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (q->front != NULL)
    {
        Node *node = dequeue(q);
        int x = node->x;
        int y = node->y;
        int dist = node->dist;

        // Nếu gặp biên của mê cung, trả về độ dài đường đi
        if (x == 0 || x == R - 1 || y == 0 || y == C - 1)
        {
            return dist;
        }

        // Dịch chuyển 4 hướng
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Nếu ô mới là ô hợp lệ và chưa xét
            if (isValid(newX, newY) && maze[newX][newY] == 0 && !visited[newX][newY])
            {
                enqueue(q, newX, newY, dist + 1);
                visited[newX][newY] = 1;
            }
        }
    }

    // Không tìm thấy đường đi
    return -1;
}

int main()
{
    // Nhập kích thước mê cung và vị trí ban đầu
    scanf("%d%d%d%d", &R, &C, &sr, &sc);

    // Cấp phát bộ nhớ cho mê cung
    maze = (int **)malloc(R * sizeof(int *));
    for (int i = 0; i < R; i++)
    {
        maze[i] = (int *)malloc(C * sizeof(int));
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }

    // Tìm đường đi ngắn nhất
    int result = shortestPath(maze, sr, sc);
    printf("%d\n", result);

    return 0;
}
