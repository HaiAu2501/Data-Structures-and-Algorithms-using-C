#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// ĐỀ BÀI: Đếm số nghiệm nguyên dương x[1..n] của phương trình a[1]x[1] + a[2]x[2] + ... + a[n]x[n] = M (*)

/* ĐẦU VÀO:
 | - Dòng thứ nhất là 2 số nguyên dương n và M.
 | - Dòng thứ hai là n số nguyên dương a[1..n].
 */

// ĐẦU RA: Số lượng các bộ số (x[1], x[2],..., x[n]) thỏa mãn phương trình (*).

/* THUẬT TOÁN: Backtracking.
 | - Cấu trúc chung của thuật toán Quay lui xây dựng lời giải.
 | - Cần hàm TRY(k) và CHECK(v, k).
procedure TRY(k)
    for (mỗi giá trị v trong tập các giá trị khả dĩ tại vị trí k) do
        if CHECK(v, k) then
            gán v cho vị trí k
            if (k == n) then
                ghi nhận lời giải
            else
                TRY(k + 1)
            hoàn tác việc gán v cho vị trí k
 */

ll n, M;
vector<ll> a;
vector<ll> x;
ll sum;
ll solution;

bool CHECK(ll v, ll k)
{
    if (sum > M)
        return false;
    return true;
}

void TRY(ll k)
{
    for (ll v = 1; v * a[k] <= M; v++)
    {
        x[k] = v;
        sum += v * a[k];
        if (CHECK(v, k))
        {
            if (k == n && sum == M)
                solution++;
            else
                TRY(k + 1);
        }
        sum -= v * a[k];
    }
}

/* CÓ THỂ KẾT HỢP HÀM TRY + CHECK THÀNH 1 HÀM DUY NHẤT ĐỂ NGẮN GỌN HƠN (vẫn chưa tối ưu và bị TLE)
void TRY(ll k)
{
    for (ll v = 1; sum + v * a[k] <= M; v++)
    {
        x[k] = v;
        sum += v * a[k];
        if (k == n && sum == M)
            solution++;
        else
            TRY(k + 1);
        sum -= v * a[k];
    }
}
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> M;
    a.resize(n + 1);
    x.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    TRY(1);
    cout << solution;
}