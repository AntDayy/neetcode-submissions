class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        // 1. Tìm điểm giữa
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Đảo ngược nửa sau
        ListNode *curr = slow->next;
        slow->next = nullptr; // Quan trọng: Ngắt đôi danh sách
        ListNode *prev = nullptr;
        while (curr) {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // 3. Gộp xen kẽ (prev đang là đầu nửa sau đã đảo)
        ListNode *first = head;
        ListNode *second = prev;
        while (second) {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }

        // In kết quả
        ListNode *currPrint = head;
        while (currPrint) {
            cout << currPrint->val << " ";
            currPrint = currPrint->next;
        }
    }
};