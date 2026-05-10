class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || t.empty() || s.length() < t.length())
        {
            return "";
        }

        // mapT dùng để lưu số lượng mỗi ký tự cần thiết từ chuỗi t
        unordered_map<char, int> mapT;
        for (char c : t)
        {
            mapT[c]++;
        }

        int required = mapT.size(); // Số lượng ký tự *khác nhau* cần thỏa mãn
        int formed = 0;             // Số lượng ký tự đã thỏa mãn đủ số lượng trong cửa sổ

        // mapWindow dùng để đếm ký tự trong cửa sổ hiện tại
        unordered_map<char, int> mapWindow;

        int left = 0, right = 0;

        // Lưu thông tin kết quả: {độ_dài_nhỏ_nhất, vị_trí_bắt_đầu, vị_trí_kết_thúc}
        int ans[3] = {-1, 0, 0};

        while (right < s.length())
        {
            char c = s[right];
            mapWindow[c]++;

            // Nếu ký tự hiện tại nằm trong t và số lượng trong cửa sổ đã bằng số lượng yêu cầu
            if (mapT.count(c) && mapWindow[c] == mapT[c])
            {
                formed++;
            }

            // Cố gắng thu hẹp cửa sổ khi đã thỏa mãn điều kiện (formed == required)
            while (left <= right && formed == required)
            {
                c = s[left];

                // Cập nhật kết quả nhỏ nhất
                if (ans[0] == -1 || right - left + 1 < ans[0])
                {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }

                // Bắt đầu loại bỏ ký tự ở left ra khỏi cửa sổ
                mapWindow[c]--;
                if (mapT.count(c) && mapWindow[c] < mapT[c])
                {
                    formed--; // Không còn thỏa mãn đủ điều kiện nữa
                }

                left++; // Thu hẹp
            }

            right++; // Mở rộng
        }

        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};