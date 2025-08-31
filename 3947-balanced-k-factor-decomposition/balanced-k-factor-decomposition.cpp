class Solution {
public:
    vector<int> ans;
    int n;
    void solve(int num, int k, vector<int> &curr){
        if(k==0 && !curr.empty()){
            long long prod=1;
            for(auto it:curr) prod=prod*it;
            if(ans.empty() && !(prod==n)) return ;
            bool c=(prod==n && ans.empty());
            if(c){
                ans=curr;
                return ;
            }
            int maxi = *max_element(curr.begin(), curr.end());
            int mini = *min_element(curr.begin(), curr.end());

            int maxi_ans = *max_element(ans.begin(), ans.end());
            int mini_ans = *min_element(ans.begin(), ans.end());
            if(prod==n && abs(maxi-mini)< abs(maxi_ans-mini_ans)){
                ans=curr;
            }
            return;
        }
        if(num==0) return;
        for(int i=1;i<=num;i++){
            if(num%i==0){
                curr.push_back(i);
                solve(num/i,k-1,curr);
                curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n_, int k) {
        n=n_;
        vector<int> curr;
        solve(n,k,curr);
        return ans;
    }
};