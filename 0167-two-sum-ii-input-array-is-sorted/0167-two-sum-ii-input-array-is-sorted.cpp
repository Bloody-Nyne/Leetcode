class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int element = nums[i] + nums[j];
            if(element == target) return {i+1,j+1};
            else if(element < target) i++;
            else j--;
        }
        return {};
    }
};