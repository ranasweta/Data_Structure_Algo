class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
    bool isSafe(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    void dfs(vector<vector<int>>& grid, int i, int j, set<pair<int,int>>& visited){
        if (!isSafe(i, j) || grid[i][j] == 0 || visited.count({i,j})) return;

        visited.insert({i,j});
        for (auto &dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(grid, i_, j_, visited);
        }
    }

    int bfs(vector<vector<int>>& grid, set<pair<int,int>> visited){
        queue<pair<int,int>> que;
        for (auto &cell : visited){
            que.push(cell);
        }

        int level = 0;
        while (!que.empty()){
            int L = que.size();
            while (L--){
                auto [x, y] = que.front(); que.pop();
                for (auto &dir : directions){
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];
                    if (!isSafe(x_, y_) || visited.count({x_, y_})) continue;

                    if (grid[x_][y_] == 1) return level;

                    visited.insert({x_, y_});
                    que.push({x_, y_});
                }
            }
            level++;
        }

        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        set<pair<int,int>> visited;

        // Find and mark the first island using DFS
        bool found = false;
        for (int i = 0; i < n && !found; ++i){
            for (int j = 0; j < n && !found; ++j){
                if (grid[i][j] == 1){
                    dfs(grid, i, j, visited);
                    found = true;
                }
            }
        }

        // Use BFS to find shortest path to second island
        return bfs(grid, visited);
    }
};
