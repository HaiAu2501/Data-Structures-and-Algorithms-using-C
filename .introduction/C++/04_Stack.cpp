#include <iostream>
#include <stack>

using namespace std;

// Trong C++, stack là CTDL ngăn xếp, LIFO.

int main()
{
    // Khai báo 1 stack:
    stack<int> s;

    // Thêm phần tử vào stack (phần tử được thêm nằm ở đỉnh stack):
    s.push(1); // Thêm phần tử 1 vào stack -> s = {1}
    s.push(2); // Thêm phần tử 2 vào stack -> s = {1, 2}

    // Lấy phần tử ra khỏi stack:
    s.pop(); // Xóa phần tử đầu tiên của stack -> s = {} (s.pop() trả về void)

    // Lấy phần tử đầu tiên của stack mà không xóa nó:
    s.push(1);
    cout << s.top() << endl; // In ra phần tử đầu tiên của stack -> 1

    // Kiểm tra stack có rỗng không:
    cout << s.empty() << endl; // Kiểm tra stack có rỗng không (trả về true nếu rỗng, ngược lại trả về false)
}