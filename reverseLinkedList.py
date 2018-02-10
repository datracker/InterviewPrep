class ListNode(object):
	def __init__(self, x):
		self.val = x;
		self.next = None;

def reverseList(head):
	prev = head
	if prev.next: 
		curr = prev.next
	else:
		return head
	
	while curr:
		temp = curr.next
		curr.next = prev
		prev = curr
		curr = temp
	head.next = None
	return prev

def createLinkedList(aList):
	curr = ListNode(aList.pop(0))
	head = curr
	while(aList):
		curr.next = ListNode(aList.pop(0))
		curr = curr.next
	return head

def printLinkedList(head):
	curr = head
	while curr:
		print curr.val
		curr = curr.next

def main():
	aList = [1,2,3,4,5,6,7]
	head = createLinkedList(aList)
	#printLinkedList(head)
	tail = reverseList(head)
	printLinkedList(tail)

if __name__ == '__main__':
	main()