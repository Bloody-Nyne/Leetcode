class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int> mp;
        for(auto it: nums){
            cnt += mp[it];
            mp[it]++;
        }
        return cnt;
    }
};