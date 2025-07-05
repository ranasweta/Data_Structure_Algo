class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        int mx=-1;
        for(auto [key,value]:freq){
            if(key==value){
                mx=max(value,mx);
            }
        }
        return mx;
    }
};