
class ListNode(object):
    def __init__(self, x):
        self.val = x;
        self.next = None;

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k == 1 or head == None: return head
        curr = head
        for i in range(k-1):
            if curr.next:
                curr = curr.next
            else:
                return head
        prev = head
        curr = prev.next
        for i in range(k-1):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        head.next = self.reverseKGroup(curr, k)
        return prev

    def createLinkedList(self, aList):
        curr = ListNode(aList.pop(0))
        head = curr
        while(aList):
            curr.next = ListNode(aList.pop(0))
            curr = curr.next
        return head

    def printLinkedList(self, head):
        curr = head
        while curr:
            print curr.val
            curr = curr.next    

def main():
    aList = [1,2,3,4,5,6,7]
    sol = Solution()
    head = sol.createLinkedList(aList)
    sol.printLinkedList(head)
    print '\n'
    newHead = sol.reverseKGroup(head, 100)
    sol.printLinkedList(newHead)

if __name__ == '__main__':
    main()          