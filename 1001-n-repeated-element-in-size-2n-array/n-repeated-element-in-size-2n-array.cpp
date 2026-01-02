class Solution {
public://pigeonhole technique as the num will occupy half of the array hence its very high chance that it will be in 3 consecutive (smallest meaningful subarray window size (3))
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size() - 2; ++i)
            if (A[i] == A[i + 1] || A[i] == A[i + 2])
                return A[i];
        return A.back();
    }
};
