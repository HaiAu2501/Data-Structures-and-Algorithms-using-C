#include <iostream>
#include <stack>
// Có thể dùng #include <bits/stdc++.h> để include tất cả các thư viện cần thiết
using namespace std;

// Thư viện chuẩn C++ (C++ STL) cung cấp cấu trúc dữ liệu stack hỗ trợ các phép toán:
/* - push(): Thêm một phần tử vào đỉnh stack.
 * - pop(): Xóa phần tử ở đỉnh stack.
 * - top(): Trả về phần tử ở đỉnh stack.
 * - empty(): Kiểm tra stack rỗng.
 * - size(): Trả về số lượng phần tử trong stack.
 */

int main()
{
    // Khai báo một stack kiểu int
    stack<int> s;

    // Thêm phần tử vào đỉnh stack
    s.push(1);
    s.push(2);

    // Xem phần tử ở đỉnh stack
    cout << s.top() << endl; // 2

    // Xóa phần tử ở đỉnh stack
    s.pop();

    // Kiểm tra stack rỗng
    if (s.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    // Xem số lượng phần tử trong stack
    cout << s.size() << endl; // 1

    return 0;
}
