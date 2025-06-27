class Solution {
public:
    int m, n;
    int pathCount = 0;
    int totalCellsToVisit = 0;
    vector<vector<int>> directions = {{1,0}, {0,1}, {0,-1}, {-1,0}};

    void dfs(vector<vector<int>>& grid, int i, int j, int visitedCount) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
            return;

        if(grid[i][j] == 2) {
            if(visitedCount == totalCellsToVisit)
                pathCount++;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;  // mark visited

        for(auto& dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];
            dfs(grid, ni, nj, visitedCount + 1);
        }

        grid[i][j] = temp; // backtrack
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int startX = 0, startY = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] != -1)
                    totalCellsToVisit++;
                if(grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }

        dfs(grid, startX, startY, 1);
        return pathCount;
    }
};
