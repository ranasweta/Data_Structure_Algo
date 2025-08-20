class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj, int u,int v,vector<bool> &visited){
        if(u==v){
            return true;
        }
        visited[u]=true;
        for(int x:adj[u]){
            if(visited[x]) continue;
                if(dfs(adj,x,v,visited)) return true;

            
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            vector<bool> visited(n,false);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(adj,u,v,visited)){
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        return {};
    }
};