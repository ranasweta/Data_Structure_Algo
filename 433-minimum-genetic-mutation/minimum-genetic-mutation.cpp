class Solution {
public://bfs se banega kyunki answer level wise nikal rha hai
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(begin(bank),end(bank));//for making easy to search the valid string 
        queue<string> que;
        que.push(startGene);
        unordered_set<string>visited;
        visited.insert(startGene);
        int level=0;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                string strt=que.front();
                que.pop();
                if(strt==endGene){
                    return level;
                }
                for(auto & ch:"ACGT"){
                    for(int i=0;i<strt.size();i++){
                        string neigbour=strt;
                        neigbour[i]=ch;
                        if(visited.find(neigbour)==visited.end() && bankset.find(neigbour)!=bankset.end()){
                            visited.insert(neigbour);
                            que.push(neigbour);

                        }
                    }
                }
            }
            level++;
        }
        return -1;


        
    }
};