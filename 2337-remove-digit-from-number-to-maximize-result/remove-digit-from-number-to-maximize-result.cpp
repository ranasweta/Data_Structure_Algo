class Solution {
public:
    string removeDigit(string number, char digit) {
        int idx=-1;
        int cnt=0;
        for(int i=0;i<number.size()-1;i++){
           if (number[i] == digit && stoi(std::string(1, number[i])) < stoi(std::string(1, number[i + 1])) && cnt<1) {
                idx=i;
                cnt=1;
                
            }
        }
        string temp;
        if(idx==-1){
            for (int i=number.size();i>=0;i--){
                if(number[i]==digit){
                    idx=i;
                    break;
                }
            }
        }
         for (int i=0;i<number.size();i++){
                if(i==idx){
                    continue;
                }
                temp+=number[i];
            }
            return temp;

    }
};