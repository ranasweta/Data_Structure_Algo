class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        //{elemnt,listIndex,elementIndex} vector<int>
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int maxEl=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],i,0});
            maxEl=max(maxEl,nums[i][0]);
        }
        //now make a range for it
        vector<int>result={-1000000,1000000};
        while(!pq.empty()){
            vector<int>curr=pq.top();
            pq.pop();
            int minEl=curr[0];
            int list=curr[1];
            int idx=curr[2];
            if(maxEl-minEl<result[1]-result[0])
            {
                result[0]=minEl;
                result[1]=maxEl;

            }
            //move min index in it list ahead
            if(idx+1<nums[list].size()){
                pq.push({nums[list][idx+1],list,idx+1});//next element pushed
                maxEl=max(maxEl,nums[list][idx+1]);
            }
            else{
                break;
            }

        }
return result;

    }
};