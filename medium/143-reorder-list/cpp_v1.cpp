// Pushed: 2026-10-09 18:26:46 UTC
// Difficulty: Medium
// Runtime: 0 ms
// Memory: 23.6 MB

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverseLL(slow->next);
        slow->next = NULL;

        ListNode* curr = head;

        while (rev != NULL) {
            ListNode* tempcurr = curr->next;
            curr->next = rev;

            ListNode* temprev = rev->next;
            rev->next = tempcurr;

            curr = tempcurr;
            rev = temprev;
        }
    }
};