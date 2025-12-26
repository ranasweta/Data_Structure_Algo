class Solution {
public://just detection of cycle in a graph 
    bool dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int u,vector<bool> &inrec){
        visited[u]=true;
        inrec[u]=true;
        for(int v:adj[u]){
            if(!visited[v] && dfs(adj,visited,v,inrec)){
                return true;
            }
            else if(inrec[v]){
                return true;
            }
        }
        inrec[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        //for directed
        for(auto vec:prerequisites){
            int u=vec[1];
            int v=vec[0];
            adj[u].push_back(v);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> inrec(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(adj,visited,i,inrec)){
                return false;
            }
        }
        return true;
    }
};