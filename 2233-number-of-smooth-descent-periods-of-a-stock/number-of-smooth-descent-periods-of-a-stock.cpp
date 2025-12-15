class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size();
        long long  curr = 1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                curr++;
            } else {
                ans += (curr - 1) * (curr) / 2;
                curr = 1;
            }
        }
        ans += (curr - 1) * (curr) / 2;

        return ans;
    }
};