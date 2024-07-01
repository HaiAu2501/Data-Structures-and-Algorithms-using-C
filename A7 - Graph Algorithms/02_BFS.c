#include <stdio.h>
#include <stdlib.h>

/* CÀI ĐẶT THUẬT TOÁN BFS (Breadth First Search) TRÊN ĐỒ THỊ VÔ HƯỚNG:
 | - Đồ thị sử dụng danh sách kề.
 | - Sử dụng hàng đợi.
 | - Độ phức tạp: O(V + E), V là số đỉnh, E là số cạnh.
 */

#define MAX 100 // Số đỉnh tối đa

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node *adjLists[MAX];
    int visited[MAX];
} Graph;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Hàm tạo một Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm khởi tạo đồ thị
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Hàm thêm cạnh vào đồ thị
void addEdge(Graph *graph, int u, int v)
{
    // Thêm cạnh từ u đến v
    Node *newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    // Thêm cạnh từ v đến u
    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

// Khởi tạo hàng đợi
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Thêm vào cuối hàng đợi
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

// Lấy phần tử ở đầu hàng đợi
int dequeue(Queue *q)
{
    if (q->front == NULL)
        return -1;

    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}

// Hàm duyệt đồ thị theo chiều rộng
void BFS(Graph *graph, int startVertex)
{
    // Tạo một hàng đợi mới
    Queue *queue = createQueue();

    // Đánh dấu đỉnh bắt đầu đã được duyệt
    graph->visited[startVertex] = 1;

    // Thêm đỉnh bắt đầu vào hàng đợi
    enqueue(queue, startVertex);

    while (queue->front != NULL)
    {
        // Lấy đỉnh ra khỏi hàng đợi và in ra
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Duyệt qua tất cả các đỉnh kề với đỉnh hiện tại
        Node *temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->data;

            // Nếu đỉnh kề chưa được duyệt thì đánh dấu đã duyệt và thêm vào hàng đợi
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }

            temp = temp->next;
        }
    }
}

int main()
{
    Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("BFS: ");
    BFS(graph, 0);

    return 0;
}
