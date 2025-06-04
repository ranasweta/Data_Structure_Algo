class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1){
            return word;
        }
        int lg=n-numFriends+1;//hum itna bada le skte hai apni string   
        string mxst= word.substr(0,lg);
        for(int i=0;i<n;i++){
            string temp=word.substr(i,min(n-i,lg));
            mxst=max(mxst,temp);
        }
        return mxst;

    }
};