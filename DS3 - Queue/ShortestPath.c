#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Tìm đường đi ngắn nhất giữa 2 ô vuông trong mê cung kích thước RxC.
 | - Mê cung được biểu diễn bằng ma trận RxC, trong đó: 0 là ô trống, 1 là ô cấm.
 | - Bắt đầu từ ô (x1, y1) và kết thúc ở ô (x2, y2).
 | - Có thể di chuyển sang 4 hướng: trên, dưới, trái, phải.
 | - Đầu ra: Độ dài đường đi ngắn nhất từ (x1, y1) đến (x2, y2).
 */

/* THUẬT TOÁN: DUYỆT THEO CHIỀU RỘNG (BFS)
 | - Sử dụng hàng đợi để lưu các ô cần xét.
 | - Mỗi lần lấy một ô ra khỏi hàng đợi, xét 4 ô xung quanh nó, nếu là ô trống thì thêm vào hàng đợi và đánh dấu đã xét.
 | - Khi gặp ô (x2, y2), trả về độ dài đường đi.
 | - Nếu không tìm thấy đường đi, trả về -1.
 */

// Các biến toàn cục
int R, C, sr, sc, er, ec;
int **maze;
int **visited;

// Một node trong hàng đợi chứa tọa độ x, y (x là hàng, y là cột).
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

    // Nếu hàng đợi rỗng, gán cả front và rear trỏ đến Node mới
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

// Lấy một node ở đầu hàng đợi (và xóa nó)
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
        return temp;
    }
}

// Hàm kiểm tra xem ô (x, y) có nằm trong mê cung hay không
int isValid(int x, int y)
{
    return (x >= 0 && x < R && y >= 0 && y < C);
}

// Hàm tìm đường đi ngắn nhất từ (sr, sc) đến (er, ec)
int shortestPath()
{
    // Khởi tạo hàng đợi và đánh dấu các ô đã xét
    Queue *q = initQueue();
    visited = (int **)malloc(R * sizeof(int *));
    for (int i = 0; i < R; i++)
    {
        visited[i] = (int *)malloc(C * sizeof(int));
        for (int j = 0; j < C; j++)
            visited[i][j] = 0;
    }

    // Thêm ô ban đầu vào hàng đợi và đánh dấu đã xét
    enqueue(q, sr, sc, 0);
    visited[sr][sc] = 1;

    // Duyệt theo chiều rộng
    while (q->front != NULL)
    {
        Node *node = dequeue(q);
        int x = node->x, y = node->y, dist = node->dist;

        // Nếu gặp ô đích, trả về độ dài đường đi
        if (x == er && y == ec)
            return dist;

        // Duyệt 4 ô xung quanh ô hiện tại
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Nếu ô mới là ô hợp lệ và chưa xét, thêm vào hàng đợi và đánh dấu đã xét
            if (isValid(nx, ny) && maze[nx][ny] == 0 && !visited[nx][ny])
            {
                enqueue(q, nx, ny, dist + 1);
                visited[nx][ny] = 1;
            }
        }
    }

    // Không tìm thấy đường đi
    return -1;
}

int main()
{
    // Nhập kích thước mê cung và mê cung
    printf("Maze size: ");
    scanf("%d%d", &R, &C);

    maze = (int **)malloc(R * sizeof(int *));
    for (int i = 0; i < R; i++)
    {
        maze[i] = (int *)malloc(C * sizeof(int));
        for (int j = 0; j < C; j++)
            scanf("%d", &maze[i][j]);
    }

    // Nhập điểm đầu và điểm cuối
    printf("Start point: ");
    scanf("%d%d", &sr, &sc);

    printf("End point: ");
    scanf("%d%d", &er, &ec);

    // Tìm đường đi ngắn nhất
    int dist = shortestPath();
    printf("%d\n", dist);

    return 0;
}