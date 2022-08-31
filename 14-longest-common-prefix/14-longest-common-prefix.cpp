class trieNode{
    public:
    char data;
    trieNode* children[26];
    int childCount;
    bool isTerminal;
    
    trieNode(char ch){
        this->data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class trie{
    public:
    trieNode* root;
    
    trie(char ch){
        root=new trieNode(ch);
    }
    
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
            root->childCount++;
            root->children[index]=child;
        }

        //RECURSION( FOR NEXT CHARCTERS IN THE WORDS)
        insertUtil(child,word.substr(1)); //word.substr(1)->it will send the word except for the first charcter for the next recursion
    }

    void insertWord(string word){
        insertUtil(root,word);
    }
    
    void lcp(string str,string &ans){
        
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->isTerminal){
                break;
            }
            
            if(root->childCount == 1){
                ans.push_back(ch);
                //ab aage badh jao
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        trie* t=new trie('\0');
        for(int i=0;i<n;i++){
            t->insertWord(strs[i]);
        }
        string first=strs[0];
        string ans="";
        t->lcp(first,ans);
        
        return ans;
    }
};