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
    int maxLevelSum(TreeNode* root) {
        int mxSum=INT_MIN;
        queue<TreeNode*> q;
        int sum=0;
        int currlvl=1;
        int res=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            sum=0;
            while(n--){//for single level
                TreeNode* t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left){
                    q.push(t->left);
                }
                if (t->right){
                    q.push(t->right);
                }

            }
            if(sum>mxSum){
                mxSum=sum;
                res=currlvl;

            }
            currlvl++;
        }
return res;
    }
};