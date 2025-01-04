#include <bits/stdc++.h>

using namespace std;

const int maxL = 101;
const int maxW = 101;
const int maxH = 101;

long long dp[maxL][maxW][maxH];
vector<array<int, 3>> bricks;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int W, L, H, N;
        cin >> W >> L >> H >> N;
        bricks.resize(N);
        for (int i = 0; i < N; i++)
            cin >> bricks[i][0] >> bricks[i][1] >> bricks[i][2];

        memset(dp, 0, sizeof(dp));

        for (int w = 1; w <= W; w++)
            for (int l = 1; l <= L; l++)
                for (int h = 1; h <= H; h++)
                {
                    long long best = 0;

                    // TH 1: Cắt dọc theo chiều w
                    for (int cut = 1; cut < w; cut++)
                        best = max(best, dp[cut][l][h] + dp[w - cut][l][h]);

                    // TH 2: Cắt dọc theo chiều l
                    for (int cut = 1; cut < l; cut++)
                        best = max(best, dp[w][cut][h] + dp[w][l - cut][h]);

                    // TH 3: Cắt dọc theo chiều h
                    for (int cut = 1; cut < h; cut++)
                        best = max(best, dp[w][l][cut] + dp[w][l][h - cut]);

                    // TH 4: Kiểm tra xem (w, l, h) có trùng với kích thước của brick nào không
                    for (auto &b : bricks)
                    {
                        int bw = b[0], bl = b[1], bh = b[2];
                        if ((bw == w && bl == l && bh == h) ||
                            (bw == w && bl == h && bh == l) ||
                            (bw == l && bl == w && bh == h) ||
                            (bw == l && bl == h && bh == w) ||
                            (bw == h && bl == w && bh == l) ||
                            (bw == h && bl == l && bh == w))
                            best = max(best, (long long)bw * bl * bh);
                    }

                    dp[w][l][h] = best;
                }

        long long waste = (long long)W * L * H - dp[W][L][H];
        cout << waste << "\n";
    }
}