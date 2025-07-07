class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(begin(events),end(events));
        int cnt=0;//result
        int i=0;//start
        int day=events[0][0];
        while(!pq.empty() || i<n){
            //if start date is same
            while(i<n && day==events[i][0] ){
                pq.push(events[i][1]);//pushing end date to sort it 
                i++;
            }

            day++;
            if(!pq.empty()){
                pq.pop();//the one which which ending will be poped
            cnt++;
            }
            //skip those days whose endday<day
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }
        return cnt;
    }
};