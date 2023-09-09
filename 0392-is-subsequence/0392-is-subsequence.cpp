class Solution {
public:
    int solve(int i,int j,string s,string t){
        if(i < 0 || j < 0) return 0;

        if(s[i] == t[j]) return 1 + solve(i-1,j-1,s,t);
        else return 0 + solve(i,j-1,s,t);
    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n > m) return false;
        int len = solve(n-1,m-1,s,t);
        return len == n;
    }
};