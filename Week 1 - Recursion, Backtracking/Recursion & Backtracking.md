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

## Thuật toán Quay lui (Backtracking)

<b>Định nghĩa:</b>
