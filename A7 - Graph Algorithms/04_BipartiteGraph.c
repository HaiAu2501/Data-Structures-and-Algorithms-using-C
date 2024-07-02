#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Kiểm tra một đồ thị vô hướng có phải là đồ thị hai phía hay không.
 | - Đồ thị hai phía là đồ thị có tính chất:
 | + Có thể phân hoạch tập đỉnh của đồ thị thành hai tập con không giao nhau.
 | + Các đỉnh trong cùng một tập không có cạnh nối với nhau.
 */

/* THUẬT TOÁN:
 | - Sử dụng BFS, từ một đỉnh chưa được duyệt.
 | - Gán phía của đỉnh đó là 0.
 | - Mỗi khi duyệt một đỉnh hàng xóm chưa được duyệt, gán phía của đỉnh đó là phía còn lại so với đỉnh hiện tại.
 | - Nếu gặp một đỉnh đã được duyệt mà phía của nó trùng với phía của đỉnh hiện tại, đồ thị không phải là đồ thị hai phía.
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
    int side[MAX_VERTICES];       // Mảng chứa phía của các đỉnh
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
    {
        graph->adjLists[i] = NULL;
        graph->side[i] = -1;
    }

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

// Để sử dụng BFS, ta cần một hàng đợi
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Hàm tạo một hàng đợi mới
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Hàm thêm vào cuối hàng đợi
void enqueue(Queue *q, int data)
{
    Node *newNode = createNode(data);
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Hàm lấy phần tử ở đầu hàng đợi
int dequeue(Queue *q)
{
    if (q->front == NULL)
        return -1;

    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    return data;
}

// Hàm kiểm tra đồ thị có phải là đồ thị hai phía hay không
int isBipartite(Graph *graph)
{
    // Khởi tạo hàng đợi
    Queue *q = createQueue();

    // Duyệt qua tất cả các đỉnh của đồ thị
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Nếu đỉnh chưa được duyệt
        if (graph->side[i] == -1)
        {
            // Thêm đỉnh vào hàng đợi
            enqueue(q, i);
            // Gán phía của đỉnh là 0
            graph->side[i] = 0;

            // Duyệt BFS
            while (q->front != NULL)
            {
                int u = dequeue(q);

                // Duyệt qua tất cả các đỉnh kề với đỉnh u
                Node *temp = graph->adjLists[u];
                while (temp != NULL)
                {
                    int v = temp->data;

                    // Nếu đỉnh v chưa được duyệt
                    if (graph->side[v] == -1)
                    {
                        // Gán phía của đỉnh v là phía còn lại so với đỉnh u
                        graph->side[v] = 1 - graph->side[u];
                        // Thêm đỉnh v vào hàng đợi
                        enqueue(q, v);
                    }
                    // Nếu phía của đỉnh v trùng với phía của đỉnh u
                    else if (graph->side[v] == graph->side[u])
                        return 0;

                    temp = temp->next;
                }
            }
        }
    }
    return 1;
}

int main()
{
    // ĐỒ THỊ:
    //        0   1   2   3   4   11 - 12
    //        | / |   | \ |   |    |  /
    //        5   6   7   8   9   10

    Graph *graph = initGraph(13);
    addEdge(graph, 0, 5);
    addEdge(graph, 5, 1);
    addEdge(graph, 1, 6);
    addEdge(graph, 2, 7);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 8);
    addEdge(graph, 4, 9);
    addEdge(graph, 10, 12);
    addEdge(graph, 10, 11);
    addEdge(graph, 11, 12);

    if (isBipartite(graph))
        printf("Graph is Bipartite\n");
    else
        printf("Graph is not Bipartite\n");

    // Đọc đầu vào, dòng 1 chứa số đỉnh và số cạnh của đồ thị
    // int numVertices, numEdges;
    // scanf("%d %d", &numVertices, &numEdges);
    // Graph *graph = initGraph(numVertices);
    // for (int i = 0; i < numEdges; i++)
    // {
    //     int u, v;
    //     scanf("%d %d", &u, &v);
    //     addEdge(graph, u, v);
    // }
    // printf(isBipartite(graph) ? "YES\n" : "NO\n");

    return 0;
}