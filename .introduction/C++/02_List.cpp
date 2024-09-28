#include <iostream>
#include <list> // Thư viện hỗ trợ list

using namespace std;

// Trong C++, list là một cấu trúc dữ liệu danh sách liên kết đôi, lưu trữ một dãy các phần tử cùng kiểu dữ liệu.

/* Các đặc điểm của list:
 |   - Chèn, xóa phần tử ở đầu, cuối, hoặc ở bất kỳ vị trí nào trong danh sách với độ phức tạp O(1).
 |   - Không hỗ trợ truy cập ngẫu nhiên đến phần tử, chỉ hỗ trợ duyệt tuần tự từ đầu đến cuối hoặc ngược lại.
 */

// Khai báo một list:
list<int> a;                   // List rỗng chứa các số nguyên
list<int> b(5);                // List chứa 5 phần tử, mỗi phần tử có giá trị mặc định là 0
list<int> c(5, 1);             // List chứa 5 phần tử, mỗi phần tử có giá trị mặc định là 1
list<int> d = {1, 2, 3, 4, 5}; // List chứa 5 phần tử, giá trị của các phần tử lần lượt là 1, 2, 3, 4, 5

int main()
{
    list<int> l = {1, 2, 3, 4, 5}; // Khai báo list l chứa 5 phần tử, giá trị của các phần tử lần lượt là 1, 2, 3, 4, 5

    // Thêm phần tử vào list:
    l.push_back(6);      // Thêm phần tử 6 vào cuối list l -> l = {1, 2, 3, 4, 5, 6}
    l.push_front(0);     // Thêm phần tử 0 vào đầu list l -> l = {0, 1, 2, 3, 4, 5, 6}
    l.emplace_back(7);   // Thêm phần tử 7 vào cuối list l (hiệu quả hơn hàm push_back trong một số trường hợp) -> l = {0, 1, 2, 3, 4, 5, 6, 7}
    l.emplace_front(-1); // Thêm phần tử -1 vào đầu list l (hiệu quả hơn hàm push_front trong một số trường hợp) -> l = {-1, 0, 1, 2, 3, 4, 5, 6, 7}

    // Chèn phần tử vào list:
    auto it = l.begin(); // Khai báo một iterator trỏ đến phần tử đầu tiên của list l
    advance(it, 3);      // Dịch chuyển iterator it 3 vị trí, trỏ đến phần tử thứ 4 của list l
    l.insert(it, 8);     // Chèn phần tử 8 vào trước phần tử thứ 4 của list l -> l = {-1, 0, 1, 8, 2, 3, 4, 5, 6, 7}

    // In ra các phần tử của list:
    for (int &x : l) // Vòng lặp for-each
    {
        cout << x << " "; // - 1 0 1 8 2 3 4 5 6 7
    }
    cout << endl;

    // Xóa phần tử khỏi list:
    l.pop_back();  // Xóa phần tử cuối cùng của list l -> l = {-1, 0, 1, 8, 2, 3, 4, 5, 6}
    l.pop_front(); // Xóa phần tử đầu tiên của list l -> l = {0, 1, 8, 2, 3, 4, 5, 6}
    l.erase(it);   // Xóa phần tử thứ 4 của list l -> l = {0, 1, 8, 3, 4, 5, 6}
    l.remove(3);   // Xóa tất cả phần tử có giá trị bằng 3 trong list l -> l = {0, 1, 8, 4, 5, 6}
    // l.clear();  // Xóa tất cả phần tử của list l -> l = {}

    // Các phương thức khác:
    cout << "Size: " << l.size() << endl;   // In ra số lượng phần tử của list l
    cout << "Empty: " << l.empty() << endl; // Kiểm tra list l có rỗng không (trả về true nếu rỗng, ngược lại trả về false)
    cout << "Front: " << l.front() << endl; // In ra phần tử đầu tiên của list l
    cout << "Back: " << l.back() << endl;   // In ra phần tử cuối cùng của list l

    l.sort();    // Sắp xếp các phần tử của list l theo thứ tự tăng dần
    l.reverse(); // Đảo ngược thứ tự các phần tử của list l
    l.unique();  // Xóa các phần tử trùng nhau trong list l

    return 0;
}