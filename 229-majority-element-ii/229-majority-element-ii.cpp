class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> maps;
        int n=nums.size();
        for(auto x: nums){
            maps[x]++;
        }
        vector<int> ans;
        for(auto it: maps){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};