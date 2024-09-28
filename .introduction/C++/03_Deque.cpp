#include <iostream>
#include <deque>

using namespace std;

// Trong C++, deque (double-ended queue) là một cấu trúc dữ liệu tuyến tính, lưu trữ một dãy các phần tử cùng kiểu dữ liệu.

// Khai báo một deque:
deque<int> a;                   // deque rỗng chứa các số nguyên
deque<int> b(5);                // deque chứa 5 phần tử, mỗi phần tử có giá trị mặc định là 0
deque<int> c(5, 1);             // deque chứa 5 phần tử, mỗi phần tử có giá trị mặc định là 1
deque<int> d = {1, 2, 3, 4, 5}; // deque chứa 5 phần tử, giá trị của các phần tử lần lượt là 1, 2, 3, 4, 5

int main()
{
    deque<int> deq = {1, 2, 3, 4, 5}; // Khai báo deque deq chứa 5 phần tử, giá trị của các phần tử lần lượt là 1, 2, 3, 4, 5

    // Thêm phần tử vào deque:
    deq.push_back(6);  // Thêm phần tử 6 vào cuối deque deq -> deq = {1, 2, 3, 4, 5, 6}
    deq.push_front(0); // Thêm phần tử 0 vào đầu deque deq -> deq = {0, 1, 2, 3, 4, 5, 6}

    // Chèn phần tử vào deque:
    auto it = deq.end(); // Khai báo một iterator trỏ đến phần tử cuối cùng của deque deq
    deq.insert(it, 7);   // Chèn phần tử 7 vào cuối deque deq -> deq = {0, 1, 2, 3, 4, 5, 6, 7}

    // In ra các phần tử của deque:
    for (int &x : deq) // Vòng lặp for-each
    {
        cout << x << " "; // 0 1 2 3 4 5 6 7
    }

    return 0;
}