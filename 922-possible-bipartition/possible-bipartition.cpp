class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&adj,int node,vector<int> &color){
        queue<int>que;
        que.push(node);
        color[node]=1;//red
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(auto v : adj[u]){
                if(color[v]==color[u]){
                    return false;
                }
                if(color[v]==-1){
                    que.push(v);
                    color[v]=1-color[u];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto vec:dislikes){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(bfs(adj,i,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};