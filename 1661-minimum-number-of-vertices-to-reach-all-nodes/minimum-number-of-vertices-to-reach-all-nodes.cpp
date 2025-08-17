class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,false);
        for(auto edge: edges){
            
            int v=edge[1];
            indegree[v]=true;

        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(indegree[i]==false){
                result.push_back(i);
            }
        }
        return result;
    }
};