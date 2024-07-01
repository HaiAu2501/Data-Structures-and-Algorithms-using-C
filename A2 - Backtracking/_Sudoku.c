#include <stdio.h>
#include <stdlib.h>

// Đề bài: Giải bảng Sudoku 9x9. Một lời giải cho bảng Sudoku phải thỏa mãn:
// - Mỗi hàng chỉ chứa các số từ 1 đến 9 mà không trùng lặp.
// - Mỗi cột chỉ chứa các số từ 1 đến 9 mà không trùng lặp.
// - Mỗi ô vuông 3x3 chỉ chứa các số từ 1 đến 9 mà không trùng lặp.
// Đầu vào: Bảng Sudoku 9x9, trong đó 0 biểu diễn ô trống.
// Đầu ra: Tất cả các lời giải cho bảng Sudoku.

/* SỬ DỤNG QUAY LUI */

int board[9][9];

// Kiểm tra xem có thể đặt số num vào ô (row, col) hay không
int isValid(int row, int col, int num)
{
    // Kiểm tra hàng
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return 0;
    }

    // Kiểm tra cột
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return 0;
    }

    // Kiểm tra ô vuông 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == num)
                return 0;
        }
    }

    return 1;
}

// Giải bảng Sudoku
void try(int row, int col)
{
    if (row == 9)
    {
        // In ra bảng Sudoku
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }

    if (board[row][col] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isValid(row, col, num))
            {
                board[row][col] = num;
                if (col == 8)
                    try(row + 1, 0);
                else
                    try(row, col + 1);
                board[row][col] = 0;
            }
        }
    }
    else
    {
        if (col == 8)
            try(row + 1, 0);
        else
            try(row, col + 1);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            scanf("%d", &board[i][j]);
    }

    try(0, 0);

    return 0;
}

/* Bảng để test:
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
*/
// -> OK đúng. Bảng này chỉ có 1 lời giải duy nhất.