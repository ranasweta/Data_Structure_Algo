class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2!=0){
            return {};
        }
        sort(begin(changed),end(changed));
        unordered_map<int,int>freq;
        for(int num: changed){
            freq[num]++;
        }
        vector<int> result;
        for( int num: changed){
            int twice=2*num;
            if(freq[num]==0) continue;
            if(freq.find(twice)==freq.end() || freq[twice]==0){
                    return {};
            }
            freq[num]--;
            freq[twice]--;
            result.push_back(num);
        }
        return result;

    }
};