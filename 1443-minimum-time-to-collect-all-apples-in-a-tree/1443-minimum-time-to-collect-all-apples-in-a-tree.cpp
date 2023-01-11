class Solution {
public:
    int dfs(int node, int runningtime, int parent, vector<int> adj[], vector<bool>& hasApple)
    {
        int time = 0;
        // vis[node] = true;
        
        for(auto it: adj[node])
        {
            if(it == parent)
                continue;
            
            time += dfs(it, 2, node, adj, hasApple);
        }
        
        if(!hasApple[node] && time == 0)
            return 0;
        
//         if(hasApple[node])
//             return time + 2;
        
        return time + runningtime;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        // vector<bool> vis(n, false);
        return dfs(0, 0, -1, adj, hasApple);
    }
};