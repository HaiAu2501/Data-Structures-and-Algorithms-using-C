#include <stdio.h>
#include <string.h>

// Đề bài: Cộng hai số nguyên a, b mà 0 <= a, b <= 10^19
/* Nhận xét:
 * Kiểu long long chứa được các số khoảng -9 * 10^18 đến 9 * 10^18
 * Tổng hai số có thể vượt quá giới hạn của kiểu long long, unsigned long long
 * => Cộng hai số bằng cách chuyển số nguyên thành chuỗi
 * => Cộng từng cặp ký tự từ phải sang trái
 */

// Hàm cộng hai số nguyên dương lớn
void sumBigNumber(char a[], char b[], char res[])
{
    // Khởi tạo biến nhớ ban đầu bằng 0
    int remember = 0;

    // Đảo chuỗi a, b để cộng từ phải sang trái
    strrev(a);
    strrev(b);

    int lenA = strlen(a);
    int lenB = strlen(b);
    int len = lenA > lenB ? lenA : lenB; // Độ dài chuỗi lớn hơn

    // Lặp qua từng cặp ký tự từ phải sang trái
    for (int i = 0; i < len; i++)
    {
        // Lấy ký tự thứ i của a, b và chuyển sang kiểu số
        int digitA = (i < lenA) ? a[i] - '0' : 0; // a[i] - '0' để chuyển ký tự số sang số nguyên
        int digitB = (i < lenB) ? b[i] - '0' : 0;

        // Tính tổng của hai ký tự và biến nhớ
        int sum = digitA + digitB + remember;

        // Nếu tổng lớn hơn 9 thì lưu vào biến nhớ
        remember = sum / 10;

        // Lưu kết quả vào mảng res
        res[i] = sum % 10 + '0';
    }

    // Nếu đến cuối chuỗi mà vẫn còn biến nhớ thì lưu vào kết quả
    if (remember > 0)
    {
        res[len] = remember + '0';
        len++;
    }

    res[len] = '\0';
    strrev(res);
}

// Nâng cao: Cộng hai số nguyên a, b mà - 10^19 <= a, b <= 10^19
/* Nhận xét:
 * Cách xử lý trường hợp âm:
 * - Nếu cả hai số đều âm thì cộng bình thường và thêm dấu trừ ở đầu kết quả
 * - Nếu một số âm một số dương thì trừ số có giá trị lớn hơn cho số có giá trị nhỏ hơn
 */

// Hàm trừ hai số nguyên dương lớn
void subBigNumber(char a[], char b[], char res[])
{
    int isNegative = 0; // Biến kiểm tra kết quả âm hay dương
    if (strcmp(a, b) < 0)
    {
        char *temp = a;
        a = b;
        b = temp;
        isNegative = 1;
    }

    // Khởi tạo biến nhớ ban đầu bằng 0
    int remember = 0;

    // Đảo chuỗi a, b để cộng từ phải sang trái
    strrev(a);
    strrev(b);

    int lenA = strlen(a);
    int lenB = strlen(b);
    int len = lenA > lenB ? lenA : lenB; // Độ dài chuỗi lớn hơn

    // Lặp qua từng cặp ký tự từ phải sang trái
    for (int i = 0; i < len; i++)
    {
        // Lấy ký tự thứ i của a, b và chuyển sang kiểu số
        int digitA = (i < lenA) ? a[i] - '0' : 0; // a[i] - '0' để chuyển ký tự số sang số nguyên
        int digitB = (i < lenB) ? b[i] - '0' : 0;

        // Tính tổng của hai ký tự và biến nhớ
        int sub = digitA - digitB - remember;

        if (sub < 0)
        {
            sub += 10;
            remember = 1;
        }
        else
        {
            remember = 0;
        }

        res[i] = sub + '0';
    }

    // Remove leading zeros
    int i = len - 1;
    while (i > 0 && res[i] == '0')
    {
        i--;
    }
    res[i + 1] = '\0';

    strrev(res);

    if (isNegative)
    {
        memmove(res + 1, res, strlen(res) + 1);
        res[0] = '-';
    }
}

void sumBigInteger(char a[], char b[], char res[])
{
    // Nếu cả hai số đều âm thì cộng bình thường và thêm dấu trừ ở đầu kết quả
    if (a[0] == '-' && b[0] == '-')
    {
        sumBigNumber(a + 1, b + 1, res);
        strrev(res);
        strcat(res, "-");
        strrev(res);
        return;
    }

    // Nếu một số âm một số dương thì trừ số có giá trị lớn hơn cho số có giá trị nhỏ hơn
    else if (a[0] == '-')
    {
        subBigNumber(b, a + 1, res);
        return;
    }

    else if (b[0] == '-')
    {
        subBigNumber(a, b + 1, res);
        return;
    }

    else
        sumBigNumber(a, b, res);
}

int main()
{
    char a[100], b[100], res[100];
    scanf("%s%s", a, b);

    sumBigInteger(a, b, res);
    printf("%s\n", res);

    return 0;
}