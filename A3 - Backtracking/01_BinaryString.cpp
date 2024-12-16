#include <bits/stdc++.h>

using namespace std;

// In ra các xâu nhị phân có độ dài n theo thứ tự từ điển

int n;
vector<int> a;

void PRINT()
{
    for (int &x : a)
        cout << x;
    cout << '\n';
}

void TRY(int k)
{
    if (k == n - 1)
    {
        PRINT();
        return;
    }
    a[k] = 0;
    TRY(k + 1);
    a[k] = 1;
    TRY(k + 1);
}

int main()
{
    cin >> n;
    a.resize(n);
    TRY(0);
}
