class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int m = mat.size();
        for(int i = 0 ; i < mat.size() ; i++ ) {
                sum += mat[i][i] + mat[i][m-i-1];  
                if(m % 2 == 1 && i == m/2) sum -= mat[i][i];     
        }
        return sum;
    }
};