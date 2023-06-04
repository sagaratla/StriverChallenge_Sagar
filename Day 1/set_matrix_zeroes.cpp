class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // leave the first row and column to store the inner matrix zero info
        bool setFirstRowZero = false, setFirstColZero = false;
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // cols
        for(int i=0;i<n;i++) {
            if(matrix[i][0] == 0) {
                setFirstColZero = true;
            }
        }
        
        for(int j=0;j<m;j++) {
            if(matrix[0][j] == 0) {
                setFirstRowZero = true;
            }
        }
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // check all rows ---->
        for(int i=1;i<n;i++) {
            if(matrix[i][0] == 0) {
                for(int j=1;j<m;j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // check all cols <||||>
        for(int j=1;j<m;j++) {
            if(matrix[0][j] == 0) {
                for(int i=1;i<n;i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(setFirstRowZero == true) {
            for(int j=0;j<m;j++) {
                matrix[0][j] = 0;
            }
        }
        
        if(setFirstColZero == true) {
            for(int i=0;i<n;i++) {
                matrix[i][0] = 0;
            }
        }
    }
};