class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Tạo một node giả (dummy head) để việc thêm node mới dễ dàng hơn
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy; // tail dùng để trỏ tới cuối danh sách kết quả
        int carry = 0;          // Biến "nhớ" (khởi tạo bằng 0)

        // Lặp khi 1 trong 2 danh sách vẫn còn phần tử, HOẶC vẫn còn số "nhớ"
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry; // Tổng tại vị trí hiện tại bắt đầu bằng biến nhớ

            // Nếu l1 còn phần tử, cộng giá trị của l1 vào tổng và tiến l1
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // Nếu l2 còn phần tử, cộng giá trị của l2 vào tổng và tiến l2
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Cập nhật lại số nhớ cho phép tính tiếp theo (ví dụ: 15 / 10 = 1)
            carry = sum / 10;

            // Tạo node mới cho kết quả chứa chữ số hàng đơn vị (ví dụ: 15 % 10 = 5)
            tail->next = new ListNode(sum % 10);
            
            // Tiến con trỏ tail
            tail = tail->next;
        }

        // Lưu lại đầu danh sách kết quả thật sự (bỏ qua node dummy)
        ListNode *res = dummy->next;
        
        // Giải phóng bộ nhớ của node dummy để tránh rò rỉ bộ nhớ
        delete dummy; 
        
        return res;
    }
};