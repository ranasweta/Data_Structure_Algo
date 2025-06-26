class Solution {
public://greedyly ulta chalte hai 10->3
/*
+1 kro ya divide by 2
10/2=5(odd)
5+1=6 even
6/2=3odd
3+1=4
4/2=even(start)
*/
    int brokenCalc(int startValue, int target) {
        
        int operation=0;
        while(target>startValue){
            if(target%2==0){
                target=target/2;
            }
            else{
                target=target+1;
            }
            operation++;
        }
        return operation + startValue-target;
    }
};