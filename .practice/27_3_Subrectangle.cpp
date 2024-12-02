#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/* Ý TƯỞNG: Cách 3 - QUY HOẠCH ĐỘNG
 | - Coi ma trận như một biểu đồ cột, ta sẽ mở rộng dần các hàng từ trên xuống dưới.
 | - Xét bài toán tìm hình chữ nhật lớn nhất trong 1 biểu đồ cột:
 | - Ví dụ: [2, 1, 5, 6, 2, 3] là một biểu đồ cột. Các bước thuật toán:
 |   1. Khởi tạo ngăn xếp rỗng và thêm cột chiều cao 0 vào cuối.
 |   2. Duyệt qua các cột từ trái sang phải:
 |      + Với mỗi cột, nếu ngăn xếp rỗng hoặc chiều cao của cột ở đỉnh ngăn xếp <= chiều cao cột hiện tại:
 |      [ Nghĩa là cột ở đỉnh ngăn xếp có thể mở rộng sang phải đến cột hiện tại ]
 |      > Đẩy CHỈ SỐ của cột hiện tại vào ngăn xếp.
 |      + Nếu chiều cao của cột ở đỉnh ngăn xếp > chiều cao cột hiện tại:
 |      [ Nghĩa là cột ở đỉnh ngăn xếp không thể mở rộng sang phải đến cột hiện tại ]
 |      > Lấy chỉ số của cột ở đỉnh ngăn xếp ra khỏi ngăn xếp.
 |      > Tính diện tích hình chữ nhật lớn nhất với cột.
 */

int n, m;

// Hàm tìm diện tích hình chữ nhật lớn nhất trong biểu đồ cột (truyền tham chiếu cho nhanh)
int getMaxArea(vector<int> &heights)
{
    stack<int> s;
    int ans = 0;

    for (int i = 0; i <= m; ++i)
    {
        while (!s.empty() && heights[i] < heights[s.top()])
        {
            int h = heights[s.top()];
            s.pop();
            /* Cách tính chiều rộng hình chữ nhật lớn nhất:
             | - s.top() là chỉ số cột gần nhất bên trái mà chiều cao <= h
             | - i là chỉ số cột gần nhất bên phải mà chiều cao <= h
             | > Có thể mở rộng từ s.top() + 1 đến i - 1
             */
            int w = s.empty() ? i : i - s.top() - 1;
            ans = max(ans, h * w);
        }
        s.push(i);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> heights(m + 1, 0);
    int ans = 0;
    int x;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            if (x == 0)
                heights[j] = 0;
            else
                heights[j] += 1;
        }

        ans = max(ans, getMaxArea(heights));
    }

    cout << ans;
}