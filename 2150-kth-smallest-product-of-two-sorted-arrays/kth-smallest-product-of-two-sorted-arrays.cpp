
class Solution {

public:
long long findCountSmallest(vector<int>& nums1, vector<int>& nums2,long long midproduct){
    long long productCount=0;
    int n=nums2.size();
    for(int i=0;i<nums1.size();i++){
        if(nums1[i]>=0){
            int l=0;
            int r=n-1;
            int m=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                long long prod=1LL*nums1[i]*nums2[mid];
                if(prod<=midproduct){
                    m=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            productCount+=m+1;
        }
        else{
            int l=0;int r=n-1;
            int m=n;
            while(l<=r){
                int mid=l+(r-l)/2;
                long long prod=1LL*nums1[i]*nums2[mid];
                if(prod<=midproduct){
                    m=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            productCount+=n-m;

        }
    }
    return productCount;
}
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        long long l=-1e10;//min product possile
        long long r=1e10;//max product psooibel
        long long result=0;;
        while(l<=r)
        {
            long long midproduct=l+(r-l)/2;
            //check if its kth smaleest
            long long countSmallest=findCountSmallest(nums1,nums2,midproduct);
            if(countSmallest>=k){
                result=midproduct;
                r=midproduct-1;
            }
            else{
                l=midproduct+1;
            }
        }
        return result;
    }
};