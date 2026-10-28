class Node {
    
    public:
        vector<Node*> vec;
        bool end;
        
        Node() {
            vec.resize(26, NULL);
            end = false;
        }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        int n = word.size();
        for(int i=0; i<n; i++) {
            char c = word[i];
            int ind = c - 'a';
            if(!temp->vec[ind]) {
                temp->vec[ind] = new Node();
            }
            temp = temp->vec[ind];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        int n = word.size();
        for(int i=0; i<n; i++) {
            char c = word[i];
            int ind = c - 'a';
            if(!temp->vec[ind]) return false;
            temp = temp->vec[ind];
        }
        if(temp->end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        int n = prefix.size();
        for(int i=0; i<n; i++) {
            char c = prefix[i];
            int ind = c - 'a';
            if(!temp->vec[ind]) return false;
            temp = temp->vec[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */