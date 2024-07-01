#include <stdio.h>
#include <stdlib.h>

/* CÀI ĐẶT THUẬT TOÁN DFS (Depth First Search) TRÊN ĐỒ THỊ VÔ HƯỚNG:
 | - Đồ thị sử dụng danh sách kề.
 | - Sử dụng đệ quy.
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

// Khai báo stack
Node *head = NULL;

// Hàm push một đỉnh vào stack
void push(int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Hàm pop một đỉnh ra khỏi stack
int pop()
{
    if (head == NULL)
        return -1;

    Node *temp = head;
    head = head->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// Hàm DFS sử dụng đệ quy
void DFS(Graph *graph, int vertex)
{
    Node *adjList = graph->adjLists[vertex];
    Node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

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

// Hàm DFS sử dụng stack
void DFS_stack(Graph *graph, int startVertex)
{
    push(startVertex);
    graph->visited[startVertex] = 1;

    while (head != NULL)
    {
        int currentVertex = pop();
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->data;

            if (graph->visited[adjVertex] == 0)
            {
                push(adjVertex);
                graph->visited[adjVertex] = 1;
            }

            temp = temp->next;
        }
    }
}

int main()
{
    Graph *graph = createGraph(9);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 8);

    // ĐỒ THỊ:
    //        1           7
    //       /           /
    //      0 - 2 - 4 - 5 - 6 - 8
    //       \ /
    //        3

    printf("DFS: ");
    DFS_stack(graph, 0);

    return 0;
}
