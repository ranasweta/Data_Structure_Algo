class Solution {
public://bada solution  
    bool IsPalindrome(string b){
        int i=0;
        int j=b.size()-1;
        while(i<=j){
            if(b[i]!=b[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string ConvertToBaseK(long long pal,int k){
        if(pal==0){
            return "0";
        }
        string base="";
        while(pal>0){
            base+=to_string(pal%k);
            pal/=k;
        }
        return base;
    }
    long long kMirror(int k, int n) {
        long long sum=0;
        int L=1;//of length 1;
        while(n>0){
            int half=(L+1)/2;
            long long min_num=pow(10,half-1);
            long long max_num=pow(10,half)-1;

            for(int num=min_num;num<=max_num;num++){
                string first_half=to_string(num);
                string second_half=first_half;
                reverse(begin(second_half),end(second_half));

                string pal="";
                if(L%2==1){
                    pal=first_half+second_half.substr(1);
                }
                else{
                    pal=first_half+second_half;
                }
                long long pal_n=stoll(pal);
                string baseK=ConvertToBaseK(pal_n,k);
                if(IsPalindrome(baseK)){
                    sum+=pal_n;
                    n--;
                    if(n==0){
                        break;
                    }
                }
            }
            L++;

        }

return sum;
    }
};