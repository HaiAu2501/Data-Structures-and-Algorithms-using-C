#include <iostream>
#include <string>

using namespace std;

/* Đề bài: Cộng hai số nguyên a, b mà 0 <= a, b <= 10^19
 | Nhận xét:
 | - Kiểu long long chứa được các số khoảng -9 * 10^18 đến 9 * 10^18 (kiểu dài nhất đối với số nguyên)
 | - Kiểu unsigned long long chứa được các số khoảng 0 đến 18 * 10^18
 | - Tổng hai số có thể vượt quá giới hạn của kiểu long long, unsigned long long
 */

typedef unsigned long long ull; // Viết tắt long long là ll

/* CÁCH 1:
 | - Cộng hai chữ số cuối cùng riêng
 | - Cộng a/10 với b/10 rồi thêm chữ số cuối cùng
 | -> a/10 + b/10 không vượt quá 2 * 10^18, nằm trong khoảng long long
 | - a, b nằm trong khoảng unsigned long long
 */
void sum(ull a, ull b)
{
    // Cộng chữ số hàng đơn vị
    ull c = (a % 10) + (b % 10);

    // Cộng phần còn lại
    ull d = (a / 10) + (b / 10) + (c / 10); // (c / 10) là thành phần nhớ của phép cộng

    if (d > 0)
        cout << d << (c % 10);
    else
        cout << c;
}

/* CÁCH 2:
 | - Đọc a, b theo kiểu string
 | - Cộng từng chữ số và kết quả cũng là kiểu string
 | - Không gây tràn số bất kể khoảng giới hạn của a, b
 */
void sumByString(string a, string b)
{
    string sum = ""; // Biến kết quả ban đầu là xâu ký tự rỗng

    int carry = 0; // Biến nhớ ban đầu bằng 0

    // Phép cộng từ hàng đơn vị: i, j là chỉ số của chữ số hàng đơn vị (do bắt đầu từ 0 nên trừ 1)
    int i = a.size() - 1;
    int j = b.size() - 1;

    // Phép cộng sẽ kết thúc nếu 1 trong 2 chuỗi kết thúc và không còn biến nhớ
    while (i >= 0 || j >= 0 || carry > 0)
    {
        // Lấy chữ số vị trí thứ i của a
        int a1 = 0;
        if (i >= 0)
            a1 = a[i] - '0'; // Chuyển ký tự thành số

        // Lấy chữ số vị trí thứ j của b
        int b1 = 0;
        if (j >= 0)
            b1 = b[j] - '0';

        // Cộng lại
        int c = a1 + b1 + carry;
        int c1 = c % 10;
        carry = c / 10;

        sum += to_string(c1);

        i--;
        j--;
    }

    reverse(sum.begin(), sum.end());

    cout << sum;
}

int main()
{
    ull a, b;
    cin >> a >> b;
    sum(a, b);

    // string a, b;
    // cin >> a >> b;
    // sumByString(a, b);
}