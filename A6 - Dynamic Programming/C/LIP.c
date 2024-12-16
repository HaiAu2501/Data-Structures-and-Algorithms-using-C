#include <stdio.h>

// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

// ✏️ ĐỀ BÀI: Cho ma trận m x n. Tìm đường đi tăng dài nhất trong ma trận.
// Một đường đi trong ma trận là một dãy các ô kề nhau theo chiều ngang hoặc chiều dọc.
// Một đường đi tăng là một đường đi mà giá trị của ô tiếp theo lớn hơn giá trị của ô trước đó.

// ❇️ THAM SỐ:
// - Đầu vào: m, n (1 ≤ m, n ≤ 200).
// - Đầu ra: đường đi tăng dài nhất trong ma trận.

// 📌 THUẬT TOÁN: DFS