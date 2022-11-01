class Trie {
public:
    
    struct Node {
        struct Node* link[26];
        bool end;
    };
    
    struct Node *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        struct Node *curr = root;
        for(int i = 0; i<word.size(); i++) {
            char ch = word[i];
            if(curr->link[ch - 'a'] ==  NULL) {
                struct Node *newNode = new Node();
                curr->link[ch - 'a'] = newNode;
            }
            curr = curr->link[ch - 'a'];
            if(i== word.size()-1) {
                curr->end = true;
            }
        }
    }
    
    bool search(string word) {
        struct Node *curr = root;
        for(int i = 0; i<word.size(); i++) {
            char ch = word[i];
            if(curr->link[ch - 'a'] ==  NULL) {
                return false;
            }
            curr = curr->link[ch - 'a'];
            if(i == word.size()-1 && curr->end == true) {
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string word) {
        struct Node *curr = root;
        for(int i = 0; i<word.size(); i++) {
            char ch = word[i];
            if(curr->link[ch - 'a'] ==  NULL) {
                return false;
            }
            curr = curr->link[ch - 'a'];
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