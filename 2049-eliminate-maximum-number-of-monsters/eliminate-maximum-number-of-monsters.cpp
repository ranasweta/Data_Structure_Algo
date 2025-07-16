class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int>time(n);
        for(int i=0;i<n;i++){
            time[i]=ceil((float)dist[i]/speed[i]);
        }
        sort(begin(time),end(time));
        int cnt=1;
        int time_passes=1;//1 for sure will be killed
        for(int i=1;i<n;i++){
                if(time[i]-time_passes<=0){
                    return cnt;
                }
                cnt+=1;
                time_passes+=1;
        }
        return cnt;

    }
};