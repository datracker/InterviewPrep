# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k == 1: return head
        curr = head
        dummy = head
        for i in xrange(k-1):
        	if not curr.next:
        		curr = curr.next
        curr = self.reverseNodes(dummy, k)
        curr = curr.next
        self.reverseKGroup(curr, k)
        return head

    def reverseNodes(self, head, k):
    	if k == 2:
    		prev = head
    		curr = head.next
    		prev.next = curr.next
    		curr.next = prev
    		return curr

    	else if k > 2:
    		prev = head
    		curr = prev.next
    		nextNode = curr.next
    		for i in range(k-2):
    			curr.next = prev
    			prev = curr
    			curr = nextNode
    			nextNode = nextNode.next
    		head.next = curr.next
    		return curr