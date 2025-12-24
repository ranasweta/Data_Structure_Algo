class Solution {
public://basic rescursion
///lets memorise
    int m,n;
    int t[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i>=m || j>=n) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(nums1[i]==nums2[j]) return t[i][j]=1+solve(nums1,nums2,i+1,j+1);
        return t[i][j]=max(solve(nums1,nums2,i+1,j),solve(nums1,nums2,i,j+1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        memset(t,-1,sizeof(t));
        return solve(nums1,nums2,0,0);
    }
};