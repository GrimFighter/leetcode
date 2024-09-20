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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* prev = head;
        ListNode* itr = head;
        int curr = head->val;

        while (itr) {
            if (itr->val != curr) {
                curr = itr->val;
                prev->next = itr;
                prev = itr;
            }
            itr = itr->next;
        }
        prev->next = nullptr;    
        return head;
    }
};