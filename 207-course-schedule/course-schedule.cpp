class Solution {
public:
    bool toposort(unordered_map<int ,vector<int>> &adj,int n,vector<int> &indegree){
        int count=0;
        queue<int> que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    que.push(v);
                }
            }
        }
        if(count==n) return true ;
        else return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int ,vector<int>> adj;
        vector<int> indegree(numCourses,0);//kahn's algo
        for(auto &e:prerequisites)
        {
            int a=e[0];
            int b=e[1];
            //b--->a
            adj[b].push_back(a);
            indegree[a]++;
        }
        return toposort(adj,numCourses,indegree);
    }
};