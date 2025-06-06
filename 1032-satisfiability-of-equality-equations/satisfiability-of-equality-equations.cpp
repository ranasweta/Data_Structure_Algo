class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i,vector<int> &parent){
        if(i==parent[i])
        return i;
        return parent[i]=find(parent[i],parent);
    }
    void Union(int x,int y){
        int x_p=find(x,parent);
        int y_p=find(y,parent);
        if(x_p==y_p)
        return;
        if(rank[x_p]>rank[y_p])
        parent[y_p]=x_p;
        else if(rank[x_p]<rank[y_p])
        parent[x_p]=y_p;
        else
        parent[x_p]=y_p;
        rank[y_p]++;

    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(auto &s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        for(auto &s:equations){
            if(s[1]=='!')
            {
                int one=find(s[0]-'a',parent);
            int two=find(s[3]-'a',parent);
            if(one==two){
                return false;
            }

            }
        }
        return true;
    }
};