class Solution {
public:
int M=1e9+7;
    int possibleStringCount(string word, int k) {
        if (k > word.length()) {
            return 0;
        }
        vector<int> freq;
        int cnt = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);
        long long p = 1;
        for (int& f : freq) {
            p = (p * f) % M;
        }
        int n = freq.size();
        if(n>=k){
            return p;
        }
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));
        // base case
        for (int i = k-1; i >=0; i--) {
            t[n][i] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
           vector<int> prefix(k+1, 0);
            for(int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % M;
            }

            for(int count = k-1; count >= 0; count--) {
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    t[i][count] = (prefix[r+1] - prefix[l] + M) % M;
                }}
        }
        long long inv=t[0][0];
        return (p-inv+M)%M;
    }
};