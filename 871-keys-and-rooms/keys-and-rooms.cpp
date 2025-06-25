class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited,int i){
        visited[i]=true;
        for(auto &key:rooms[i]){
            if(!visited[key])
            dfs(rooms,visited,key);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        dfs(rooms,visited,0);
        for(bool x:visited){
            if(x==false){
                return false;
            }
        }
        return true;

    }
};