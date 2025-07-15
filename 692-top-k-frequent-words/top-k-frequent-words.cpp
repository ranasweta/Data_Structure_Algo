class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string w : words) {
            mp[w]++;
        }

        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second; // reverse lexicographic order
            return a.first < b.first; // max heap by frequency
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }

        vector<string> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};