#include <iostream>
#include <vector>

using namespace std;

/* ĐỀ BÀI: Cho dãy n số nguyên a[1..n]. Tìm GTLN của a[i]*a[j]*a[k]*a[l]*a[m] với 1 ≤ i < j < k < l < m ≤ n. */

/* Ý TƯỞNG:
 | - Nếu dãy a chứa toàn số âm thì GTLN của tích trên là tích của 5 phần tử lớn nhất.
 | - Nếu dãy a chứa số dương thí sort
 */