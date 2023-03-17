class Trie {
private:
    
    class Node{
    public:
        Node* links[26];
        bool isEnd;

        Node(){
            for(int i = 0; i < 26; i++)
                links[i] = NULL;
            isEnd = false;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* tRoot = root;
        for(auto &a : word){
            if( !tRoot->links[a - 'a'] )
               tRoot->links[a - 'a'] = new Node();
            tRoot = tRoot->links[a - 'a'];
        }
        tRoot->isEnd = true;
    }
    
    bool search(string word) {
        Node* tRoot = root;
        for(auto &a : word){
            if( !tRoot->links[a - 'a'] ) return 0;
            tRoot = tRoot->links[a - 'a'];
        }
        return tRoot->isEnd;
    }
    
    bool startsWith(string prefix) {
         Node* tRoot = root;
        for(auto &a : prefix){
            if( !tRoot->links[a - 'a'] ) return 0;
            tRoot = tRoot->links[a - 'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */