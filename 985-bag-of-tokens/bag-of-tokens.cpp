class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int n=tokens.size();
        sort(begin(tokens),end(tokens));
        int mxscore=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                score++;
                mxscore=max(mxscore,score);
            }
            else if(score>=1){
                power+=tokens[j];
                j--;
                score--;
            }
            else{
                return mxscore;
            }
        }
        return mxscore;
    }
};