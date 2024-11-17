# Mã giả các thuật toán duyệt đồ thị

## Tìm kiếm theo chiều sâu (DFS)

```
ALGORITHM DFS(Graph, startNode)
    ĐẦU VÀO: 
        Graph - một đồ thị
        startNode - đỉnh bắt đầu duyệt

    KHỞI TẠO:
        S - một ngăn xếp rỗng
        visited[] - mảng đánh dấu các đỉnh đã duyệt, false
        S.push(startNode)
        visited[startNode] = true

    WHILE (S khác rỗng) DO
        currentNode = S.pop() // Node ở đỉnh của S
        process(currentNode)  // Xử lý Node này

        FOR (mỗi đỉnh neighbor kề currentNode) DO
            IF visited[neighbor] = FALSE THEN
                S.push(neighbor) // Thêm vào đỉnh S
                visited[neighbor] = true
            END IF
        END FOR
    END WHILE
END ALGORITHM
```

## Tìm kiếm theo chiều rộng (BFS)

```
ALGORITHM BFS(Graph, startNode)
    ĐẦU VÀO: 
        Graph - một đồ thị
        startNode - đỉnh bắt đầu duyệt

    KHỞI TẠO:
        Q - một hàng đợi rỗng
        visited[] - mảng đánh dấu các đỉnh đã duyệt, false
        Q.push(startNode)
        visited[startNode] = true

    WHILE (Q khác rỗng) DO
        currentNode = Q.pop() // Node đầu tiên trong Q
        process(currentNode)  // Xử lý Node này

        FOR (mỗi đỉnh neighbor kề currentNode) DO
            IF visited[neighbor] = FALSE THEN
                Q.push(neightbor) // Thêm vào cuối Q
                visited[neighbor] = true
            END IF
        END FOR
    END WHILE
END ALGORITHM
```