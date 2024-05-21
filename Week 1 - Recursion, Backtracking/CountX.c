#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Thi giữa kỳ CTDL&TT HUST CTTN - KHMT K67
// Đề bài: Cho xâu a chứ một số kí tự 'x', đếm số các dãy m kí tự 'x' liên tiếp trong a.
// Lưu ý: Dãy các 'x' này không chồng lên nhau. Ví dụ: m = 2, a = 'xxx' -> count = 1

int m;
char a[MAX_LENGTH];

// Hàm kiểm tra xem m kí tự liên tiếp từ vị trí i có bằng 'x' không
int isValid(char *a, int i)
{
    for (int j = i; j < i + m; j++)
    {
        if (a[j] != 'x')
            return 0;
    }
    return 1;
}

// Cách 1: Hàm đếm số dãy m kí tự 'x' liên tiếp trong xâu a -> Time complexity: O(n x m)
int countXVer1(char *a)
{
    int count = 0;
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        if (isValid(a, i))
        {
            count++;
            i += m - 1;
        }
    }
    return count;
}

// Cách 2: Đếm bằng cách chia lấy phần nguyên -> Time complexity: O(n)
int countXVer2(char *a)
{
    // Lưu số kí tự 'x' liên tiếp, nếu gặp kí tự khác thì reset về 0
    int count = 0;
    int result = 0;
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'x')
            count++;
        else
        {
            result += count / m;
            count = 0;
        }
    }
    result += count / m;
    return result;
}

int main()
{
    scanf("%d", &m);
    scanf("%s", a);
    printf("%d", countXVer1(a));
    printf("\n%d", countXVer2(a));
    return 0;
}
