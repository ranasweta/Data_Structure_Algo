class Solution {
public:
    string generateTag(string caption) {
        string s = "#";
        bool flag = false;
        int idx=0;
        while(caption[idx]==' '){
            idx++;
        }
        for (int i = idx; i < caption.length(); i++) {
            if (caption[i] == ' ') {
                flag = true;
                continue;
            }
            if (flag ) {
                s += (char)toupper(caption[i]);
                flag = false;
            } else {
                s += (char)tolower(caption[i]);
            }
        }
        return s.substr(0,100);


    }
};