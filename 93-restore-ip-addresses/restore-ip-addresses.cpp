class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtrack(s, 0, 0, "", res);
        return res;
    }
private:
    void backtrack(const string& s, int start, int count, string cur, vector<string>& res) {
        if (count == 4) {
            if (start == s.size()) res.push_back(cur.substr(0, cur.size()-1));
            return;
        }
        for (int len = 1; len <= 3 && start+len <= s.size(); ++len) {
            string seg = s.substr(start, len);
            if (seg.size() > 1 && seg[0] == '0') break;
            if (stoi(seg) > 255) break;
            backtrack(s, start+len, count+1, cur+seg+".", res);
        }
    }
};