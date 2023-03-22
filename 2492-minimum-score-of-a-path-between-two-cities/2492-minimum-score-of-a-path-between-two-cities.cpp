class Solution {
private:
    class DSU{
    public:
        vector<int> par;
        DSU(int n){
            par.resize(n);
            for(int i = 0; i < n; i++) par[i] = i;
        }
        int findPar(int n){
            if( n == par[n] ) return n;
            return par[n] = findPar(par[n]);
        }
        void merge(int a, int b){
            a = findPar(a), b = findPar(b);
            if( a == b ) return;
            par[b] = a;
        }
    };

    void dfs(int node, vector<pair<int, int>> graph[], vector<bool> &isVis, int &minDist){
        // if( isVis[node] ) return;
        isVis[node] = 1;
        for(auto &a : graph[node]){
            minDist = min(minDist, a.second);
            if( isVis[a.first] ) continue;
            dfs(a.first, graph, isVis, minDist);
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> graph[n];
        DSU st(n);
        for(auto &a : roads){
            int u = a[0] - 1;
            int v = a[1] - 1;
            int wt = a[2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
            st.merge(u, v);
        }
        if( st.findPar(0) != st.findPar(n - 1) ) return -1;
        int minDist = 1e9;
        vector<bool> isVis(n, 0);
        dfs(0, graph, isVis, minDist);
        for(int i = 0; i < n; i++) isVis[i] = 0;
        dfs(n - 1, graph, isVis, minDist);
        return minDist;
    }
};