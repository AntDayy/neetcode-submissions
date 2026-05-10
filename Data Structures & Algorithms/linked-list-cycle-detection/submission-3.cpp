class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *turtle = head;
        ListNode *rabbit = head;

        // Đảm bảo thỏ và bước đi tiếp theo của thỏ không bị rỗng để tránh Crash
        while (rabbit != nullptr && rabbit->next != nullptr)
        {
            turtle = turtle->next;       // Rùa đi 1 bước
            rabbit = rabbit->next->next; // Thỏ đi 2 bước

            // Cho chúng di chuyển xong rồi mới kiểm tra xem có gặp nhau không
            if (turtle == rabbit)
                return true;
        }

        return false;
    }
};