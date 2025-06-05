class Solution {
public:
    vector<int> KahnsAlgo(int numCourses,unordered_map<int,vector<int>> adj,vector<int> indegree){
        queue<int> que;
        int cnt=0;
        vector<int>r;
       for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            r.push_back(i);
            cnt++;
            que.push(i);

        }}
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    r.push_back(v);
                    que.push(v);
                    cnt++;

                }
            }
        }
        if(cnt==numCourses){
            return r;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto &v: prerequisites){
            int a=v[0];
            int b=v[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        return KahnsAlgo(numCourses,adj,indegree);
       
    }
};