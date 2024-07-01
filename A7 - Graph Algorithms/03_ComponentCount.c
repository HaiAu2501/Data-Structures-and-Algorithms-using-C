#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Đếm số thành phần liên thông của đồ thị vô hướng.
 | - Đồ thị liên thông là đồ thị mà giữa mọi cặp đỉnh đều có đường đi.
 | - Một đồ thị bất kỳ có thể chia thành một hoặc nhiều thành phần liên thông có tập đỉnh không giao nhau.
 */

/* THUẬT TOÁN:
 | - Sử dụng DFS (Duyệt theo chiều sâu) hoặc BFS (Duyệt theo chiều rộng) để duyệt qua tất cả các đỉnh của đồ thị.
 | - Mỗi lần gặp một đỉnh chưa được duyệt, tăng biến đếm lên 1 và thực hiện DFS/BFS từ đỉnh đó.
 | - Kết thúc mỗi lần DFS/BFS, sẽ tìm được một thành phần liên thông.
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
    int visited[MAX_VERTICES];    // Mảng đánh dấu các đỉnh đã duyệt
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
        graph->visited[i] = 0;
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

// Hàm DFS đệ quy
void DFS(Graph *graph, int startVertex)
{
    Node *adjList = graph->adjLists[startVertex];
    Node *temp = adjList;

    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->data;

        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }

        temp = temp->next;
    }
}

// Hàm đếm số thành phần liên thông của đồ thị
int countConnectedComponents(Graph *graph)
{
    int count = 0;

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->visited[i] == 0)
        {
            count++;
            DFS(graph, i);
            printf("\n");
        }
    }

    return count;
}

int main()
{
    Graph *graph = initGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 3, 4);

    printf("Number of connected components: %d\n", countConnectedComponents(graph));

    return 0;
}