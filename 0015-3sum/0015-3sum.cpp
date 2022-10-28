class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {{}};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int target = -nums[i];
            int j = i+1,k = n-1;
            while(j<k){
                int element = nums[j] + nums[k];
                if(element < target) j++;
                else if(element > target) k--;
                else{
                    vector<int> temp(3,0);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    ans.push_back(temp);
                
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++,k--;
                }
            }
        }
        return ans;
    }
};