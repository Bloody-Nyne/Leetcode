class Solution {
public:
    string largestOddNumber(string nums) {
        int n=nums.length();
        for(int i=n-1;i>=0;i--){
            int isOdd=nums[i] - '0';
            if(isOdd % 2 != 0)
                return nums.substr(0,i+1);
        }
        return "";
    }
};