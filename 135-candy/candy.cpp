class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=n;
        int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]) {
                i++;
            continue;}
            int peak=0;
            while( i<n && ratings[i]>ratings[i-1]){
                i++;
                peak++;
                sum+=peak;
                // if(i==n){
                //     return sum;
                // }


            }
            int dip=0;
            while(i<n && ratings[i]<ratings[i-1]){
                dip++;
                i++;
                sum+=dip;
            }
            sum-=min(peak,dip);

        }
        return sum;

    }
};