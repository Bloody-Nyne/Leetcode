class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,num1=-1,num2=-1;
        int n=nums.size();
        for(auto x: nums){
            if(x == num1)
                cnt1++;
            else if(x == num2)
                cnt2++;
            else if(cnt1 == 0){
                num1=x;
                cnt1=1;
            }
            else if(cnt2 == 0){
                num2=x;
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0,cnt2=0;
        for(auto x: nums){
            if(x == num1)
                cnt1++;
            else if(x == num2)
                cnt2++;
        }
        
        if(cnt1 > n/3)
            ans.push_back(num1);
        if(cnt2 > n/3)
            ans.push_back(num2);
        
        return ans;
    }
};