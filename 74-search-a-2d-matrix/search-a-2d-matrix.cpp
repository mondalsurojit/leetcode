class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size(), l = rows*cols;
        int start=0, end=l-1, mid;
        int m, n;
        while(start <= end){
            mid = start + (end-start)/2;
            m = mid / cols, n = mid % cols;
            if(matrix[m][n] == target){
              return true;
            }else if(matrix[m][n] > target){
              end = mid -1;
            }else{
              start= mid+1;
            }
        }
        return false;
    }
};