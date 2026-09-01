class Solution:
    def bstToGst(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        summ = 0

        def inorderreverse(root):
            nonlocal summ

            if root is None:
                return

            # Right → Root → Left
            inorderreverse(root.right)

            summ += root.val
            root.val = summ

            inorderreverse(root.left)

        inorderreverse(root)

        return root