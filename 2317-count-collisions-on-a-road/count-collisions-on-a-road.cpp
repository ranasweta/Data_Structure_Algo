class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        // Skip cars moving left at the start
        while (i < n && directions[i] == 'L') i++;

        // Skip cars moving right at the end
        while (j >= 0 && directions[j] == 'R') j--;

        int ans = 0;
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S') ans++;
        }
        return ans;
    }
};