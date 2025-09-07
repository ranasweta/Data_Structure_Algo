class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n % 2 == 0) {
            int i = -n / 2;
            while (i <= (n / 2)) {
                if (i == 0) {
                    i++;
                    continue;
                } else {
                    ans.push_back(i);
                }
                i++;
            }
        } else {
            int i = -n / 2;
            while (i <= (n / 2)) {

                ans.push_back(i);

                i++;
            }
        }
        return ans;
    }
};