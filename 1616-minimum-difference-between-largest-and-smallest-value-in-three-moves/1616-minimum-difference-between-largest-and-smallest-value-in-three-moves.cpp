class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;

        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        for(int i=0;i<=3;i++) {
            int large = nums[n-i-1];
            int small = nums[3-i];

            mini = min(mini, (large-small));
        }

        return mini;
    }
};