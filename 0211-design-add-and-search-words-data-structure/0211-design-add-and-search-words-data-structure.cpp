class Node{
    public:
        Node* links[26];
        bool isEnd = false;
        Node(){
            for(int i = 0; i < 26; i++)
                links[i] = NULL;
            isEnd = false;
        }
};

class WordDictionary {
private:
    Node* root;

    bool func(int i, int n, string &word, Node* root){
        if( i == n ) return root->isEnd;
        if( !root ) return 0;
        bool flag = 0;
        if( word[i] == '.' ){
            for(int j = 0; j < 26; j++){
                if( root->links[j] )
                    flag |= func(i + 1, n, word, root->links[j]);
            }
        }
        else{
            if( !root->links[word[i] - 'a'] ) return 0;
            flag |= func(i + 1, n, word, root->links[word[i] - 'a']);
        }
        return flag;
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* tRoot = root;
        for(auto &a : word){
            if( tRoot->links[a - 'a'] == NULL )
                tRoot->links[a - 'a'] = new Node();
            tRoot = tRoot->links[a - 'a'];
        }
        tRoot->isEnd = true;
    }
    
    bool search(string word) {
        Node* tRoot = root;
        bool flag = func(0, word.size(), word, tRoot);
        return flag;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */