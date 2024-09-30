#include <iostream>

using namespace std;

// Trong lập trình thi đấu, việc tối ưu hóa I/O là một trong những yếu tố quan trọng giúp tăng hiệu suất chương trình.

int main()
{
    ios::sync_with_stdio(0); // Tắt đồng bộ giữa C và C++.
    cin.tie(0);
    cout.tie(0); // Tắt đồng bộ giữa cin/cout và scanf/printf.
    // Khuyến nghị cin.tie(nullptr) và cout.tie(nullptr) vì tính rõ ràng và an toàn về kiểu dữ liệu.

    int a, b;
    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}