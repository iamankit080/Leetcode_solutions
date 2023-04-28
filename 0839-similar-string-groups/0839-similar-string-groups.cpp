class Solution {
private:
    bool sameGrp(string &a, string &b){
        int n = a.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if( a[i] != b[i] ) cnt += 1;
        }
        return cnt <= 2;
    }

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
                par[a] = b;
            }
    };

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU st(n);
        vector<int> graph[n];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if( sameGrp(strs[i], strs[j]) ){
                    st.merge(i, j);
                } 
            }
        }
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(st.findPar(i));
        return (int)s.size();
    }
};