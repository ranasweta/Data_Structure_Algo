class Solution {
public:
    vector<bool> visited;
    int cnt;
    void dfs(int u,int parent,unordered_map<int,vector<pair<int,int>>> &adj){
        visited[u]=true;
        for( auto & [v,check] : adj[u]){
            if(v!=parent){
                cnt+=check;
                dfs(v,u,adj);
            }
        }

    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for( auto & vec:connections){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        visited = vector<bool>(n, false);
        cnt=0;
        dfs(0,-1,adj);
        return cnt;

    }
};