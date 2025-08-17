class Solution {
public://using dfs vese toh ye swal dsu se hi best solve hi skta hai
    vector<bool> visited;
        unordered_map<int,vector<int>> adj;
        long long size;
    void dfs(int u){
        visited[u]=true;
        size++;
        for(auto & v: adj[u]){
            if(!visited[v]){
                dfs(v);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        visited=vector<bool>(n,false); 
        int remaining=n;
        long long res=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                size=0;
                dfs(i);
                res+=(size)*(remaining - size);
                remaining-=size;

            }
        }
        return res;
    }
};