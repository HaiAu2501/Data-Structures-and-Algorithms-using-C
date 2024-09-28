#include <iostream>
#include <map>
#include <string>

using namespace std;

/* Map là CTDL tập hợp có ánh xạ chứa các cặp key-value. Đặc điểm của map:
 | - Map chứa các phần tử không trùng key.
 | - Các phần tử trong map được sắp xếp theo key tăng dần.
 | - Map được triển khai dưới dạng cây nhị phân tìm kiếm cân bằng (AVL tree hoặc Red-Black tree).
 | -> Thao tác thêm, xóa, tìm kiếm phần tử trong map có độ phức tạp là O(log(n)).
 */

int main()
{
    // Khai báo 1 map, key là string, value là int:
    map<string, int> m = {{"Alice", 20}, {"Bob", 27}, {"Carol", 19}, {"Arthur", 22}, {"Ben", 25}};

    // In ra các phần tử của map:
    for (const auto &x : m) // Vòng lặp for-each (x là một pair)
    {
        cout << x.first << ": " << x.second << endl; // Alice: 20, Arthur: 22, Ben: 25, Bob: 27, Carol: 19 (map tự sắp xếp các phần tử)
    }

    // Thêm phần tử vào map:
    m.insert({"David", 30});
    m.insert(make_pair("Eva", 35));

    // Nếu thêm phần tử đã tồn tại, hàm insert sẽ không thêm phần tử mới mà trả về iterator trỏ đến phần tử đã tồn tại:
    auto it = m.insert({"Alice", 40});
    if (it.second) // Nếu phần tử được thêm thành công
    {
        cout << "Inserted!" << endl;
    }
    else // Nếu phần tử đã tồn tại
    {
        cout << "Existed!" << endl;                                  // Existed! (dù value khác nhau nhưng key giống nhau)
        cout << it.first->first << ": " << it.first->second << endl; // Alice: 20
    }

    m["Daniel"] = 45; // Thêm phần tử {"Daniel", 45} vào map m
    for (const auto &x : m)
    {
        cout << x.first << ": " << x.second << endl;
    }

    // Xóa phần tử khỏi map:
    m.erase("David"); // Xóa phần tử có key là "David" khỏi map m

    // Các phương thức khác:
    cout << "Size: " << m.size() << endl;   // In ra số lượng phần tử của map m
    cout << "Empty: " << m.empty() << endl; // Kiểm tra map m có rỗng không (trả về true nếu rỗng, ngược lại trả về false)
}