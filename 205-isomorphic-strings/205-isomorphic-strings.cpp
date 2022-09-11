class Solution {
public:
    bool helper(string s,string t){
        unordered_map<char,char> mpp;
        for(int i=0;i<s.length();i++){
            if(mpp.find(s[i]) != mpp.end()){
                if(mpp[s[i]] != t[i]) return false;
            }
            else{
                mpp[s[i]] = t[i];
            }
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return helper(s,t) && helper(t,s);
    }
};