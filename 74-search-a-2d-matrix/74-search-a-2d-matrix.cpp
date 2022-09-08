class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0,e=m*n-1,mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(matrix[mid/m][mid%m] < target)
                s=mid+1;
            else if(matrix[mid/m][mid%m] > target)
                e=mid-1;
            else{
                return true;
            }
        }
        return false;
    }
};