class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int count=0;
        for(auto &x: s){
            if(s.count(x-1)) continue;
            int j = 1;
            while(s.count(x+j)) j++;
            count = max(count,j);
        }
        return count;
    }
};