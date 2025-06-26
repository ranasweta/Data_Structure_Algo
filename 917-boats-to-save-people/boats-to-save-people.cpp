class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        sort(begin(people),end(people));
        int boat=0;
        while(i<=j){
            if(people[j]+people[i]>limit){
                boat++;
                j--;
            }
            else{
                boat++;
                j--;
                i++;
            }
        }
        return boat;
    }
};