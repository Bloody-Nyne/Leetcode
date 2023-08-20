class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = -1e9;
        int cur = 1;
        for(int i=0;i<nums.size();i++){
            cur *= nums[i];
            maxi = max(maxi,cur);
            if(cur == 0){
                cur = 1;
            }
        }
        cur = 1;
        for(int i = nums.size()-1;i>=0;i--){
            cur *= nums[i];
            maxi = max(maxi,cur);
            if(cur == 0){
                cur = 1;
            }
        }
        return maxi;
    }
};