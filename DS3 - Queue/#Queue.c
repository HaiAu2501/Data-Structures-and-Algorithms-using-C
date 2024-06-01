#include <stdio.h>
#include <stdlib.h>

// Hàng đợi (Queue) là một cấu trúc dữ liệu dạng FIFO (First In First Out, vào trước ra trước)
/* Các phép toán cơ bản trên hàng đợi:
 * - enqueue: Thêm một phần tử vào cuối hàng đợi.
 * - dequeue: Lấy giá trị của phần tử ở đầu hàng đợi (và xóa nó).
 * - front: Lấy giá trị của phần tử ở đầu hàng đợi (mà không xóa nó).
 * - isEmpty: Kiểm tra xem hàng đợi có rỗng không.
 */

// Định nghĩa cấu trúc Node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Định nghĩa cấu trúc Queue
typedef struct Queue
{
    Node *front, *rear;
} Queue;

/* Triển khai hàng đợi trong C sử dụng 2 con trỏ front và rear:
 * - front: Con trỏ trỏ đến phần tử ở đầu hàng đợi.
 * - rear: Con trỏ trỏ đến phần tử ở cuối hàng đợi.
 * Đây là cách triển khai phổ biến nhất vì nó giúp giảm độ phức tạp của một số phép toán.
 * - Thao tác enqueue: O(1)
 * - Thao tác dequeue: O(1)
 * - Thao tác front: O(1)
 */

// Hàm khởi tạo một hàng đợi
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Hàm tạo một Node mới
Node *createNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Hàm thêm một phần tử vào cuối hàng đợi
/* - Thêm một phần tử vào cuối hàng đợi tương đương với việc thêm một Node mới vào cuối danh sách liên kết.
 * - Đầu tiên, tạo một Node mới với dữ liệu là data.
 * - Nếu hàng đợi rỗng, gán cả front và rear trỏ đến Node mới.
 * - Ngược lại, gán con trỏ next của rear trỏ đến Node mới, và cập nhật rear trỏ đến Node mới.
 */
void enqueue(Queue *q, int data)
{
    Node *new_node = createNode(data);

    // Nếu hàng đợi rỗng, gán cả front và rear trỏ đến Node mới
    if (q->front == NULL)
    {
        q->front = q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Hàm lấy giá trị của phần tử ở đầu hàng đợi (và xóa nó)
/* - Lấy giá trị của phần tử ở cuối hàng đợi tương đương với việc lấy giá trị của Node cuối cùng trong danh sách liên kết.
 * - Lưu giá trị của Node cuối cùng vào biến result.
 * - Cập nhật front trỏ đến Node thứ hai trong danh sách liên kết.
 * - Trả về giá trị của result.
 */
int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return -1;
    }
    else
    {
        int result = q->front->data;
        Node *temp = q->front;

        q->front = q->front->next;
        free(temp);

        return result;
    }
}

// Hàm lấy giá trị của phần tử ở đầu hàng đợi (mà không xóa nó)
int front(Queue *q)
{
    if (q->front == NULL)
    {
        return -1;
    }

    return q->front->data;
}

// Hàm in hàng đợi
void printQueue(Queue *q)
{
    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void main()
{
    Queue *q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printQueue(q); // 1 2 3

    printf("%d\n", dequeue(q)); // 1
    printf("%d\n", front(q));   // 2

    printQueue(q); // 2 3
}