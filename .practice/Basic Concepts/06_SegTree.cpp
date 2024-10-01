#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* ĐỀ BÀI: Cho dãy a[1..n]. Thực hiện 1 dãy các thao tác:
 | - update i v: gán a[i] = v
 | - get-max i j: trả về giá trị lớn nhất trong dãy a[i..j]
 */

/* ĐẦU VÀO:
 | - Dòng 1 chứa số nguyên dương n (1 <= n <= 100000)
 | - Dòng 2 chứa n phần tử của dãy a là a[1..n] (1 <= a[i] <= 10000)
 | - Dòng 3 chứa số nguyên dương m là số thao tác (1 <= m <= 100000)
 | - m dòng tiếp theo là các thao tác kể trên
 */

/* ĐẦU RA:
 | - Mỗi dòng là kết quả của truy vấn get-max tương ứng
 */

/* CẤU TRÚC DỮ LIỆU SEGMENT TREE:
 | - Segment Tree là 1 cây nhị phân đầy đủ (mỗi nút hoặc là lá hoặc có đúng 2 con)
 | - Mỗi nút quản lý một đoạn trên dãy số:
 |   + Nút gốc lưu thông tin của đoạn a[1..n]
 |   + Nếu một nút lưu trữ thông tin của đoạn a[i..j] thì con trái, con phải lưu trữ thông tin của a[i..(i+j)/2], a[(i+j)/2+1..j]
 | - Có thể cài đặt Segment Tree bằng mảng 1 chiều, node thứ i có con trái là (2i) và con phải là (2i+1)
 | - Kích thước mảng khi đó không vượt qua 4n
 */

int n, m;
vector<int> a;       // Dãy số bài cho
vector<int> segTree; // Mảng để xây dựng Segment Tree từ dãy a

/* Hàm xây dựng Segment Tree:
 | - node: chỉ số nút hiện tại trong Segment Tree
 | - start: chỉ số bắt đầu của đoạn trong mảng
 | - end: chỉ số kết thúc của đoạn trong mảng
 */
void buildTree(int node, int start, int end)
{
    if (start == end)
    {
        segTree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(2 * node, start, mid);       // Node con trái quản lý đoạn start..mid
    buildTree(2 * node + 1, mid + 1, end); // Node con phải quản lý đoạn mid+1..end
    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
}

/* Hàm truy vấn GTLN trong đoạn a[L..R]
 | - node: chỉ số node hiện tại trong SegTree
 | - start: chỉ số bắt đầu của đoạn trong mảng
 | - end: chỉ số kết thúc của đoạn trong mảng
 | - L, R: đoạn cần truy vấn; xảy ra 3 khả năng:
 |   + Nếu [start..end] không giao với [L, R]
 |   + Nếu [start..end] nằm hoàn toàn trong [L, R]
 |   + Nếu [start..end] có phần giao với [L, R]
 */
int queryMax(int node, int start, int end, int L, int R)
{
    // Trường hợp đoạn hiện tại không giao với [L, R]
    if (R < start || end < L)
    {
        // Trả về giá trị nhỏ nhất để không ảnh hưởng đến max
        return INT32_MIN;
    }
    // Trường hợp đoạn hiện tại nằm hoàn toàn trong [L, R]
    if (L <= start && end <= R)
    {
        return segTree[node];
    }
    // Trường hợp đoạn hiện tại có phần giao với [L, R]
    int mid = (start + end) / 2;
    int p1 = queryMax(2 * node, start, mid, L, R);
    int p2 = queryMax(2 * node + 1, mid + 1, end, L, R);
    return max(p1, p2);
}

/* Hàm cập nhật giá trị tại vị trí idx thành value:
 */
void updateTree(int node, int start, int end, int idx, int value)
{
    if (start == end)
    {
        // Cập nhật giá trị tại nút lá
        segTree[node] = value;
        a[idx] = value;
    }
    else
    {
        int mid = (start + end) / 2;
        if (idx <= mid)
        {
            // Cập nhật cây con bên trái
            updateTree(2 * node, start, mid, idx, value);
        }
        else
        {
            // Cập nhật cây con bên phải
            updateTree(2 * node + 1, mid + 1, end, idx, value);
        }
        // Cập nhật giá trị của nút hiện tại sau khi cập nhật cây con
        segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n + 1);
    segTree.resize(4 * (n + 1));

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    buildTree(1, 1, n);

    cin >> m;

    while (m--)
    {
        string q;
        cin >> q;
        if (q == "update")
        {
            int idx, value;
            cin >> idx >> value;
            updateTree(1, 1, n, idx, value);
        }
        if (q == "get-max")
        {
            int L, R;
            cin >> L >> R;
            cout << queryMax(1, 1, n, L, R) << endl;
        }
    }
}