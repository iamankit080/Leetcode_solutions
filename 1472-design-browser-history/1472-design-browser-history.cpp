class Node{
public:
    string val;
    Node* next;
    Node* prev;

    Node(string url){
        this->val = url;
        next = NULL;
        prev = NULL;
    }
};
class BrowserHistory {
public:
    Node* head;
    Node* curr;

    BrowserHistory(string homepage) {
        head = new Node(homepage);        
        curr = head;
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    
    string back(int steps) {
        while(steps--){
            if(curr->prev == NULL)
                return curr->val;
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps--){
            if(curr->next == NULL)
                return curr->val;
            curr = curr->next;
        }
        return curr->val;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */