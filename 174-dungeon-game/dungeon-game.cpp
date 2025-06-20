class Solution {
public://bottom up 
//t[i][j] its reaching from m-1 & n-1 to i,j min steps 
// hence we willl return t[0][0]
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
        if (i == m - 1 && j == n - 1) {
            t[i][j] = max(1, 1 - dungeon[i][j]);
        } else {
            int right = (j + 1 < n) ? t[i][j + 1] : INT_MAX;
            int down = (i + 1 < m) ? t[i + 1][j] : INT_MAX;
            int need = min(right, down) - dungeon[i][j];
            t[i][j] = max(1, need);
        }
    }
}

        return t[0][0];
    }
};