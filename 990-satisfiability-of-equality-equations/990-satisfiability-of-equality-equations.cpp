class Solution {
public:
    int parent[26];
    int findParent(int x){
        
        return parent[x]= parent[x]==x? x: findParent(parent[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<26; i++)
            parent[i]=i;
        for(auto eq: equations){
            if(eq[1] == '='){
                parent[findParent(eq[0]-'a')] = findParent(eq[3]-'a');
            }
            
            
            
        }
        for(auto eq: equations){
            if(eq[1] == '!' and findParent(eq[0]-'a') == findParent(eq[3]-'a')){
                return false;
            }
    }
        return true;
    }
};