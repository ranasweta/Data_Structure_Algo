class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(begin(folder),end(folder));
        vector<string> result;
        for(auto &curr: folder){
            bool isFolder=false;
            string temp=curr;
           while(!curr.empty())
           { size_t pos=curr.find_last_of('/');
            curr=curr.substr(0,pos);
            if(st.find(curr)!=st.end()){
                isFolder=true;
                break;
            }
            }
            if(!isFolder){
                result.push_back(temp);
            }
        }
return result;
   
    }
};