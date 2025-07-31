class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;
        for(int i=0;i<arr.size();i++){
            for(int x: prev){//T.C. : O(32) max 32 diff element can be there 
                curr.insert(x|arr[i]);
                result.insert(x|arr[i]);
            }
            //arr[i] might be unique
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev=curr;
            curr.clear();
        }
        return result.size();
    }
};