class Solution {
private:
    void backTrack(string str,int ind,vector<string>& path,vector<vector<string>>& ans){
        if(ind == str.size()){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<str.size();i++){
            if(isPalindrome(str,ind,i)){
                path.push_back(str.substr(ind,i-ind+1));
                backTrack(str,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string str,int start,int end){
        while(start <= end) if(str[start++] != str[end--]) return false;
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backTrack(s,0,path,ans);
        return ans;
    }
};