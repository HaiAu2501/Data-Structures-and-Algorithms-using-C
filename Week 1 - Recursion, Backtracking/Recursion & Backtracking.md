# Recursion & Backtracking

## Thuật toán Đệ quy (Recursion)

<b>Định nghĩa:</b> Đệ quy là một phương pháp giải quyết vấn đề bằng cách phân chia vấn đề lớn thành các vấn đề nhỏ hơn có cấu trúc tương tự. Trong lập trình, đệ quy là quá trình mà một hàm tự gọi lại chính nó.

Cấu trúc tổng quát của Đệ quy:

- Điều kiện dừng hay Bước cơ sở (Base Case): Đây là điều kiện để kết thúc đệ quy. Khi điều kiện này được thỏa mãn, hàm đệ quy sẽ dừng gọi lại chính nó.
- Lời gọi đệ quy (Recursive Call): Nếu điều kiện dừng không thỏa mãn, hàm sẽ tự gọi lại chính nó với các giá trị tham số được thay đổi sao cho nó dần dần tiến đến điều kiện dừng.

```pseudocode
function recursive_function(parameters):
    if base_condition:
        return base_case_value
    else:
        return recursive_function(modified_parameters)
```

Danh sách bài toán:

- [Sắp xếp nhanh](QuickSort.c)
- [Tính số hạng thứ $n$ của dãy Fibonacci](Fibonacci.c)
- [Tính hệ số nhị thức $C^k_n$](Binomial.c)
- [Tính lũy thừa $a^n$](BinaryExponent.c)
- [Thuật toán Karatsuba nhân hai đa thức](PolynomialMultiply.c)

## Thuật toán Quay lui (Backtracking)

<b>Định nghĩa:</b> Quay lui là một kỹ thuật tìm kiếm để giải quyết các vấn đề mà các quyết định được thực hiện từng bước và có thể quay lui lại để thử các quyết định khác nếu giải pháp hiện tại không thành công.

Cấu trúc tổng quát của Quay lui:

- Điều kiện thành công (Success Condition): Điều kiện mà giải pháp đã tìm ra là đúng và có thể kết thúc quá trình quay lui.
- Thử và kiểm tra (Try and Check): Thử một giá trị cụ thể cho một biến và kiểm tra xem nó có hợp lệ không.
- Quay lui (Backtrack): Nếu giá trị thử không hợp lệ hoặc không dẫn đến giải pháp, hủy bỏ giá trị đó và thử giá trị tiếp theo.
- Điều kiện dừng (Base Case): Kết thúc quá trình khi đã kiểm tra hết tất cả các giá trị có thể.

```pseudocode
function backtracking_function(parameters):
    if success_condition:
        return true
    
    for each value in possible_values:
        if is_valid(value):
            update_structure(value)
            if backtracking_function(modified_parameters):
                return true
            undo_update(value)
    
    return false
```

Danh sách bài toán:

- [Liệt kê dãy nhị phân](BinaryGen.c)
- [Liệt dãy hoán vị](PermutationGen.c)
- [Liệt kê tập con](Subsets.c)
- [Liệt kê các cách điền toán tử](Operators.c)
- [Sắp xếp quân hậu](QueenArrange.c)
- [Bài toán mã đi tuần](KnightTour.c)
- [Thay thế dấu ngoặc](ReplaceBracket.c)
- [Điền toán tử giữa các số](Operators.c)
- [Giải Sudoku](SudokuSolver.c)

## Sự khác nhau giữa Đệ quy và Quay lui

- Cách tiếp cận:
  - Đệ quy: Chia vấn đề lớn thành các vấn đề nhỏ hơn có cấu trúc tương tự và giải quyết chúng.
  - Quay lui: Thử từng bước một, nếu bước đó không dẫn đến giải pháp, thì quay lui và thử bước khác.

- Điều kiện dừng:
  - Đệ quy: Điều kiện dừng là khi đạt đến một trường hợp cơ sở.
  - Quay lui: Điều kiện dừng là khi tìm thấy một giải pháp hợp lệ hoặc không còn lựa chọn nào khác để thử.

- Quản lý trạng thái:
  - Đệ quy: Mỗi lần gọi hàm đệ quy sẽ lưu trạng thái hiện tại trên ngăn xếp gọi hàm.
  - Quay lui: Mỗi bước thử sẽ kiểm tra và cập nhật trạng thái, nếu không thành công sẽ quay lại trạng thái trước đó.

## Định lý Thợ

Định lý Thợ (Master Theorem) là một công cụ mạnh mẽ trong lý thuyết độ phức tạp tính toán, dùng để phân tích thời gian chạy của các thuật toán đệ quy. Định lý này đặc biệt hữu ích cho các bài toán đệ quy dạng:
$$
T(n) = a\times T\left(\frac{n}{b}\right) + f(n)
$$

Trong đó:

- $a \geq 1$ và $b> 1$ là các hằng số.
- $f(n)$ là một hàm cho trước.

Các trường hợp:

- Nếu $f(n) = \mathcal{O}(n^{\log_b a - \varepsilon})$ với $\epsilon > 0$ thì $T(n) = \Theta(n^{\log_b a})$.
- Nếu $f(n) = \Theta(n^{\log_b a})$ thì $T(n) = \Theta(n^{\log_b a} \log n)$.
- Nếu $f(n) = \Omega(n^{\log_b a+ \varepsilon})$ với $\varepsilon >0$ và $a f\left(\frac{n}{b}\right) \leq cf(n)$ với $c<1$ và $n$ đủ lớn thì $T(n)=\Theta(f(n))$.
