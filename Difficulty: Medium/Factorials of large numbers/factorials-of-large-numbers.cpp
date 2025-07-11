// User function template for C++

class Solution {
  public:
  void multiply( vector<int> & arr,int multiplier,int & size){
      int carry=0;
      for(int i=0;i<size;i++){
          int res=multiplier*arr[i]+carry;
         
          arr[i]=res%10;
          carry=res/10;
      }
      while(carry>0){
          arr[size++]=carry%10;
          carry=carry/10;
         
      }
  }
    vector<int> factorial(int n) {
        // code here
        vector<int> arr(10000,0);
        int size=1;
        arr[0]=1;
        for(int i=2;i<=n;i++){
            multiply(arr,i,size);
        }
        vector<int>result;
        for(int i=size-1;i>=0;i--){
            result.push_back(arr[i]);
        }
        return result;
    }
};