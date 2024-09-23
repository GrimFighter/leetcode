/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* last = head;
        int length = 1;

        while (last->next != nullptr) {
            last = last->next;
            ++length;
        }

        last->next = head;

        int t = length - k % length;
        for (int i = 0; i < t; i++) {
            last = last->next;
        }
        head = last->next;
        last->next = nullptr;

        return head;
    }
};