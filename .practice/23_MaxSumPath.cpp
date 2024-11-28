#include <iostream>

using namespace std;

/* ĐỀ BÀI: Cho 1 cây nhị phân, mỗi node chứa 1 số nguyên.
 | - Tìm đường đi từ 1 node tới 1 node khác sao cho tổng các số trên đường đi là lớn nhất.
 | - Node xuất phát không nhất thiết phải là node gốc.
 */

/* ĐẦU VÀO:
 | - Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 10^5) - số node của cây.
 | - Dòng thứ hai chứa n số nguyên a1, a2, ..., an (-10^9 ≤ ai ≤ 10^9) - giá trị của các node.
 | (Node i có 2 node con là 2i và 2i + 1, 1 ≤ i ≤ n/2).
 */

/* ĐẦU RA: Tổng lớn nhất của các số trên đường đi từ 1 node tới 1 node khác.
 */
