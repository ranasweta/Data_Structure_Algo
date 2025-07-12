class Solution {
public://slidind window 
/*
left        right
1 2 3 4     0
1 2 3       0 1
1 2         0 1 3
1           0 1 3 2
0           0 1 3 2 0
take max at each iteration hence iteration is k

*/
    int maxScore(vector<int>& nums, int k) {
        int rSum=0;
        int lSum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            lSum+=nums[i];

        }
        maxSum=lSum;
        int rIndex=nums.size()-1;
        for(int i=k-1;i>=0;i--){
            lSum-=nums[i];
            rSum+=nums[rIndex];
            rIndex--;
            maxSum=max(maxSum,lSum+rSum);
        }
        return maxSum;

    }
};