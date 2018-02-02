class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeKLists(self, lists):
    	N = len(lists)
    	if N == 0:
    		return None
    	if N == 1:
            return lists[0]
    	if N > 1:
    		newList = lists[0]
    		for i in range(1, N):
    			newList = self.mergetwoLists(newList, lists[i])
    		return newList

    def mergetwoLists(self, list1, list2):
    	if not list1: return list2
    	if not list2: return list1
    	if list1.val < list2.val:
            list1.next = self.mergetwoLists(list1.next, list2)
            return list1
    	else:
            list2.next = self.mergetwoLists(list1, list2.next)
            return list2