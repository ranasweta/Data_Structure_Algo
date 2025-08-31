class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        //using min heap
        vector<int> ans;
        for(int i=0;i<order.size();i++){
            for(int f:friends){
                if(f==order[i]){
                    ans.push_back(f);
                }
            }
        }
        return ans;
    }
};