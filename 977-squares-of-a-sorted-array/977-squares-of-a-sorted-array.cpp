class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int s=0;
        int e=n-1;
        int k=s+e;
        while(s<=e){
            if(abs(nums[s])<abs(nums[e])){
                ans[k--] = nums[e]*nums[e--];
            }
            else{
                ans[k--] = nums[s]*nums[s++];
            }
        }
        return ans;
    }
};