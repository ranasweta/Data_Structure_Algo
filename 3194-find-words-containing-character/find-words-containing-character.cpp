class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            int a=words[i].size();
            for (int j=0;j<a;j++){
                if (x==words[i][j]){
                    ans.push_back(i);
                    break;
                }
                
            }
        }
        return ans;
    }
};