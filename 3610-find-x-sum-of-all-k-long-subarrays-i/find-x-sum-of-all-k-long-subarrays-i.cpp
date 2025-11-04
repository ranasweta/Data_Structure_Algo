class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first == b.first)
                return a.second < b.second; // tie-breaker: higher value wins
            return a.first < b.first;       // max heap by frequency
        }
    };

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
            for (auto& [val, freq] : mp) {
                pq.push({freq, val});
            }

            int sum = 0, t = x;
            while (t-- && !pq.empty()) {
                auto [freq, val] = pq.top(); pq.pop();
                sum += freq * val;
            }

            ans.push_back(sum);
        }
        return ans;
    }
};