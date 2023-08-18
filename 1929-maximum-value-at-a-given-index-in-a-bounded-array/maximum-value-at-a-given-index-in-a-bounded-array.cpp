class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long int emptyR = n-index-1;
        long long int emptyL = index;
        int low = 1, high = maxSum;
        long long int ans = 0;
        while(low <= high){
            long long int mid = (low+high)/2;
            long long int leftsum = 0,rightsum = 0,el = mid-1;
            if(emptyR <= el){
                rightsum = ((el*(el+1)))/2 - ((el-emptyR)*(el-emptyR+1))/2;
            }
            else{
                rightsum = (el*(el+1))/2 + (emptyR-el);
            }
            if(emptyL <= el){
                leftsum = ((el*(el+1)))/2 - ((el-emptyL)*(el-emptyL+1))/2;
            }
            else{
                leftsum = (el*(el+1))/2 + (emptyL-el);
            }

            long long int sum = leftsum + rightsum + mid;
            if(sum <= maxSum){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};