class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.length();
        int i = 0, j = 0;
        int res = 0;

        while (j < n) {
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
                res = max(res, (int)st.size());
                j++;
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};
