class Solution {
public:
    void dfs(int curr,int n,vector<int>& r){
        if(curr>n) return;
        r.push_back(curr);
        for(int i=0;i<=9;i++){
            int num=curr*10+i;//this is appending new digit at ones place   
            if(num>n) return ;
            dfs(num,n,r);
        }

    }
    vector<int> lexicalOrder(int n) {
        //we have to make a tree with every 1-9 while appending 0-9 in its ones place
        vector<int> r;
        for (int i=1;i<=9;i++){
            dfs(i,n,r);
        }
        return r;
    }
};