class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int curr, vector<int>& color,
             int curr_color) {
        queue<int> que;
        color[curr] = curr_color;
        que.push(curr);
        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (auto& v : graph[u]) {
                if (color[v] == color[u])
                    return false;
                else if (color[v] == -1) // not visited{
                {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }
    return true;
    }
 
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1); // work as visited
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bfs(graph, i, color, 1)) {
                return false;
            }
        }
    }
    return true;
}
}
;