class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        long long ans = 0;
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int total = n;
        vector<bool>visited(n, false);
        for(int i=0; i<n; i++){
            if(visited[i]) continue;

            int neighbors = 0;
            dfs(i, adj, visited, neighbors);
            // cout<<i<<' '<<neighbors<<' '<<total<<' ';
            total -= neighbors;
            // cout<<total<<endl;
            ans += (long long)neighbors * total * 1LL;
            // cout<<ans<<endl;
        }
        return ans;
    }

    void dfs(int cur, vector<vector<int>>&adj, vector<bool>&visited, int &neighbors){
        if(visited[cur]) return;
        
        visited[cur] = true;
        neighbors++;
        for(auto a: adj[cur]){
            dfs(a, adj, visited, neighbors);
        }
    }
};