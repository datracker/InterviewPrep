# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from Queue import PriorityQueue

class Solution(object):
    def mergeKLists(self, lists):
        dummy = ListNode(None)
        curr = dummy
        pQueue = PriorityQueue()
        for idx, headNode in enumerate(lists):
            if headNode: pQueue.put((headNode.val, idx, headNode))
        while not pQueue.empty() > 0:
            popped = pQueue.get()
            curr.next = popped[2]
            idx = popped[1]
            curr = curr.next
            if curr.next: pQueue.put((curr.next.val, idx, curr.next))
        return dummy.next