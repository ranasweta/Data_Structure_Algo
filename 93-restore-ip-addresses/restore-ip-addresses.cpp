
class Solution {
public:
    int n;
    vector<string> result;

    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }

        return stoi(s) <= 255;
    }

    void solve(int idx, string s, string curr, int parts) {

        if (idx == n && parts == 4) {
            curr.pop_back();
            result.push_back(curr);
            return;
        }

        if (idx == n || parts == 4) {
            return;
        }

        if (idx + 1 <= n && isValid(s.substr(idx, 1))) {
            solve(idx + 1, s, curr + s.substr(idx, 1) + '.', parts + 1);
        }

        if (idx + 2 <= n && isValid(s.substr(idx, 2))) {
            solve(idx + 2, s, curr + s.substr(idx, 2) + '.', parts + 1);
        }

        if (idx + 3 <= n && isValid(s.substr(idx, 3))) {
            solve(idx + 3, s, curr + s.substr(idx, 3) + '.', parts + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        result.clear();

        if (n < 4 || n > 12) {
            return {};
        }

        solve(0, s, "", 0);

        return result;
    }
};
