class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        for(int i=0;i<n;i++){
            long long int sum = 0;
            int temp = nums[i];

            for(int j=i;j>=0;j--){
                temp = min(temp,nums[j]);
                sum += temp;
            }

            temp = nums[i];
            for(int j=i+1;j<n;j++){
                temp = min(temp,nums[j]);
                sum += temp;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};