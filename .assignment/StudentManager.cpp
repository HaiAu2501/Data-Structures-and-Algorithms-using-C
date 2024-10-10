#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Hàm để loại bỏ khoảng trắng ở đầu và cuối chuỗi
char *trim(char *str)
{
    // Loại bỏ khoảng trắng ở đầu
    while (isspace(*str))
        str++;
    // Nếu toàn bộ chuỗi là khoảng trắng
    if (*str == 0)
        return str;
    // Loại bỏ khoảng trắng ở cuối
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end))
        end--;
    *(end + 1) = '\0';
    return str;
}

// Hàm để lấy từ cuối cùng trong họ tên
const char *getLastWord(const char *fullName)
{
    const char *lastSpace = strrchr(fullName, ' ');
    if (lastSpace != nullptr)
    {
        return lastSpace + 1;
    }
    return fullName;
}

// Hàm so sánh hai sinh viên dựa trên từ cuối cùng của họ tên
int compareStudents(const void *a, const void *b)
{
    const char *name1 = *(const char **)a;
    const char *name2 = *(const char **)b;
    const char *lastWord1 = getLastWord(name1);
    const char *lastWord2 = getLastWord(name2);
    return strcmp(lastWord1, lastWord2);
}

int main()
{
    // Danh sách sinh viên
    char **students = nullptr;
    int count = 0;    // Số lượng sinh viên
    int capacity = 0; // Số lượng tối đa hiện tại

    while (true)
    {
        // Hiển thị menu
        cout << "\n--- Student Management Program ---\n";
        cout << "1. Enter student list\n";
        cout << "2. Print sorted student list\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";

        int option;
        cin >> option;
        cin.ignore(); // Bỏ ký tự xuống dòng sau khi nhập số

        if (option == 1)
        {
            // Chức năng nhập danh sách sinh viên
            cout << "Enter student full names (end with #):\n";
            while (true)
            {
                cout << "Full Name: ";
                char buffer[1000];
                cin.getline(buffer, 1000);
                // Loại bỏ khoảng trắng ở đầu và cuối
                char *name = trim(buffer);
                // Kiểm tra dấu kết thúc
                if (strcmp(name, "#") == 0)
                    break;
                // Kiểm tra tính duy nhất bằng tìm kiếm nhị phân nếu danh sách đã sắp xếp
                bool unique = true;
                if (count > 0)
                {
                    int left = 0, right = count - 1;
                    while (left <= right)
                    {
                        int mid = left + (right - left) / 2;
                        int cmp = strcmp(students[mid], name);
                        if (cmp == 0)
                        {
                            unique = false;
                            break;
                        }
                        else if (cmp < 0)
                        {
                            left = mid + 1;
                        }
                        else
                        {
                            right = mid - 1;
                        }
                    }
                }
                if (!unique)
                {
                    cout << "Name already exists. Please enter a different name.\n";
                    continue;
                }
                // Cấp phát bộ nhớ cho họ tên
                int len = strlen(name);
                char *newName = new char[len + 1];
                strcpy(newName, name);
                // Khi count đạt đến capacity, mảng được mở rộng gấp đôi kích thước hiện tại, giảm số lần cấp phát bộ nhớ
                if (count == capacity)
                {
                    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
                    char **temp = new char *[newCapacity];
                    for (int i = 0; i < count; i++)
                    {
                        temp[i] = students[i];
                    }
                    delete[] students;
                    students = temp;
                    capacity = newCapacity;
                }
                // Thêm sinh viên vào danh sách
                students[count++] = newName;
            }
        }
        else if (option == 2)
        {
            if (count == 0)
            {
                cout << "The student list is empty.\n";
                continue;
            }
            // Sắp xếp danh sách sinh viên theo từ cuối cùng bằng qsort
            qsort(students, count, sizeof(char *), compareStudents);
            // In danh sách sinh viên đã sắp xếp
            cout << "\n--- Sorted Student List ---\n";
            for (int i = 0; i < count; i++)
            {
                cout << i + 1 << ". " << students[i] << "\n";
            }
        }
        else if (option == 3)
        {
            // Thoát chương trình
            break;
        }
        else
        {
            cout << "Invalid option. Please try again.\n";
        }
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < count; i++)
    {
        delete[] students[i];
    }
    delete[] students;

    cout << "Program exited.\n";
    return 0;
}
