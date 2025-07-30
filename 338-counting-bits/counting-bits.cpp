class Solution {
public:
//observation code 
/*
1->001  ->1 
2->010  ->1 (1 is half of 2) hence same no. of bit for 1
3->011  ->2 bit(3/2) +1
4->100  ->1 bits(4/2)
5->101  ->2 bits(5/2)+1
6->110
7->111
8->1000
9->1001
*/
    vector<int> countBits(int n) {
        vector<int> result (n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2==0){
                result[i]=result[i/2];
            }
            else{
                result[i]=result[i/2]+1;

            }
        }
        return result;
    }
};