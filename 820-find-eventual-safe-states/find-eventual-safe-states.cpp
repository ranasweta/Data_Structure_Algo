class Solution {
public:
    bool isCycle(vector<vector<int>>& graph,int u,vector<bool> &visited,vector<bool> &InRecursion){
        visited[u]=true;
        InRecursion[u]=true;
        for(int &v:graph[u]){
            if(visited[v]==false && isCycle(graph,v,visited,InRecursion)){
                return true;
            }
            else if(InRecursion[v]==true){
                return true;
            }
        }
        InRecursion[u]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool> visited(V,false);
        vector<bool> InRecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(visited[i]==false ){
               isCycle(graph,i,visited,InRecursion);
            }
        }
        vector<int> res;
        for(int i=0;i<V;i++){
            if(InRecursion[i]==false){
                res.push_back(i);
            }
        }
        return res;
    }
};