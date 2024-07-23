#include <stdio.h>

/* ĐỀ BÀI: Tìm hiểu CTDL bảng băm (Hash Table) và cài đặt các hàm xử lý.
 | - Hàm băm (Hash Function): Chuyển khóa thành chỉ số của bảng băm.
 | - Bảng băm (Hash Table): Mảng lưu trữ các phần tử dựa trên chỉ số của chúng.
 */

/* VẤN ĐỀ XUNG ĐỘT (COLLISION): Xảy ra khi hai hoặc nhiều phần tử có cùng chỉ số băm.
 | - Cách giải quyết:
 | + Phương pháp tạo chuỗi (Chaining): Mỗi chỉ số của bảng băm lưu trữ một danh sách liên kết các phần tử.
 | + Phương pháp địa chỉ mở (Open Addressing):
 |   -> Tìm một vị trí trống khác để lưu trữ phần tử.
 |   -> Khi bổ sung phần tử mới, nếu xảy ra xung đột thì tìm vị trí trống (phương pháp dò thử - probing).
 |   -> Để tìm kiếm, ta sẽ tìm dọc theo dãy các phép dò thử cho đến khi tìm thấy phần tử hoặc gặp vị trí trống.
 |   -> Có nhiều phương pháp dò thử: tuyến tính, bình phương, kép, v.v.
 */

/* CÁC PHƯƠNG PHÁP DÒ THỬ (PROBING):
 | - Tuyến tính (Linear Probing): Mỗi lần dò, tăng chỉ số băm lên một đơn vị.
 | - Bình phương (Quadratic Probing): Mỗi lần dò, tăng chỉ số băm lên bình phương của bước dò.
 | - Kép (Double Hashing): Mỗi lần dò, tăng chỉ số băm lên một lượng được tính bằng một hàm băm khác.
 */

int SIZE = 100; // Kích thước bảng băm

// HÀM BĂM THEO MODULO
int hash(int key)
{
    return key % SIZE;
}

// HÀM TẠO BẢNG BĂM
int *createHashTable()
{
    int *hashTable = (int *)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1; // Khởi tạo tất cả các phần tử bằng -1
    return hashTable;
}

// HÀM THÊM PHẦN TỬ VÀO BẢNG BĂM

/* CÁCH 1: CHAINING (PHƯƠNG PHÁP TẠO CHUỖI)
 | - Mỗi chỉ số của bảng băm lưu trữ một danh sách liên kết các phần tử.
 | - Khi xảy ra xung đột, phần tử mới sẽ được thêm vào đầu danh sách.
 */

// Cấu trúc Node cho danh sách liên kết
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Hàm tạo một Node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào danh sách liên kết
void addNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Hàm thêm phần tử vào bảng băm
void addElement(int *hashTable, int key)
{
    int index = hash(key);
    if (hashTable[index] == -1)
    {
        hashTable[index] = key;
    }
    else
    {
        Node *head = NULL;
        addNode(&head, hashTable[index]);
        addNode(&head, key);
        hashTable[index] = (int)head;
    }
}

// HÀM TÌM KIẾM PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP CHAINING
int searchElement(int *hashTable, int key)
{
    int index = hash(key);
    if (hashTable[index] == key)
        return index;

    Node *head = (Node *)hashTable[index];
    while (head != NULL)
    {
        if (head->data == key)
            return index;
        head = head->next;
    }

    return -1;
}

// HÀM XÓA PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP CHAINING
void deleteElement(int *hashTable, int key)
{
    int index = hash(key);
    if (hashTable[index] == key)
    {
        hashTable[index] = -1;
        return;
    }

    Node *head = (Node *)hashTable[index];
    Node *prev = NULL;
    while (head != NULL)
    {
        if (head->data == key)
        {
            if (prev != NULL)
                prev->next = head->next;
            free(head);
            return;
        }
        prev = head;
        head = head->next;
    }
}

/* CÁCH 2: OPEN ADDRESSING (PHƯƠNG PHÁP ĐỊA CHỈ MỞ)
 | - Khi xảy ra xung đột, tìm một vị trí trống khác để lưu trữ phần tử.
 */

// CÁCH 2.1: DÒ THỬ TUYẾN TÍNH (LINEAR PROBING)
// HÀM THÊM PHẦN TỬ VÀO BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ TUYẾN TÍNH
void addElementLP(int *hashTable, int key)
{
    int index = hash(key);
    int i = 1;
    while (hashTable[index] != -1)
    {
        index = (index + i) % SIZE;
        i++;
    }
    hashTable[index] = key;
}

// HÀM TÌM KIẾM PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ TUYẾN TÍNH
int searchElementLP(int *hashTable, int key)
{
    int index = hash(key);
    int i = 1;
    while (hashTable[index] != key)
    {
        if (hashTable[index] == -1)
            return -1;
        index = (index + i) % SIZE;
        i++;
    }
    return index;
}

// HÀM XÓA PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ TUYẾN TÍNH
void deleteElementLP(int *hashTable, int key)
{
    int index = searchElementLP(hashTable, key);
    if (index != -1)
        hashTable[index] = -1;
}

// CÁCH 2.2: DÒ THỬ BÌNH PHƯƠNG (QUADRATIC PROBING)
// HÀM THÊM PHẦN TỬ VÀO BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ BÌNH PHƯƠNG
void addElementQP(int *hashTable, int key)
{
    int index = hash(key);
    int i = 1;
    while (hashTable[index] != -1)
    {
        index = (index + i * i) % SIZE;
        i++;
    }
    hashTable[index] = key;
}

// HÀM TÌM KIẾM PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ BÌNH PHƯƠNG
int searchElementQP(int *hashTable, int key)
{
    int index = hash(key);
    int i = 1;
    while (hashTable[index] != key)
    {
        if (hashTable[index] == -1)
            return -1;
        index = (index + i * i) % SIZE;
        i++;
    }
    return index;
}

// HÀM XÓA PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ BÌNH PHƯƠNG
void deleteElementQP(int *hashTable, int key)
{
    int index = searchElementQP(hashTable, key);
    if (index != -1)
        hashTable[index] = -1;
}

// CÁCH 2.3: DÒ THỬ KÉP (DOUBLE HASHING)
// HÀM BĂM THỨ HAI CHO PHƯƠNG PHÁP DÒ THỬ KÉP
int hash2(int key)
{
    return 7 - (key % 7);
}

// HÀM THÊM PHẦN TỬ VÀO BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ KÉP
void addElementDH(int *hashTable, int key)
{
    int index = hash(key);
    int i = 1;
    while (hashTable[index] != -1)
    {
        index = (hash(key) + i * hash2(key)) % SIZE;
        i++;
    }
    hashTable[index] = key;
}

// HÀM TÌM KIẾM PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ KÉP
int searchElementDH(int *hashTable, int key)
{
    int index = hash(key);
    int i = 1;
    while (hashTable[index] != key)
    {
        if (hashTable[index] == -1)
            return -1;
        index = (hash(key) + i * hash2(key)) % SIZE;
        i++;
    }
    return index;
}

// HÀM XÓA PHẦN TỬ TRONG BẢNG BĂM TƯƠNG ỨNG VỚI PHƯƠNG PHÁP DÒ THỬ KÉP
void deleteElementDH(int *hashTable, int key)
{
    int index = searchElementDH(hashTable, key);
    if (index != -1)
        hashTable[index] = -1;
}

int main()
{
    int *hashTable = createHashTable();
    addElement(hashTable, 10);
    addElement(hashTable, 20);
    addElement(hashTable, 30);
    addElement(hashTable, 40);
    addElement(hashTable, 50);
    addElement(hashTable, 60);
    addElement(hashTable, 70);
    addElement(hashTable, 80);
    addElement(hashTable, 90);
    addElement(hashTable, 100);

    printf("Search 20: %d\n", searchElement(hashTable, 20));
    printf("Search 50: %d\n", searchElement(hashTable, 50));
    printf("Search 100: %d\n", searchElement(hashTable, 100));
    printf("Search 200: %d\n", searchElement(hashTable, 200));

    deleteElement(hashTable, 20);
    deleteElement(hashTable, 50);
    deleteElement(hashTable, 100);

    printf("Search 20: %d\n", searchElement(hashTable, 20));
    printf("Search 50: %d\n", searchElement(hashTable, 50));
    printf("Search 100: %d\n", searchElement(hashTable, 100));

    return 0;
}