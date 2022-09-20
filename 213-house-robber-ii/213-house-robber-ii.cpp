class Solution {
private:
    int houseRobber(vector<int>& nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=0;i<n;i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notpick = 0 + prev;
            int curi = max(pick,notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1,temp2;
        if(n == 1) return nums[0];
        for(int i=0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        int ans1 = houseRobber(temp1);
        int ans2 = houseRobber(temp2);
        return max(ans1,ans2);
    }
};