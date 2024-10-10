#include <iostream>
#include <vector>

using namespace std;

int n;

// ĐỀ BÀI: Sinh dãy nhị phân độ dài n theo thứ tự từ điển.

void generateBinarySeq(int i, vector<int> a)
{
    if (i == n)
    {
        for (int &x : a)
            cout << x;
        cout << endl;
        return;
    }

    a[i] = 0;
    generateBinarySeq(i + 1, a);
    a[i] = 1;
    generateBinarySeq(i + 1, a);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> a(n);

    generateBinarySeq(0, a);

    return 0;
}