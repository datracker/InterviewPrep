"""
Ptoblem no. 2
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
"""


class ListNode(object):
    '''A class for Node'''
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    '''A class for the solution'''
    def addTwoNumbers(self, l1, l2):
        res = []
        remainder = [0]
        while l1 != None and l2 != None:
            a = l1.val + l2.val + remainder.pop(0)
            res.append(a%10)
            remainder.append(a/10)
            if l1.next and not l2.next:
                l2.next = ListNode(0)
            if l2.next and not l1.next:
                l1.next = ListNode(0)
            l1 = l1.next
            l2 = l2.next
        a = remainder.pop()
        if a:
            res.append(a)
        return res

if __name__ == "__main__":
    l1 = ListNode(5)
    #l1.next = ListNode(4)
    #l1.next.next = ListNode(3)

    l2 = ListNode(5)
    #l2.next = ListNode(6)
    #l2.next.next = ListNode(4)

    sol = Solution()
    print sol.addTwoNumbers(l1, l2)
        