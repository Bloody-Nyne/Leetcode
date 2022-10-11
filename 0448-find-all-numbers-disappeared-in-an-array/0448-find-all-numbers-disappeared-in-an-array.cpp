class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto it: nums) mp[it]++;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(mp.find(i) == mp.end()) ans.push_back(i);
        }
        return ans;
    }
};