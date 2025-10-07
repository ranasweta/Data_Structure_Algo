class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        set<int> zeroes;// for storing zero vaali index
        unordered_map<int,int> mp;//isme dekho ki sbse phele barsih kab hui (lake : index)
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            int lake=rains[i];
            if(lake==0){
                zeroes.insert(i);
            }
            else{
                ans[i]=-1;
                if(mp.count(lake)){
                    //already it has water 
                    auto it = zeroes.lower_bound(mp[lake]);//find the nearest index with which we can fill it 
                    if(it == zeroes.end()){
                        //ktam
                        return {};
                    }
                    int idx=*it;
                    ans[idx]=lake;
                    zeroes.erase(it);


                }
                mp[lake]=i;
            }
        }
        return ans;

    }
};