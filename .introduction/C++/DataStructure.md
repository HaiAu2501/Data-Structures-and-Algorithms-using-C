# Cấu trúc dữ liệu trong C++

Cấu trúc dữ liệu là cách thức tổ chức và lưu trữ dữ liệu trong máy tính sao cho có thể sử dụng một cách hiệu quả. Trong C++, thư viện chuẩn (Standard Template Library - STL) cung cấp nhiều cấu trúc dữ liệu mạnh mẽ và linh hoạt giúp bạn dễ dàng quản lý dữ liệu trong các chương trình của mình.

# Các loại cấu trúc dữ liệu trong STL

## Sequence Containers

Đây là các cấu trúc dữ liệu lưu trữ các phần tử theo một thứ tự cụ thể.

* `vector`: Mảng động có khả năng mở rộng kích thước tự động. Truy cập ngẫu nhiên nhanh.
* `deque`: Double-ended queue, cho phép thêm hoặc xóa phần tử ở cả hai đầu.
* `list`: Danh sách liên kết đôi, cho phép chèn và xóa phần tử nhanh chóng ở bất kỳ vị trí nào.
* `forward_list`: Danh sách liên kết đơn, tiết kiệm bộ nhớ hơn list nhưng chỉ hỗ trợ duyệt theo một chiều.
* `array`: Mảng có kích thước cố định, hiệu suất cao khi kích thước đã biết trước.

## Associative Containers

Các cấu trúc dữ liệu này lưu trữ các phần tử theo một thứ tự nhất định và hỗ trợ các thao tác tìm kiếm nhanh.

* `set`: Tập hợp các phần tử duy nhất, sắp xếp theo thứ tự tăng dần.
* `multiset`: Tập hợp cho phép chứa các phần tử trùng lặp.
* `map`: Bảng băm lưu trữ cặp khóa-giá trị, khóa là duy nhất.
* `multimap`: Bảng băm cho phép nhiều cặp khóa-giá trị có cùng khóa.

## Unordered Associative Containers

Sử dụng bảng băm để lưu trữ dữ liệu, cho phép tìm kiếm trung bình rất nhanh.

* `unordered_set`: Tập hợp các phần tử duy nhất, không theo thứ tự cụ thể.
* `unordered_multiset`: Tập hợp cho phép chứa các phần tử trùng lặp.
* `unordered_map`: Bảng băm lưu trữ cặp khóa-giá trị, khóa là duy nhất.
* `unordered_multimap`: Bảng băm cho phép nhiều cặp khóa-giá trị có cùng khóa.

## Container Adaptors

Chúng không phải là containers độc lập mà là các lớp xây dựng dựa trên các containers khác để cung cấp giao diện cụ thể.

* `stack`: Cấu trúc dữ liệu ngăn xếp (LIFO - Last In First Out).
* `queue`: Cấu trúc dữ liệu hàng đợi (FIFO - First In First Out).
* `priority_queue`: Hàng đợi ưu tiên, phần tử có độ ưu tiên cao nhất được truy cập trước.