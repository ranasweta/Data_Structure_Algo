class Solution {
public://graph Transformation
/*
making two graphs one is which is expecting blue edges
and another one is which is expecting red edges
*/
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,vector<int>>adj;
        for(auto & edge: redEdges){
            adj[edge[0]].push_back(n+edge[1]);
        }
        for(auto & edge : blueEdges){
            adj[edge[0]+n].push_back(edge[1]);
        }
        queue<pair<int,int>>q;
        vector<bool> visited(2*n,false);
        q.push({0,0});
        q.push({n,0});//initially both are initial starting node
        visited[0]=true;
        visited[n]=true;
        vector<int>ans(n,-1);
        while(!q.empty()){
            pair<int,int> it=q.front();
            q.pop();
            int node=(it.first)%n;

            if(ans[node]==-1) ans[node]=it.second;
            for(int nbr: adj[it.first]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push({nbr,it.second+1});
                }
            }
        }
        return ans;
    }
};