#include <iostream>
#include <vector> // Thư viện hỗ trợ vector
using namespace std;

// Trong C++, vector là một cấu trúc dữ liệu mảng động, cho phép thêm, xóa phần tử một cách linh hoạt
/* - Vector là kiểu dữ liệu trừu tượng (abstract data type), còn gọi là array list.
 * - Vector hỗ trợ các hàm cơ bản bảo gồm:
 * + size(): trả về số lượng phần tử trong vector
 * + empty(): kiểm tra vector có rỗng hay không
 * + resize(n): thay đổi kích thước vector thành n phần tử
 * + vector[i]: trả về phần tử ở vị trí i trong vector
 * + front(): trả về tham chiếu đến phần tử đầu tiên trong vector -> độ phức tạp O(1)
 * + back(): trả về tham chiếu đến phần tử cuối cùng trong vector -> độ phức tạp O(1)
 * + push_back(x): thêm phần tử x vào cuối vector
 * -> độ phức tạp O(1) nếu không cần cấp phát thêm bộ nhớ, O(n) nếu cần cấp phát thêm bộ nhớ
 * + pop_back(): xóa phần tử cuối cùng của vector và giảm kích thước vector đi 1
 */

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

// Ví dụ:
int main()
{
    // Khai báo vector
    vector<int> v(6); // Khởi tạo vector với 6 phần tử, mỗi phần tử có giá trị mặc định là 0
    printVector(v);

    // Thêm phần tử vào vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    printVector(v);

    // Xóa phần tử cuối cùng của vector
    v.pop_back();
    printVector(v);

    // Truy cập phần tử trong vector
    cout << "v[2] = " << v[2] << endl;

    // Thay đổi kích thước vector
    v.resize(10); // Thay đổi kích thước vector thành 10 phần tử
    printVector(v);

    // Nếu thay đổi về kich thước nhỏ hơn, các phần tử sau sẽ bị xóa
    v.resize(2);
    printVector(v);

    // Trả về phần tử đầu tiên và cuối cùng của vector
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
}
