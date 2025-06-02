class Solution {
public:
    void dfs(vector<vector<int>> &adj,int u,vector<bool> &visited){
        visited[u]=true;
        for(int &v:adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                cnt++;
            }
        }
        return cnt;
    }
};