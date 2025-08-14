class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int n=  milestones.size();

        sort( milestones.rbegin() ,  milestones.rend());

        long long slots =  milestones[0] -1;

        for(int i=1;i<n;i++){

            slots -=   milestones[i];

        }

        long long sum = accumulate(milestones.begin() ,  milestones.end(),0LL);

        return  min(sum ,  sum - (slots));
        
    }
};