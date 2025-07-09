class Solution {
public://dfs 
    int dfs(unordered_map<int,vector<int>>&adj,int curr,int parent,vector<bool>& hasApple){
        int time =0;
        for(int child : adj[curr]){
            if(child==parent) continue;
            int time_by_child=dfs(adj,child,curr,hasApple);
            if(time_by_child>0 || hasApple[child]){
                time+=2+time_by_child;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //make adj
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj,0,-1,hasApple);
    }
};