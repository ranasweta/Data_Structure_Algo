class Solution {
public:
    vector<char> vowels={'a','A','e','E','i','I','o','O','u','U'};
    bool isVowel(char c){
        for( char ch : vowels){
            if(c==ch){
                return true;
            }
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(isVowel(s[i])){
                if(isVowel(s[j])){
                    char ch=s[i];
                    s[i]=s[j];
                    s[j]=ch;
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};