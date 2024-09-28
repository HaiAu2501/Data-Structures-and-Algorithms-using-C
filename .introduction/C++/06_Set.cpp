#include <iostream>
#include <set>

using namespace std;

/* Set là CTDL tập hợp. Đặc điểm của set:
 | - Set chứa các phần tử không trùng lặp.
 | - Các phần tử trong set được sắp xếp tự động (mặc định theo thứ tự tăng dần).
 | - Set được triển khai dưới dạng cây nhị phân tìm kiếm cân bằng (AVL tree hoặc Red-Black tree).
 | -> Thao tác thêm, xóa, tìm kiếm phần tử trong set có độ phức tạp là O(log(n)).
 */

int main()
{
    // Khai báo một set:
    set<int> s = {5, 3, 1, 2, 4}; // Khai báo set s chứa 5 phần tử, giá trị của các phần tử lần lượt là 5, 3, 1, 2, 4

    // In ra các phần tử của set:
    for (int x : s) // Vòng lặp for-each
    {
        cout << x << " "; // 1 2 3 4 5 (set tự sắp xếp các phần tử)
    }

    /* Chú ý:
     | - Nếu duyệt bằng tham chiếu for (int &x : s) thì sẽ gặp lỗi.
     | - Bởi vì các phần tử trong set là const, không thể thay đổi giá trị của chúng.
     | -> Cách duyệt đúng là for (const int &x : s).
     */

    // Thêm phần tử vào set:
    s.insert(6);  // Thêm phần tử 6 vào set s -> s = {1, 2, 3, 4, 5, 6}
    s.emplace(7); // Thêm phần tử 7 vào set s (hiệu quả hơn hàm insert trong một số trường hợp) -> s = {1, 2, 3, 4, 5, 6, 7}

    // Xóa phần tử khỏi set:
    s.erase(7); // Xóa phần tử 7 khỏi set s -> s = {1, 2, 3, 4, 5, 6}

    // Các phương thức khác:
    cout << "Size: " << s.size() << endl;   // In ra số lượng phần tử của set s
    cout << "Empty: " << s.empty() << endl; // Kiểm tra set s có rỗng không (trả về true nếu rỗng, ngược lại trả về false)

    // Tìm kiếm phần tử trong set (trả về iterator):
    auto it = s.find(3); // Tìm kiếm phần tử 3 trong set s
    if (it != s.end())   // Nếu phần tử 3 tồn tại trong set s
    {
        cout << "Found: " << *it << endl; // In ra phần tử 3
    }
    else // Nếu phần tử 3 không tồn tại trong set s
    {
        cout << "Not found!" << endl;
    }

    // Hàm lower_bound và upper_bound:
    auto lb = s.lower_bound(3); // Tìm iterator trỏ đến phần tử đầu tiên có giá trị >= 3
    auto ub = s.upper_bound(3); // Tìm iterator trỏ đến phần tử đầu tiên có giá trị > 3

    cout << "Lower bound: " << *lb << endl; // In ra giá trị của phần tử tìm được
    cout << "Upper bound: " << *ub << endl; // In ra giá trị của phần tử tìm được
}