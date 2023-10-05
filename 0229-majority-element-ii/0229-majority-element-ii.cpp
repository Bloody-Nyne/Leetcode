class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0,num2 = 0,cnt1 = 0,cnt2 = 0;
        for(int i=0;i<n;i++){
            int ele = nums[i];
            if(ele == num1) cnt1++;
            else if(ele == num2) cnt2++;
            else if(cnt1 == 0) {
                num1 = ele;
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                num2 = ele;
                cnt2 = 1;
            }
            else{
                cnt1--;cnt2--;
            }
        }
        vector<int> ans;
        int c1 = 0,c2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == num1) c1++;
            else if(nums[i] == num2) c2++;
        }
        if(c1 > n/3) ans.push_back(num1);
        if(c2 > n/3) ans.push_back(num2);
        return ans;
    }
};