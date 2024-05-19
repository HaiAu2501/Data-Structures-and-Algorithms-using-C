# Branch and Bound & Greedy Algorithm

## Thuật toán nhánh cận (Branch and Bound)

Thuật toán Nhánh cận (Branch and Bound) là một kỹ thuật tìm kiếm và tối ưu hóa để giải quyết các bài toán tổ hợp và các bài toán tối ưu hóa khó. Thuật toán này kết hợp hai khái niệm chính: "nhánh" (branching) và "cận" (bounding). Nhánh cận giúp cắt giảm không gian tìm kiếm bằng cách sử dụng các ràng buộc và ước lượng để tránh phải xem xét tất cả các khả năng.

1. Nhánh (Branching):
Quá trình phân chia vấn đề lớn thành các vấn đề con nhỏ hơn (nhánh). Điều này giống như việc tạo cây tìm kiếm, trong đó mỗi nút đại diện cho một trạng thái của bài toán và mỗi cạnh đại diện cho một bước chuyển từ trạng thái này sang trạng thái khác.

2. Cận (Bounding):
Sử dụng các giới hạn trên và dưới (cận) để đánh giá xem một nhánh có thể chứa giải pháp tối ưu hay không. Nếu nhánh đó không thể cải thiện được giải pháp hiện tại, nó sẽ bị loại bỏ (cắt tỉa).

Quy trình tổng quát:

- Khởi tạo: Bắt đầu với trạng thái ban đầu của bài toán và thiết lập cận ban đầu (có thể là giá trị tối ưu tạm thời).
- Nhánh (Branch): Phân chia bài toán hiện tại thành các bài toán con (tạo các nhánh).
- Cận (Bound): Đánh giá các nhánh bằng cách sử dụng cận. Nếu cận của nhánh tốt hơn giá trị tối ưu tạm thời, tiếp tục tìm kiếm trên nhánh đó. Ngược lại, bỏ qua nhánh đó.
- Cập nhật giá trị tối ưu tạm thời: Nếu tìm thấy giải pháp tốt hơn, cập nhật giá trị tối ưu.
- Lặp lại: Tiếp tục quá trình cho đến khi không còn nhánh nào để xem xét.

## Thuật toán Tham lam (Greedy Algorithm)

Thuật toán tham lam (Greedy Algorithm) là một phương pháp giải quyết bài toán dựa trên việc lựa chọn các bước đi tối ưu cục bộ với hy vọng rằng chúng sẽ dẫn đến kết quả tối ưu toàn cục. Thuật toán tham lam thường được sử dụng cho các bài toán mà lựa chọn tối ưu tại mỗi bước sẽ dẫn đến giải pháp tối ưu cuối cùng.

Các bước cơ bản của thuật toán tham lam:

- Bắt đầu từ một trạng thái ban đầu.
- Lặp lại quá trình lựa chọn tham lam cho đến khi đạt đến trạng thái cuối cùng hoặc không còn lựa chọn khả thi nào.
- Kết thúc với giải pháp tạm thời hoặc giải pháp tối ưu (nếu tồn tại).
