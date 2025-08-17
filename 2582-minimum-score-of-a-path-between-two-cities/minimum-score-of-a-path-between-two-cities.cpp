class Solution {
public:
    void dfs(int u,unordered_map<int,vector<pair<int,int>>>& adj,vector<bool> &visited,int &result){
        visited[u]=true;
        for(auto vec: adj[u]){
            int v=vec.first;
            int dist=vec.second;
         result=min(result,dist);
            if(!visited[v]){
                dfs(v,adj,visited,result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int result=INT_MAX;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto r:roads){
            int u=r[0];
            int v=r[1];
            int dist=r[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        
        vector<bool> visited(n+1,false);
        dfs(1,adj,visited,result);
        return result;

    }
};