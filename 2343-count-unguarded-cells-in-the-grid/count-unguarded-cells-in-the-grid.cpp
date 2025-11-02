class Solution {
public: // brute
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        //-1 unoccupied 0 guard 1 wall at the end we have to count -1
        int ans = 0;
        for (const auto& guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 0;
        }
        for (const auto& wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // go right
                if (grid[i][j] == 0) {
                    // Right
                    for (int r = j + 1;
                         r < n && grid[i][r] != 1 && grid[i][r] != 0; r++) {
                        grid[i][r] = 2;
                    }
                    // Left
                    for (int l = j - 1;
                         l >= 0 && grid[i][l] != 1 && grid[i][l] != 0; l--) {
                        grid[i][l] = 2;
                    }
                    // Up
                    for (int u = i - 1;
                         u >= 0 && grid[u][j] != 1 && grid[u][j] != 0; u--) {
                        grid[u][j] = 2;
                    }
                    // Down
                    for (int d = i + 1;
                         d < m && grid[d][j] != 1 && grid[d][j] != 0; d++) {
                        grid[d][j] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};