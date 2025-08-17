class Solution {
public:
    void bfs(int vertex,unordered_map<int,vector<pair<int,int>>>& adj,vector<bool> &visited,int &result){
        
        queue<int>que;
        que.push(vertex);
        visited[vertex]=true;
        
       
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(auto &[v,dist]:adj[u]){
                result=min(result,dist);
                if(!visited[v]){
                    que.push(v);
                    visited[v]=true;
                    
                }
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
        bfs(1,adj,visited,result);
        return result;

    }
};