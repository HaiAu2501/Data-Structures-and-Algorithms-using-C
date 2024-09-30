#include <iostream>
#include <queue> // Thư viện hỗ trợ queue, trong đó có priority_queue

using namespace std;

/* priority_queue là CTDL hàng đợi ưu tiên.
 | - Phần tử có độ ưu tiên cao nhất luôn nằm ở đầu priority_queue.
 | - priority_queue được triển khai dưới dạng max-heap theo mặc định.
 | -> Thao tác thêm, xóa phần tử trong priority_queue có độ phức tạp là O(log(n)).
 */

int main()
{
    // Khai báo 1 priority_queue:
    priority_queue<int> pq;

    /* Lưu ý:
     | - Không thể khởi tạo priority_queue bằng cách truyền danh sách khởi tạo như vector, set, map.
     | - Cú pháp sai: priority_queue<int> pq = {1, 2, 3, 4, 5};
     */

    // Khởi tạo từ một vector:
    vector<int> v = {4, 2, 5, 1, 3};
    priority_queue<int> pq1(v.begin(), v.end());

    // Thêm phần tử vào priority_queue:
    pq.push(5);
    pq.push(6);
    pq.push(3);
    pq.push(4);
    pq.push(1);
    pq.push(2);

    while (!pq.empty())
    {
        cout << pq.top() << " "; // In ra phần tử có độ ưu tiên cao nhất -> 6 5 4 3 2 1
        pq.pop();
    }

    return 0;
}