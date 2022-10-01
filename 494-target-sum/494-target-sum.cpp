class Solution {
public:
    int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i=0;i<n;i++) sum += arr[i];
    if(sum - d < 0 || (sum - d)%2) return false;
    int target = (sum - d) / 2;
    vector<int> prev(target+1,0),cur(target+1,0);
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=target;sum++){
            int notpick = prev[sum];
            int pick = 0;
            if(arr[i] <= sum) pick = prev[sum-arr[i]];
            cur[sum] = (pick + notpick);
        }
        prev = cur;
    }
    return prev[target];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};