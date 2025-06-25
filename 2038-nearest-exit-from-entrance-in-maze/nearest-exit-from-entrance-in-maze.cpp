class Solution {
public:
    int m, n;
    vector<vector<int>> direction = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool check(int i, int j) { return (i < m && i >= 0 && j < n && j >=0); }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> que;
        m = maze.size();
        n = maze[0].size();
        que.push({entrance[0], entrance[1]});
        int steps = 0;
        while (!que.empty()) {
            int p = que.size();
            while (p--) {
                int r = que.front().first;
                int c = que.front().second;
                

                que.pop();
                if ((r == 0 || r == m - 1 || c == 0 || c == n - 1) &&
                    (r != entrance[0] || c != entrance[1])) {
                    return steps;
                }
                for (auto dir : direction) {
                    int x = r + dir[0];
                    int y = c + dir[1];
                    if ( check(x, y) && maze[x][y] == '.') {
                        maze[x][y] ='+';
                        que.push({x, y});
                    }
                }
            }
            steps++;
          
        }
        return -1;
    }
};