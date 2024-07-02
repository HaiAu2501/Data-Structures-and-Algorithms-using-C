#include <stdio.h>
#include <stdlib.h>

/* ĐỀ BÀI: Tìm cây khung nhỏ nhất của đồ thị vô hướng sử dụng thuật toán Kruskal.
 | - Cho đồ thị vô hướng liên thông G = (V, E) với tập đỉnh V và tập cạnh E.
 | - Với mỗi (u, v) thuộc E, có trọng số w(u, v).
 | - Cây T = (V, F) với F là tập con của E được gọi là một cây khung của G.
 | -> Tìm cây khung có tổng trọng số nhỏ nhất.
 */

/* THUẬT TOÁN KRUSKAL:
 | - Sắp xếp tất cả các cạnh theo thứ tự không giảm của trọng số.
 | - Chọn cạnh nhỏ nhất, kiểm tra xem việc thêm cạnh đó vào cây có tạo thành chu trình hay không.
 | - Nếu không tạo thành chu trình, thêm cạnh đó vào cây.
 | - Lặp lại bước 3 cho đến khi có (V - 1) cạnh trong cây.
 */

/* CẤU TRÚC DỮ LIỆU DISJOINT SET:
 | - Disjoint Set là một cấu trúc dữ liệu cho phép lưu trữ các tập hợp phân biệt.
 | - Các phần tử trong mỗi tập hợp phân biệt được lưu trữ dưới dạng một cây nhị phân.
 | - Có 2 phép toán chính:
 | + Find(x): Tìm tập hợp mà phần tử x thuộc về.
 | + Union(x, y): Gộp hai tập hợp chứa x và y thành một tập hợp.
 */

/* CÀI ĐẶT THUẬT TOÁN KRUSKAL VỚI DISJOINT SET:
 | - Sắp xếp tất cả các cạnh theo thứ tự không giảm của trọng số.
 | - Khởi tạo cây khung rỗng.
 | - Duyệt qua tất cả các cạnh:
 | + Nếu cạnh đó không tạo thành chu trình khi thêm vào cây khung, thêm cạnh đó vào cây khung.
 | + Sử dụng Disjoint Set để kiểm tra xem cạnh đó có tạo thành chu trình hay không.
 */

// Biểu diễn đồ thị bởi tập cạnh

// Đinh nghĩa cấu trúc cạnh
typedef struct Edge
{
    int src, dest, weight;
} Edge;

// Định nghĩa cấu trúc đồ thị
typedef struct Graph
{
    int V, E;   // Số đỉnh và số cạnh
    Edge *edge; // Mảng chứa các cạnh
} Graph;

// Định nghĩa cấu trúc Disjoint Set
typedef struct DisjointSet
{
    int *parent, *rank;
    int n;
} DisjointSet;

// Hàm tạo một Disjoint Set mới
DisjointSet *createDisjointSet(int n)
{
    DisjointSet *ds = (DisjointSet *)malloc(sizeof(DisjointSet));
    ds->n = n;
    ds->parent = (int *)malloc(n * sizeof(int));
    ds->rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

// Hàm tìm tập hợp mà phần tử x thuộc về
int find(DisjointSet *ds, int x)
{
    if (ds->parent[x] != x)
        ds->parent[x] = find(ds, ds->parent[x]);
    return ds->parent[x];
}

// Hàm gộp hai tập hợp chứa x và y thành một tập hợp
void unionSet(DisjointSet *ds, int x, int y)
{
    int rootX = find(ds, x);
    int rootY = find(ds, y);
    if (ds->rank[rootX] < ds->rank[rootY])
        ds->parent[rootX] = rootY;
    else if (ds->rank[rootX] > ds->rank[rootY])
        ds->parent[rootY] = rootX;
    else
    {
        ds->parent[rootY] = rootX;
        ds->rank[rootX]++;
    }
}

// Hàm so sánh hai cạnh theo trọng số
int compareEdge(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight > b1->weight;
}

// Hàm tìm cây khung nhỏ nhất của đồ thị
void kruskalMST(Graph *graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0, i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdge);
    DisjointSet *ds = createDisjointSet(V);
    while (e < V - 1)
    {
        Edge nextEdge = graph->edge[i++];
        int x = find(ds, nextEdge.src);
        int y = find(ds, nextEdge.dest);
        if (x != y)
        {
            result[e++] = nextEdge;
            unionSet(ds, x, y);
        }
    }
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main()
{
    int V, E;
    scanf("%d%d", &V, &E);
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge *)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++)
        scanf("%d%d%d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    kruskalMST(graph);
    return 0;
}