class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> FreeTime;
       
        FreeTime.push_back(startTime[0]);
        for(int i=1;i<endTime.size();i++){
           
            FreeTime.push_back(startTime[i]-endTime[i-1]);
        }
            FreeTime.push_back(eventTime-endTime[endTime.size()-1]);
        int n=FreeTime.size();
        int i=0;
        int j=0;
        int mx=0;
        int curr=0;
        while(j<n){
            curr+=FreeTime[j];
            while(i<n&& j-i+1>k+1){
                curr-=FreeTime[i];
                i++;
            }
            mx=max(mx,curr);
            j++;
        }

        
    return mx;
    }
};