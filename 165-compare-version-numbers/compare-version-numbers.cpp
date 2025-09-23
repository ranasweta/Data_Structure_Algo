class Solution {
public:
    int compareVersion(string version1, string version2) {
        // storing version1 is "v1"
        stringstream ss(version1);
        string w;
        vector<int> v1;
        while (getline(ss, w, '.')) {
            int val = 0;
            for (auto i : w) {
                val = val * 10 + (i - '0');
            }
            v1.push_back(val);
        }
        // storing version2 is "v2"
        stringstream ss2(version2);
        string w2;
        vector<int> v2;
        while (getline(ss2, w2, '.')) {
            int val = 0;
            for (auto i : w2) {
                val = val * 10 + (i - '0');
            }
            v2.push_back(val);
        }
        // now comapring them for result
        int n1 = v1.size(), n2 = v2.size();
        for (int i = 0; i < abs(n1 - n2); i++) {
            if (n1 > n2) {
                v2.push_back(0);
            } else {
                v1.push_back(0);
            }
        }
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] > v2[i]) {
                return 1;
            } else if (v1[i] < v2[i]) {
                return -1;
            }
        }
        return 0;
    }
};