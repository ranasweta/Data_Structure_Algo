class Solution {
public:
    int digitsum(int n)
{
    int sum = 0;
    while (n > 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        int n=nums.size();
for(int i=0;i<n;i++)
{
   if (mp.find(digitsum(nums[i]))==mp.end()){
    vector<int>v1;
    v1.push_back(nums[i]);
    mp[digitsum(nums[i])]=v1;
   }
   else{    
    mp[digitsum(nums[i])].push_back(nums[i]);
    }
}

int sum=-1;
for(auto it=mp.begin();it!=mp.end();it++){
    sort(it->second.begin(),it->second.end());
    if(it->second.size()>=2)
    sum=max(it->second[it->second.size()-1]+it->second[it->second.size()-2],sum);
    
    }
return sum;
   


    }
};