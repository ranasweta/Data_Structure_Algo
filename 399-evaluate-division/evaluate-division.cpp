class Solution {
public:
    void bfs(unordered_map<string, vector<pair<string, double>>>& adj,
             string src, string des, unordered_set<string> visited, double& ans,
             double& product) {
                queue<pair<string,double>>que;//{string, product}
                que.push({src,product});
                visited.insert(src);
                while(!que.empty()){
                    string u=que.front().first;
                    double prod=que.front().second;
                    que.pop();
                    for(auto & p:adj[u]){
                        string v=p.first;
                        double val=p.second;
                        if(v==des){
                            ans=prod*val;
                        }
                        if(visited.find(v)==visited.end()){
                            visited.insert(v);
                            double newprod=prod*val;
                            que.push({v,newprod});
                        }
                    }
                }
             }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 1.0 / w});
        }
        vector<double> result;
        for (auto& query : queries) {
            string src = query[0];
            string des = query[1];
            double ans = -1.0;
            double product = 1.0;

            if (adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                bfs(adj, src, des, visited, ans, product);
            }
            result.push_back(ans);
        }
        return result;
    }
};