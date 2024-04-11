#include <iostream>
#include <queue>
using namespace std;

// Thư viện chuẩn C++ (C++ STL) cung cấp cấu trúc dữ liệu queue hỗ trợ các phép toán:
/* - push(): Thêm một phần tử vào cuối queue.
 * - pop(): Xóa phần tử ở đầu queue.
 * - front(): Trả về phần tử ở đầu queue.
 * - back(): Trả về phần tử ở cuối queue.
 * - empty(): Kiểm tra queue rỗng.
 * - size(): Trả về số lượng phần tử trong queue.
 */

int main()
{
    // Khai báo một queue kiểu int
    queue<int> q;

    // Thêm phần tử vào cuối queue
    q.push(1);
    q.push(2);

    // Xem phần tử ở đầu queue
    cout << q.front() << endl; // 1

    // Xem phần tử ở cuối queue
    cout << q.back() << endl; // 2

    // Xóa phần tử ở đầu queue
    q.pop();

    // Kiểm tra queue rỗng
    if (q.empty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    // Xem số lượng phần tử trong queue
    cout << q.size() << endl; // 1

    return 0;
}