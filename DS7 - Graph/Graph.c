#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Tìm hiểu về CTDL đồ thị và các thao tác cơ bản trên đồ thị vô hướng.
 | - Đồ thị là tập hợp các đỉnh và các cạnh nối giữa các đỉnh đó.
 | - Đồ thị vô hướng là đồ thị mà các cạnh không có hướng, đồ thị có hướng là đồ thị mà các cạnh có hướng.
 | - Có thể biểu diễn đồ thị bằng: ma trận kề, danh sách kề, danh sách cạnh...
 */

/* Biểu diễn đồ thị vô hướng bằng danh sách kề:
 | - Mỗi phần tử trong mảng danh sách kề là một danh sách liên kết chứa các đỉnh kề với đỉnh tương ứng.
 | - Giả sử đồ thị có n đỉnh, ta cần một mảng chứa n danh sách liên kết, gọi là A.
 | - Phần tử A[i] chứa các đỉnh kề với đỉnh i.
 | - Để thêm cạnh giữa hai đỉnh u và v, ta thêm v vào danh sách kề của u và u vào danh sách kề của v.
 */

#define MAX_VERTICES 100

// Định nghĩa cấu trúc Node
typedef struct Node
{
    int data;          // Dữ liệu của Node
    struct Node *next; // Con trỏ trỏ đến Node kế tiếp
} Node;

// Định nghĩa cấu trúc Graph
typedef struct Graph
{
    int numVertices;              // Số đỉnh của đồ thị
    Node *adjLists[MAX_VERTICES]; // Mảng chứa các danh sách kề
} Graph;

// Hàm tạo một Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm khởi tạo đồ thị
Graph *initGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Hàm thêm cạnh vào đồ thị
void addEdge(Graph *graph, int u, int v)
{
    // Thêm cạnh từ u đến v
    Node *newNode = createNode(v);
    // Thêm v vào đầu danh sách kề của u
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    // Thêm cạnh từ v đến u
    newNode = createNode(u);
    // Thêm u vào đầu danh sách kề của v
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

// Hàm in đồ thị
void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d: ", i);
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Hàm đếm số lượng cạnh của đồ thị
int countEdges(Graph *graph)
{
    int count = 0;
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
    }
    return count / 2;
}

/* THUẬT TOÁN DUYỆT ĐỒ THỊ THEO CHIỀU SÂU (DFS):
 | - Sử dụng Stack để lưu trữ các đỉnh cần duyệt.
 | - Sử dụng mảng visited[] để đánh dấu các đỉnh đã duyệt.
 */

// Khai báo một Stack
Node *stack = NULL;

// Hàm duyệt đồ thị theo chiều sâu
void DFS(Graph *graph, int startVertex)
{
    // Mảng visited[] để đánh dấu các đỉnh đã duyệt
    int visited[MAX_VERTICES] = {0};

    // Đưa đỉnh bắt đầu vào Stack
    Node *newNode = createNode(startVertex);
    newNode->next = stack;
    stack = newNode;

    while (stack != NULL)
    {
        // Lấy đỉnh đầu tiên ra khỏi Stack
        int vertex = stack->data;
        stack = stack->next;

        // Nếu đỉnh chưa được duyệt thì in ra và đánh dấu đã duyệt
        if (visited[vertex] == 0)
        {
            printf("%d ", vertex);
            visited[vertex] = 1;
        }

        // Duyệt qua tất cả các đỉnh kề với đỉnh hiện tại
        Node *temp = graph->adjLists[vertex];
        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                // Đưa đỉnh kề vào Stack
                newNode = createNode(temp->data);
                newNode->next = stack;
                stack = newNode;
            }
            temp = temp->next;
        }
    }
}

/* THUẬT TOÁN DUYỆT ĐỒ THỊ THEO CHIỀU RỘNG (BFS):
 | - Sử dụng Queue để lưu trữ các đỉnh cần duyệt.
 | - Sử dụng mảng visited[] để đánh dấu các đỉnh đã duyệt.
 */

// Cấu trúc Queue
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Hàm tạo một Queue mới
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Hàm duyệt đồ thị theo chiều rộng
void BFS(Graph *graph, int startVertex)
{
    // Mảng visited[] để đánh dấu các đỉnh đã duyệt
    int visited[MAX_VERTICES] = {0};

    // Tạo một Queue mới
    Queue *queue = createQueue();

    // Đưa đỉnh bắt đầu vào Queue
    Node *newNode = createNode(startVertex);
    queue->front = queue->rear = newNode;

    while (queue->front != NULL)
    {
        // Lấy đỉnh đầu tiên ra khỏi Queue
        int vertex = queue->front->data;
        queue->front = queue->front->next;

        // Nếu đỉnh chưa được duyệt thì in ra và đánh dấu đã duyệt
        if (visited[vertex] == 0)
        {
            printf("%d ", vertex);
            visited[vertex] = 1;
        }

        // Duyệt qua tất cả các đỉnh kề với đỉnh hiện tại
        Node *temp = graph->adjLists[vertex];
        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                // Đưa đỉnh kề vào Queue
                newNode = createNode(temp->data);
                if (queue->front == NULL)
                    queue->front = queue->rear = newNode;
                else
                {
                    queue->rear->next = newNode;
                    queue->rear = newNode;
                }
            }
            temp = temp->next;
        }
    }
}

int main()
{
    Graph *graph = initGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);

    // ĐỒ THỊ:
    //        2
    //       / \
    //  0 - 1 - 3
    //       \ /
    //        4

    printGraph(graph);

    printf("Number of edges: %d\n", countEdges(graph));

    printf("DFS: ");
    DFS(graph, 0);

    printf("\nBFS: ");
    BFS(graph, 0);

    return 0;
}
