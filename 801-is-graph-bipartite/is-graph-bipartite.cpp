class Solution {
public:
    bool dfs( vector<vector<int>>& graph,int curr,vector<int> &color,int curr_color){
        color[curr]=curr_color;
        for(auto &v:graph[curr]){
            if(color[v]==color[curr])
            return false;
            if(color[v]==-1)//not visited{
                {
                    int v_color=1-color[curr];
                if(!dfs(graph,v,color,v_color)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);//work as visited
        for(int i=0;i<n;i++){
            if(color[i]==-1)
            {
                if(!dfs(graph,i,color,1)){
                return false;
            }
            }
        }
        return true;
    }
};