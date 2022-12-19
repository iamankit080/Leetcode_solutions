class Solution {
public:
    bool dfs(int src, int dest , vector<int> adj[] , vector<int> &vis){
        vis[src]=1;
        if (src==dest) return true;
        for(auto it:adj[src]){
            if(!vis[it]) if(dfs(it,dest,adj,vis)==true) return true;
            
        }
        return false;
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector <int> adj[n];
        for (auto it: edges){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
            
        }
        int cnt=0;
        vector<int>vis(n,0);
        return dfs(source,destination,adj,vis);
    }
};