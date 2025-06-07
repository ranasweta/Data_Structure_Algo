class Solution {
public:
    vector<int> parent;
    vector<int> rank;//baad me resize krn amat bhulna
    int find(int x){
        if(x==parent[x])
           return x;
        return find(parent[x]);
    }
    void Union(int x,int y){
        int x_p=find(x);
        int y_p=find(y);
        if(x_p==y_p){
            return ;
        }
        if(rank[x_p]>rank[y_p]){
            parent[y_p]=x_p;
        }
        else if(rank[y_p]>rank[x_p]){
            parent[x_p]=y_p;
        }
        else{
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &v:edges){
            Union(v[0],v[1]);

        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int p=find(i);
            mp[p]++;
        }
        long long r=0;
        long long rem=n;
        for(auto &it : mp){
            int s=it.second;
            r+=s*(rem-s);
            rem-=s;

        }
        return r;
    }
};