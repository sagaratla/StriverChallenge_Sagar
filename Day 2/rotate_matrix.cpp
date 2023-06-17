class Solution {
public:
    void printMat(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<< mat[i][j] << " ";
            }
            cout<<"\n";
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int d=0; d<n;d++) {
            for(int idx=d+1;idx<n;idx++) {
                int temp = matrix[d][idx];
                matrix[d][idx] = matrix[idx][d];
                matrix[idx][d] = temp;
            }
        }
        // printMat(matrix);
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n/2;j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
        
        // printMat(matrix);
    }
};