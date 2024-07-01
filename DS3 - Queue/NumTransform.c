#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Đề bài: Cho 4 số nguyên dương a, b, x, y. Bạn có thể thực hiện các thao tác sau:
 | - Thao tác I: (a, b) -> (a - b, b) nếu a >= b
 | - Thao tác II: (a, b) -> (a + b, b)
 | - Thao tác III: (a, b) -> (b, a)
 | Hãy tìm cách biến đổi số cặp số (a, b) thành số cặp số (x, y) bằng cách thực hiện các thao tác trên sao cho số lần biến đổi là ít nhất.
 */

/* THUẬT TOÁN: -> TÌM KIẾM THEO CHIỀU RỘNG (BFS) ĐỂ DUYỆT TRẠNG THÁI
 | - Sử dụng hàng đợi để lưu trạng thái (a, b) cần xét.
 | - Mỗi lần lấy một trạng thái ra khỏi hàng đợi,
 |   thực hiện các thao tác I, II, III để tạo ra các trạng thái mới và thêm vào hàng đợi, đồng thời đánh dấu đã xét.
 | - Nếu trạng thái mới là trạng thái cần tìm thì trả về số bước biến đổi.
 | - Nếu không tìm thấy thì trả về -1.
 | - Để chỉ ra dãy thao tác biến đổi, ta duy trì một mảng trạng thái trước của mỗi trạng thái hiện tại.
 |  Khi tìm được trạng thái cần tìm, ta lần ngược từ trạng thái cần tìm về trạng thái ban đầu để lấy dãy thao tác.
 | - Độ phức tạp: O(MAX^2) với MAX là giới hạn của cặp số được biến đổi.
 */

#define MAX 100 // Giới hạn của cặp số được biến đổi

// Một node trong hàng đợi chứa cặp số (a, b) + số bước biến đổi từ cặp số ban đầu
typedef struct Node
{
    int a, b, steps; // steps: số bước biến đổi
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
Node *createNode(int a, int b, int steps)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->a = a;
    newNode->b = b;
    newNode->steps = steps;
    newNode->next = NULL;
    return newNode;
}

// Thêm một node vào cuối hàng đợi
void enqueue(Queue *q, int a, int b, int steps)
{
    Node *newNode = createNode(a, b, steps);

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

        if (q->front == NULL)
        {
            q->rear = NULL;
        }

        return temp;
    }
}

// Kiểm tra xem cặp số (a, b) có nằm trong phạm vi cho phép không
int isValid(int a, int b)
{
    return a >= 1 && b >= 1 && a <= MAX && b <= MAX;
}

// Hàm tìm số bước biến đổi ít nhất từ cặp số (a, b) thành cặp số (x, y)
int minSteps(int a, int b, int x, int y)
{
    // Mảng đánh dấu trạng thái đã xét
    int visited[MAX + 1][MAX + 1];
    memset(visited, 0, sizeof(visited));

    // Mảng trạng thái trước của mỗi trạng thái
    Node *prev[MAX + 1][MAX + 1];
    memset(prev, 0, sizeof(prev));

    // Khởi tạo hàng đợi
    Queue *q = initQueue();

    // Thêm trạng thái ban đầu vào hàng đợi
    enqueue(q, a, b, 0);

    // Duyệt trạng thái
    while (q->front != NULL)
    {
        Node *cur = dequeue(q);
        int a = cur->a, b = cur->b, steps = cur->steps;

        // Nếu trạng thái hiện tại là trạng thái cần tìm
        if (a == x && b == y)
        {
            // In dãy biến đổi từ trạng thái ban đầu đến trạng thái cần tìm
            // Dùng 1 mảng để lưu dãy thao tác ngược từ trạng thái cần tìm về trạng thái ban đầu
            Node *path[steps + 1]; // Mảng các Node lưu trạng thái
            Node *temp = cur;
            for (int i = steps; i >= 0; i--)
            {
                path[i] = temp;
                temp = prev[temp->a][temp->b];
            }

            printf("Path: ");
            for (int i = 0; i < steps; i++)
            {
                printf("(%d, %d) -> ", path[i]->a, path[i]->b);
            }
            printf("(%d, %d)\n", x, y);

            return steps;
        }

        // Thực hiện các thao tác I, II, III
        if (isValid(a - b, b) && !visited[a - b][b])
        {
            enqueue(q, a - b, b, steps + 1);
            visited[a - b][b] = 1;
            prev[a - b][b] = cur;
        }

        if (isValid(a + b, b) && !visited[a + b][b])
        {
            enqueue(q, a + b, b, steps + 1);
            visited[a + b][b] = 1;
            prev[a + b][b] = cur;
        }

        if (isValid(b, a) && !visited[b][a])
        {
            enqueue(q, b, a, steps + 1);
            visited[b][a] = 1;
            prev[b][a] = cur;
        }
    }

    return -1;
}

int main()
{
    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);

    int steps = minSteps(a, b, x, y);
    printf("Minimum steps: %d\n", steps);

    return 0;
}
