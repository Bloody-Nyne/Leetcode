class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;

        trieNode(char ch){
            this->data=ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie {
public:
    trieNode* root ;
    /** Initialize your data structure here. */
    Trie() {
        root=new trieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(trieNode* root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal=true;
            return;
        }
        //assumption: all charcters are in CAPS
        int index=word[0]-'a';
        trieNode* child;

        //present case
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            //absent case
            child=new trieNode(word[0]);
            root->children[index]=child;
        }

        //RECURSION( FOR NEXT CHARCTERS IN THE WORDS)
        insertUtil(child,word.substr(1)); //word.substr(1)->it will send the word except for the first charcter for the next recursion
        }
    
    void insert(string word) {
        insertUtil(root,word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(trieNode* root,string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }
        //assumption: all charcters in the string are in CAPS
        int index=word[0]-'a';
        trieNode* child;

        //present case
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            //absent case
            return false;
        }

        //RECURSION FOR THE REMAINING CHARCTERS IN THE STRING
        return searchUtil(child,word.substr(1)); //word.substr(1)-> it will send the string except the first charcter for the next recursion
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixUtil(trieNode* root,string word){
        //base case
        if(word.length() == 0){
            return true;
        }
        //assumption: all charcters in the string are in CAPS
        int index=word[0]-'a';
        trieNode* child;

        //present case
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            //absent case
            return false;
        }

        //RECURSION FOR THE REMAINING CHARCTERS IN THE STRING
        return prefixUtil(child,word.substr(1)); //word.substr(1)-> it will send the string except the first charcter for the next recursion
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */