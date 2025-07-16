class Solution {
public://do it consequtively no need to see 2nd example
//plant that which has most days to grow
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        auto lambda=[](pair<int,int>&P1,pair<int,int>&P2){
            return P1.second>P2.second;

        };
        sort(begin(vec),end(vec),lambda);
        int maxBloomDays=0;//for max days our ans
        int prevPlantDays=0;
        for(int i=0;i<n;i++){
            int currPlantDays=vec[i].first;
            int currBloomDays=vec[i].second;

            prevPlantDays+=currPlantDays;//so that we may know the last planted
            int currPlantBloomDays=prevPlantDays+currBloomDays;
            maxBloomDays=max(maxBloomDays,currPlantBloomDays);
        }
        return maxBloomDays;
    }
};