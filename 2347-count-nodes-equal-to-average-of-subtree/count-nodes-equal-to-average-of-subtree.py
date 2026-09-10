# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        ans=0
        def func(root):
            if root is None:
                return 0,0
            l=func(root.left)
            r=func(root.right)
            value=root.val+l[0]+r[0]
            n=l[1]+r[1]+1
            nonlocal ans
            if value//n==root.val:
                ans+=1
            return value,n
        func(root)
        return ans
        