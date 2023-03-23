class DSUst{
public:
    vector<int> par;

    DSUst(int n){
        par.resize(n);
        for(int i = 0; i < n; i++) par[i] = i;
    }

    int findPar(int n){
        if( n == par[n] ) return n;
        return par[n] = findPar(par[n]);
    }

    void merge(int a, int b){
        // cout << a << " " << b << endl;
        a = findPar(a);
        b = findPar(b);
        if( a == b ) return;
        // cout << a << " " << b << endl;
        par[a] = b;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSUst st(n);
        for(auto &a : connections){
            int &u = a[0];
            int &v = a[1];
            // cout << u << " " << v << endl;
            st.merge(u, v);
        }
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(st.findPar(i));
        int reqCables = n - 1;
        int avaiCables = connections.size();
        cout << reqCables << endl;
        if( reqCables > avaiCables ) return -1;
        return s.size() - 1;
    }
};