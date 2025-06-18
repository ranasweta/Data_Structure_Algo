class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            t[i][i] = 1;  // Single character is always a palindrome
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i + 1][j], t[i][j - 1]);
                }
            }
        }

        return t[0][n - 1];
    }
};