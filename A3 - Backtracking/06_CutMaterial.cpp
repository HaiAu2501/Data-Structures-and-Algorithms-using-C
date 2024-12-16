#include <bits/stdc++.h>

using namespace std;

// Xem xem 1 bảng ô vuông (H, W) có cắt được thành n hcn (h1, w1)..(hn, wn) không?

#define MAX 15

int H, W, n, h[MAX], w[MAX];

bool used[MAX][MAX], found;

bool CHECK(int x, int y, int hh, int ww)
{
    if (x + hh > H || y + ww > W)
        return false;
    for (int i = x; i < x + hh; i++)
        for (int j = y; j < y + ww; j++)
            if (used[i][j])
                return false;
    return true;
}

void MARK(int x, int y, int hh, int ww, bool val)
{
    for (int i = x; i < x + hh; i++)
        for (int j = y; j < y + ww; j++)
            used[i][j] = val;
}

void TRY(int k)
{
    if (found)
        return;
    if (k > n)
    {
        found = true;
        return;
    }
    for (int x = 0; x < H; x++)
        for (int y = 0; y < W; y++)
        {
            if (CHECK(x, y, h[k], w[k]))
            {
                MARK(x, y, h[k], w[k], true);
                TRY(k + 1);
                MARK(x, y, h[k], w[k], false);
            }

            if (CHECK(x, y, w[k], h[k]))
            {
                MARK(x, y, w[k], h[k], true);
                TRY(k + 1);
                MARK(x, y, w[k], h[k], false);
            }
        }
}

int main()
{
    cin >> H >> W >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i] >> w[i];
    TRY(1);
    if (found)
        cout << 1;
    else
        cout << 0;
}