class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;++i) mp[s[i]]++;
        int cnt = 0;
        bool flag = false;
        
        for(auto &it: mp) {
            if(it.second % 2 == 0) cnt += it.second;
            else{
                cnt += it.second-1;
                flag = true;
            }
        }

        if(flag) return cnt+1;

        return cnt;
    }
};