class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       
        sort(begin(arr),end(arr));
        int mn=INT_MAX;
        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;i++){
            mn=min(mn,(arr[i+1]-arr[i]));
        }
        for(int i=0;i<arr.size()-1;i++){

            if(arr[i+1]-arr[i]==mn){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);

                ans.push_back(temp);
            }


        }
        return ans;
        
    }
};