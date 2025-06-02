class Solution {
public:
    int n;
    void bfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;
        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            for (auto& v : adj[curr]) {
                if (!visited[v]) {
                    bfs(adj,v,visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(adj, i, visited);
                cnt++;
            }
        }
        return cnt;
    }
};