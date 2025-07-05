class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<vector<int>>& graph, int u, int target, vector<int>& temp) {
        temp.push_back(u);
        if (u == target) {
            result.push_back(temp);

        }

        else {
            for (auto v : graph[u]) {

                dfs(graph, v, target, temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = n - 1;

        vector<int> temp;
        dfs(graph, 0, target, temp);
        return result;
    }
};