#include <iostream>
#include <string>
#include <map>

using namespace std;

// ĐỀ BÀI: Trả lời truy vấn về số điện thoại.

/* ĐẦU VÀO:
 | - Khối đầu tiên gồm các dòng có dạng:
 |   call <from_number> <to_number> <date> <from_time> <end_time>
 | - from_number, to_number là xâu kí tự gồm 10 chữ số
 | - date viết dưới dạng YYYY-MM-DD (năm:tháng:ngày)
 | - from_time, end_time có dạng hh:mm:ss (giờ:phút:giây)
 | - Kết thúc bởi dấu #
 | - Khối thứ 2 gồm các truy vấn:
 |   ?check_phone_number: trả về 1 nếu tất cả số điện thoại hợp lệ
 |   ?number_calls_from <phone_number>: trả về số lượng cuộc gọi từ phone_number
 |   ?number_total_calls: tổng số cuộc gọi trong dữ liệu
 |   ?count_time_calls_from <phone_number>: tổng thời gian cuộc gọi từ phone_number (theo giây)
 */

map<string, int> call_from;
map<string, int> time_count;
int total;
int check = true;

int calculateTime(string &f_time, string &e_time)
{
    int f_h = stoi(f_time.substr(0, 2));
    int f_m = stoi(f_time.substr(3, 2));
    int f_s = stoi(f_time.substr(6, 2));

    int e_h = stoi(e_time.substr(0, 2));
    int e_m = stoi(e_time.substr(3, 2));
    int e_s = stoi(e_time.substr(6, 2));

    return (e_h - f_h) * 3600 + (e_m - f_m) * 60 + (e_s - f_s);
}

bool checkPhone(string &phone)
{
    if (phone.length() != 10)
        return false;
    for (char &c : phone)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;

    while (true)
    {
        cin >> s;
        if (s == "#")
            break;
        if (s == "call")
        {
            string f_num, t_num, date, f_time, e_time;
            cin >> f_num >> t_num >> date >> f_time >> e_time;
            call_from[f_num]++;
            time_count[f_num] += calculateTime(f_time, e_time);
            total++;
            if (!checkPhone(f_num) || !checkPhone(t_num))
                check = false;
        }
    }

    while (true)
    {
        cin >> s;
        if (s == "#")
            break;
        if (s == "?check_phone_number")
            cout << check << endl;
        if (s == "?number_calls_from")
        {
            string phone;
            cin >> phone;
            cout << call_from[phone] << endl;
        }
        if (s == "?number_total_calls")
            cout << total << endl;
        if (s == "?count_time_calls_from")
        {
            string phone;
            cin >> phone;
            cout << time_count[phone] << endl;
        }
    }

    return 0;
}