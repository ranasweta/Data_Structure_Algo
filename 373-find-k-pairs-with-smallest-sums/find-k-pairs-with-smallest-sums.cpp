class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P,vector<P>,greater<P>> pq;
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>>result;
        int sum=nums1[0]+nums2[0];//as shuru me apka pehla elemnets ka sum 
        pq.push({sum,{0,0}});
        set<pair<int,int>> visited;
        visited.insert({0,0});
        while(k-- && !pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int i=curr.second.first;
            int j=curr.second.second;
            result.push_back({nums1[i],nums2[j]});
            //push(i,j+1) with its sum
            if(j+1<n && visited.find({i,j+1})==visited.end()){
                sum=nums1[i]+nums2[j+1];
                visited.insert({i,j+1});
                pq.push({sum,{i,j+1}});
            }
            //push(i+1,j)
            if(i+1<m && visited.find({i+1,j})==visited.end()){
                sum=nums1[i+1]+nums2[j];
                visited.insert({i+1,j});
                pq.push({sum,{i+1,j}});
            }

        }
        return result;
    }
};