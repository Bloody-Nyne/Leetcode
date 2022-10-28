class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int curArea = 0;
        int i=0,j=n-1;
        while(i < j){
            curArea = (j-i) * min(height[i],height[j]);
            maxArea = max(maxArea,curArea);
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};