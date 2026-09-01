# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, l,r, arr):
        if l>r:
            return None
        mid=l+(r-l)//2
        root = TreeNode(arr[mid])
        root.left=self.solve(l,mid-1,arr)
        root.right=self.solve(mid+1,r,arr)
        return root


    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:   
        arr=[]
        def inorder(root):
            if root is None:
                return 
            inorder(root.left)
            arr.append(root.val)
            inorder(root.right)
        inorder(root)
        
        return self.solve(0,len(arr)-1,arr)

        