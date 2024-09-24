/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    private:
        int getLength(ListNode *head)
        {
            int l = 0;
            for (ListNode *ptr = head; ptr; ptr = ptr->next)
                ++l;
            return l;
        }

    public:
        ListNode* reverseKGroup(ListNode *head, int k)
        {   
            if(!head || k == 1) return head;
            
            int n = getLength(head);
            ListNode dummy(0, head);

            ListNode *prev = &dummy;
            ListNode *curr = head;

            for (int i = 0; i < n / k; ++i)
            {
                for (int j = 0; j < k - 1; ++j)
                {
                    ListNode *tmp = curr->next;

                    curr->next = tmp->next;
                    tmp->next = prev->next;

                    prev->next = tmp;
                }

                prev = curr;
                curr = curr->next;
            }

            return dummy.next;
        }
};