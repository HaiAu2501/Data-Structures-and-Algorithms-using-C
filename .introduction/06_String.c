#include <stdio.h>
#include <string.h> // Thư viện hỗ trợ xử lý chuỗi

int main()
{
    // Một chuỗi là một mảng các ký tự kết thúc bởi ký tự null '\0'
    char s[100];       // Khai báo một mảng s gồm 100 ký tự
    scanf("%s", s);    // Đọc một chuỗi từ bàn phím, %s là định dạng đọc chuỗi
    printf("%s\n", s); // In ra chuỗi vừa đọc

    // Độ dài của chuỗi
    int len = strlen(s); // Hàm strlen trả về độ dài của chuỗi
    printf("%d\n", len);

    // Cộng chuỗi
    char s1[100], s2[100];
    scanf("%s%s", s1, s2); // Đọc hai chuỗi từ bàn phím
    strcat(s1, s2);        // Hàm strcat dùng để nối chuỗi s2 vào sau chuỗi s1, kết quả được lưu trong s1
    printf("%s\n", s1);    // In ra chuỗi sau khi nối
}