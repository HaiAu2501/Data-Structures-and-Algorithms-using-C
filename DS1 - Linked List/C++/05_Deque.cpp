#include <iostream>
#include <deque>
using namespace std;

// Trong C++, cấu trúc dữ liệu hàng đợi 2 đầu (deque) được cung cấp trong thư viện <deque>

// Hàm in ra hàng đợi 2 đầu
void printDeque(deque<int> dq)
{
    for (int i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;
}

int main()
{
    // Khởi tạo một deque chứa các số nguyên
    deque<int> dq;

    // Thêm phần tử vào cuối deque
    dq.push_back(1);
    dq.push_back(2);

    // Thêm phần tử vào đầu deque
    dq.push_front(3);

    // In ra deque: 3 1 2
    printDeque(dq);

    // Xem phần tử ở đầu deque
    cout << dq.front() << endl; // 3

    // Xem phần tử ở cuối deque
    cout << dq.back() << endl; // 2

    // Lấy ra phần tử ở đầu deque
    dq.pop_front();

    // Lấy ra phần tử ở cuối deque
    dq.pop_back();

    return 0;
}
