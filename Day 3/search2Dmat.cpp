class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        int top = 0, bot = rows-1;
        while(top <= bot) {
            int curr_row = (top+bot)/2;
            if(target > matrix[curr_row][cols-1]) {
                top = curr_row+1;
            } else if(target < matrix[curr_row][0]) {
                bot = curr_row-1;
            } else {
                break;
            }
        }
        
        if(top > bot) {
            return false;
        }
        
        int curr_row = (top+bot) / 2;
        // cout<<curr_row<<endl;
        
        int left = 0, right = cols-1;
        while(left<=right) {
            int mid = left + (right - left) / 2;
            if(matrix[curr_row][mid] == target) {
                return true;
            }
            
            if(matrix[curr_row][mid] > target) {
                right = mid-1;
            } else if(matrix[curr_row][mid] < target) {
                left = mid+1;
            }
        }
        
        return false;
    }
};