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
    ListNode* partition(ListNode* head, int x) {

        ListNode *leftHead = new ListNode(), *rightHead = new ListNode();
        ListNode *right = rightHead, *left = leftHead;

        while(head){
            if(head-> val < x){
                left->next = head;
                left = left->next;

            }else{
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        left->next = rightHead->next;
        right->next = nullptr;

        return leftHead->next;


        
    }
};