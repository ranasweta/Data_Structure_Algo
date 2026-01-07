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
    //makiing global jisse hoga kya ki aap usko every time update kr skte ho on every fucntion call
    long long s;
    long long maxP;

    //pehle total sum nikalete hai 
    int totalSum(TreeNode* root){
        if(root==NULL) return 0;
        int leftSum=totalSum(root->left);
        int rightSum=totalSum(root->right);
        int sum= root->val + leftSum + rightSum;
        return sum;
    }
    long long find(TreeNode* root){
        if(root==NULL) return 0;
        int leftSum=find(root->left);
        int rightSum=find(root->right);

        long long  subtreeSum=root->val + leftSum +rightSum;
        long long remain=s-subtreeSum;
        maxP=max(maxP,subtreeSum*remain);
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        s=totalSum(root);
        maxP=0;

        find(root);
        return maxP%(1000000007);
    }
};