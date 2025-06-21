class Solution {
public://dijkstra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int ,vector<pair<int,int>>>adj;//3d
        for(auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
            
            
        }
        vector<int>result(n+1,INT_MAX);
      
        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto & v:adj[node]){
                int adjn=v.first;             
                int dist=v.second;
                if(d+dist<result[adjn]){
                    result[adjn]=d+dist;
                    pq.push({d+dist,adjn});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            ans=max(ans,result[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};