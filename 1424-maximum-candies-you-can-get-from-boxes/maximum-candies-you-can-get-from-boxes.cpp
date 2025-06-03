class Solution {
public:
    int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int> &visited,unordered_set<int>& found){
        if(visited.count(box))
        return 0;
        if(status[box]==0){
            found.insert(box);//jo jo box mile hai vo 
            return 0;

        }
        //ab ata hai ki us box ki candies add kro
        visited.insert(box);
        int c=candies[box];
        for(int &insidebox :containedBoxes[box] ){
            c+=dfs(insidebox,status,candies,keys,containedBoxes,visited,found);
        }
        //ab un boxes me kinki chabhi hai or jinki chabhi hai unhe kholo fir check kro agr vo already mil chuke kisi ke andr if mil gaye hai toh kholo fir unke andr dekho agr boxes and keys and candies mile 
        for(int &key:keys[box])
    {
        status[key]=1;
        if(found.count(key)){
            c+=dfs(key,status,candies,keys,containedBoxes,visited,found);
        }
    }
    return c;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int> visited;
        unordered_set<int> found;
        int c=0;
        for (int & box : initialBoxes){
            c+=dfs(box,status,candies,keys,containedBoxes,visited,found);
        }
        return c;
    }
};