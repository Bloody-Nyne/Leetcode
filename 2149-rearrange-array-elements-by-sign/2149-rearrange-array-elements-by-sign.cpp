class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp(nums);
        int posIndex=0,negIndex=1;
        for(auto x: temp){
            if(x > 0){
                nums[posIndex]=x;
                posIndex+=2;
            }
            if(x < 0){
                nums[negIndex]=x;
                negIndex+=2;
            }
        }
        return nums;
    }
};