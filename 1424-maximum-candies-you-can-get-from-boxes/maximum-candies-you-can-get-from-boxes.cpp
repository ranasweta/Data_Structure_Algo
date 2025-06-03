class Solution {
public: // bfs
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        unordered_set<int> visited;
        unordered_set<int> found;
        int c = 0; // apni total candies
        // pehle un boxes se candies lelo jo opened hai and intial me matlab ek
        // level or unhe visited bhi krdo
        queue<int> que;
        for (int & box : initialBoxes) {

                found.insert(box);
            if (status[box] == 1) {
                que.push(box);
            visited.insert(box);
                c += candies[box];
            }
        }
        // ab vahi purana tareeka jisme bfs ki queue use hoti hai and fir
        // visited mark krna hai pehle contained me jana hai fir keys me jana h
        // agar vo vsisited nhi h toh unhe que me daldo
        while (!que.empty()) {
            int box = que.front();
            que.pop();
            for (auto& insidebox : containedBoxes[box]) {
                found.insert(insidebox);
                if (!visited.count(insidebox) && status[insidebox] == 1) {
                    c += candies[insidebox];
                    visited.insert(insidebox);
                    que.push(insidebox);
                }
            }
            for (auto& key : keys[box]) {
                status[key]=1;
                if (!visited.count(key) && found.count(key)) {
                    c += candies[key];
                    visited.insert(key);
                    que.push(key);
                }
            }
        }
        return c;
    }
};