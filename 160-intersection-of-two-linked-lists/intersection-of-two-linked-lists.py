# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:
        # a = headA
        # b = headB

        # while a != b:
        #     if a != None:
        #         a = a.next
        #     else:
        #         a = headB
        #     if b != None:
        #         b = b.next
        #     else:
        #         b = headA
        # return a

        a = headA
        dic = {}

        while a:
            dic[a] = a.val
            a = a.next
        a = headB

        while a:
            if a in dic:
                return a
            a = a.next
        return None
