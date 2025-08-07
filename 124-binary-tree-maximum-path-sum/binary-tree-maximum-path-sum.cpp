/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;
    int  solve(TreeNode* root){
        if(root==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);

        int niche_hi_milgaya=l+r+root->val;
        int koi_ek_acha_hai=max(l,r)+root->val;
        int only_root_acha_hai=root->val;
        maxSum=max({niche_hi_milgaya,koi_ek_acha_hai,only_root_acha_hai,maxSum});
        return max(only_root_acha_hai,koi_ek_acha_hai);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};