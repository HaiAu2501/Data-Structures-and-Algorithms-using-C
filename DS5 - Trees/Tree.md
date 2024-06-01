# Tree

Cây (Tree) là một dữ liệu trừu tượng lưu trữ các phần tử theo cách phân cấp. Ngoại trừ phần tử đứng đầu, mỗi phần tử trong cây đều có một phần tử cha và không có hoặc có một hoặc nhiều phần tử con.

## Các thành phần cơ bản

- **Nút (Node)** là đơn vị cơ bản của cây, mỗi nút lưu trữ một phần tử dữ liệu.
  - **Gốc (Root)** là nút đầu tiên và duy nhất không có nút cha.
  - **Lá (Leaf)** là nút không có nút con, còn gọi là **nút ngoài (External Node)**.
  - **Nút trong (Internal Node)** là nút có một hoặc nhiều con.
  - Các nút được gọi là **anh chị em (sibling)** nếu chúng có cùng cha.
- Cây  có thể được biểu diễn dưới dạng một đồ thị vô hướng, với mỗi đỉnh là một nút, hai nút có cạnh nếu chúng có quan hệ cha - con.

## Các kiểu cây

- **Cây nhị phân (Binary Tree):** Mỗi nút có tối đa hai nút con, được gọi là con trái và con phải.
  - **Cây nhị phân đầy đủ (Full Binary Tree)** là cây trong đó mỗi nút có hoặc 0 hoặc 2 nút con.
  - **Cây nhị phân hoàn hảo (Perfect Binary Tree)** là cây nhị phân trong đó tất cả các nút bên trong đều có hai nút con và tất cả các lá đều có cùng độ sâu. Cây nhị phân hoàn hảo cũng là cây nhị phân đầy đủ.
  - **Cây tìm kiếm nhị phân (Binary Search Tree - BST)** là cây nhị phân mà nút con bên trái nhỏ hơn hoặc bằng nút cha, và nút con bên phải lớn hơn nút cha.
  - **Cây AVL (AVL Tree)** hay cây nhị phân cân bằng, trong đó độ cao của hai cây con của mỗi nút không chênh lệch quá 1.
