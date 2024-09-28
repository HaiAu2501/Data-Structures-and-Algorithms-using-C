#include <iostream> // Thư viện hỗ trợ nhập xuất cơ bản
#include <vector>   // Thư viện hỗ trợ vector

using namespace std;

// Trong C++, vector là một cấu trúc dữ liệu mảng động, lưu trữ một dãy các phần tử cùng kiểu dữ liệu và có thể thay đổi kích thước.

// Khai báo một vetor:
vector<int> a;                   // Vector chứa các số nguyên
vector<int> b(5);                // Vector chứa 5 phần tử, mỗi phần tử có giá trị mặc định là 0
vector<int> c(5, 1);             // Vector chứa 5 phần tử, mỗi phần tử có giá trị mặc định là 1
vector<int> d = {1, 2, 3, 4, 5}; // Vector chứa 5 phần tử, giá trị của các phần tử lần lượt là 1, 2, 3, 4, 5

int main()
{
    vector<int> v = {1, 2, 3, 4, 5}; // Khai báo vector v chứa 5 phần tử, giá trị của các phần tử lần lượt là 1, 2, 3, 4, 5

    // Truy cập phần tử của vector:
    cout << v[1] << endl;      // In ra phần tử thứ 2 của vector v (v[1] = 2)
    cout << v.at(3) << endl;   // In ra phần tử thứ 4 của vector v (v.at(3) = 4)
    cout << v.front() << endl; // In ra phần tử đầu tiên của vector v (v.front() = 1)
    cout << v.back() << endl;  // In ra phần tử cuối cùng của vector v (v.back() = 5)

    // Thêm phần tử vào vector:
    v.push_back(6);    // Thêm phần tử 6 vào cuối vector v -> v = {1, 2, 3, 4, 5, 6}
    v.emplace_back(7); // Thêm phần tử 7 vào cuối vector v (hiệu quả hơn hàm push_back trong một số trường hợp) -> v = {1, 2, 3, 4, 5, 6, 7}

    // Xóa phần tử khỏi vector:
    v.pop_back();           // Xóa phần tử cuối cùng của vector v -> v = {1, 2, 3, 4, 5, 6}
    v.erase(v.begin() + 2); // Xóa phần tử thứ 3 của vector v -> v = {1, 2, 4, 5, 6}
    v.clear();              // Xóa tất cả phần tử của vector v -> v = {}

    // Các phương thức khác:
    cout << "Size: " << v.size() << endl;         // In ra số lượng phần tử của vector v
    cout << "Capacity: " << v.capacity() << endl; // In ra số lượng phần tử mà vector v có thể chứa mà không cần cấp phát thêm bộ nhớ
    cout << "Empty: " << v.empty() << endl;       // Kiểm tra vector v có rỗng không (trả về true nếu rỗng, ngược lại trả về false)

    // Thay đổi kích thước vector:
    v.resize(10); // Thay đổi kích thước vector v thành 10 phần tử, các phần tử mới có giá trị mặc định là 0

    // Duyệt vector:
    for (int i = 0; i < v.size(); i++) // Vòng lặp for truyền thống
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int &x : v) // Vòng lặp for-each
    {
        cout << x << " ";
    }
    cout << endl;

    for (int x : v) // Vòng lặp for-each (sao chép giá trị)
    {
        cout << x << " ";
    }

    return 0;
}
