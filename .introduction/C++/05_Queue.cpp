#include <iostream>
#include <queue>

using namespace std;

// Trong C++, queue là CTDL hàng đợi, FIFO.

int main()
{
    // Khai báo 1 queue:
    queue<int> q;

    // Thêm phần tử vào queue (phần tử được thêm nằm ở cuối queue):
    q.push(1); // Thêm phần tử 1 vào queue -> q = {1}
    q.push(2); // Thêm phần tử 2 vào queue -> q = {1, 2}

    // Lấy phần tử ra khỏi queue:
    q.pop(); // Xóa phần tử đầu tiên của queue -> q = {2} (q.pop() trả về void)

    // Lấy phần tử đầu tiên của queue mà không xóa nó:
    q.push(1);
    cout << q.front() << endl; // In ra phần tử đầu tiên của queue -> 2

    // Kiểm tra queue có rỗng không:
    cout << q.empty() << endl; // Kiểm tra queue có rỗng không (trả về true nếu rỗng, ngược lại trả về false)
}