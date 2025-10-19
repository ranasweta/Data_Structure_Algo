class Solution {
public:
//rotation trick
void rotate(string &s,int b){
    reverse(begin(s),end(s));
    reverse(begin(s),begin(s)+b);
    reverse(begin(s)+b,end(s));

}
    string findLexSmallestString(string s, int a, int b) {
        string smalleststr=s;
        unordered_set<string> visited;
        visited.insert(s);
        queue<string> que;
        que.push(s);
        while(!que.empty()){
            string curr=que.front();
            que.pop();
            if(curr<smalleststr) smalleststr=curr;
            string c=curr;
            //add a starting with 1 as it wants to change only odd indices
            for(int i=1;i<curr.length();i+=2){
                c[i]=((c[i]-'0'+a)%10 )+ '0';
            }
            if(!visited.count(c)){
                visited.insert(c);
                que.push(c);
            }
            //rotate by b
            rotate(curr,b);
            if(!visited.count(curr)){
                visited.insert(curr);
                que.push(curr);
            }

        }
        return smalleststr;
    }
};