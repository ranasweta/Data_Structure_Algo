class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> del;
        for (int i=0; i<nums.size();i++){
            del.push_back((nums[i]^k)-nums[i]);
        }
        long long sum =0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        // important is how you frame and understand the question it is a good intuition that u checked that all nodes are connected to each other if any 2 nodes are chnaged(maximises) after XOR then there inbetween nodes remain unchanged. hence we just need to see if every node afetr xor is increazing or not also only taking 2 at a time 
        sort(del.begin(),del.end(),greater<int>());//sorting in descending order
        for (int i=0;i<del.size()-1;i+=2){
            int check=del[i]+del[i+1];
            if (check<=0){
                break;
            }
            sum+=check;
        }
        return sum;
    }
};