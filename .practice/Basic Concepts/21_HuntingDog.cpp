#include <iostream>
#include <algorithm>

using namespace std;

/* ĐỀ BÀI: Một người nông dân có n con chó săn.
 | - Mỗi con chó có 3 thông số: cân nặng, chỉ số thông minh, giá bán.
 | - Người mua muốn những chú chó thỏa mãn: nếu chó A có cân nặng >= chó B thì chó A phải thông minh >= chó B.
 | - Tìm giá bán lớn nhất mà người nông dân có thể mua được.
 */

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 10^4) - số con chó.
 | - n dòng tiếp theo, mỗi dòng chứa 3 số nguyên w, s, p (1 ≤ w, s, p ≤ 10^9) - cân nặng, chỉ số thông minh, giá bán của con chó.
 */

/* ĐẦU RA: Giá bán lớn nhất mà người nông dân có thể bán được.
 */

/* Ý TƯỞNG: Quy hoạch động
 | - Gọi f[i] là giá bán lớn nhất mà người nông dân có thể bán được với i con chó.
 | - Sắp xếp các con chó theo cân nặng tăng dần.
 | - f[i] = max(f[j] + p[i]) với j < i và s[j] <= s[i] (vì w[j] <= w[i]).
 */

#define MAX 10010

struct Dog
{
    int w, s, p;
    bool operator<(const Dog &d) const
    {
        return w < d.w;
    }
};

int n;
Dog dogs[MAX];
int f[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> dogs[i].w >> dogs[i].s >> dogs[i].p;

    sort(dogs, dogs + n);

    for (int i = 0; i < n; i++)
    {
        f[i] = dogs[i].p;
        for (int j = 0; j < i; j++)
            if (dogs[j].s <= dogs[i].s)
                f[i] = max(f[i], f[j] + dogs[i].p);
    }

    cout << *max_element(f, f + n);
}