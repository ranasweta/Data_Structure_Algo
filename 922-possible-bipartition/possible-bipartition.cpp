class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int node,vector<int> &color,vector<int> &visited,int col){
        color[node]=col;
        visited[node]=1;
        for(auto v:adj[node]){
            if(!visited[v]){
                
                if(dfs(adj,v,color,visited,1-col)==false) return false;
            }
            if(color[v]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        vector<int> visited(n+1,0);
        for(auto vec:dislikes){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(dfs(adj,i,color,visited,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};