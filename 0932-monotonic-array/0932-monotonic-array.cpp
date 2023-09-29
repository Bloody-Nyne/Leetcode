class Solution {
public:
    bool solve1(vector<int>& nums,int n){
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
    bool solve2(vector<int>& nums,int n){
        for(int i=0;i<n-1;i++){
            if(nums[i] < nums[i+1]) return false;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increase = solve1(nums,n);
        bool decrease = solve2(nums,n);
        return increase || decrease;
    }
};