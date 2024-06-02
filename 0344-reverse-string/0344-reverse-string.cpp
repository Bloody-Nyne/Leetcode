class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0;i<n/2;++i) {
            int j = n-i-1;
            swap(s[i],s[j]);
        }
    }
};