class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> s;
        bitset<1000> visited;
        bitset<1000> keysCollected;
        keysCollected[0] = 1;
        s.push(0);

        while (!s.empty()) {
            int t = s.top();
            s.pop();
            if (!visited[t]) {
                visited[t] = 1;
                for (auto i = rooms[t].begin(); i != rooms[t].end(); i++) {
                    if (!keysCollected[*i]) {
                        keysCollected[*i] = 1;
                        s.push(*i);
                    }
                }
            }
        }
        return visited.count() == rooms.size();
    }
};