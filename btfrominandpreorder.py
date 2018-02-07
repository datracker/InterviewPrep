# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder or not postorder:
            return None
    
        root = TreeNode(postorder.pop())
        inorderIndex = inorder.index(root.val)
        
        root.right = self.buildTree(inorder[inorderIndex+1: ], postorder)
        root.left = self.buildTree(inorder[:inorderIndex], postorder)
        
        return root

def stringToIntegerList(input):
    return json.loads(input)

def treeNodeToString(root):
    if not root:
        return "[]"
    output = ""
    queue = [root]
    current = 0
    while current != len(queue):
        node = queue[current]
        current = current + 1

        if not node:
            output += "null, "
            continue

        output += str(node.val) + ", "
        queue.append(node.left)
        queue.append(node.right)
    return "[" + output[:-2] + "]"

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            inorder = stringToIntegerList(line)
            line = lines.next()
            postorder = stringToIntegerList(line)
            
            ret = Solution().buildTree(inorder, postorder)

            out = treeNodeToString(ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()