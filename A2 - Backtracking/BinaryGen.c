#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Hàm đệ quy để tạo và in ra các chuỗi nhị phân
void generateBinary(int n, char arr[], int i)
{
    if (i == n)
    {
        // Khi độ dài chuỗi đạt n, in ra chuỗi và trở về
        arr[i] = '\0'; // Đánh dấu kết thúc chuỗi
        printf("%s\n", arr);
        return;
    }

    // Gán giá trị '0' vào vị trí thứ i và đệ quy tiếp tục
    arr[i] = '0';
    generateBinary(n, arr, i + 1);

    // Gán giá trị '1' vào vị trí thứ i và đệ quy tiếp tục
    arr[i] = '1';
    generateBinary(n, arr, i + 1);
}

int main()
{
    int n;
    // Đọc độ dài chuỗi nhị phân từ người dùng
    scanf("%d", &n);

    char arr[MAX_LENGTH];

    // Gọi hàm đệ quy để tạo và in ra các chuỗi nhị phân
    generateBinary(n, arr, 0);

    return 0;
}
