/*
LeetCode 73 - Set Matrix Zeroes

Problem summary:
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0 in-place. Do this with O(1) extra space (not counting the input matrix itself).

Approach used in this implementation:
- Use the first row and first column of the matrix as markers/flags to track which rows and columns need to be zeroed.
- Use a separate variable `col` to track whether the first column itself should be zeroed (since matrix[0][0] is shared between row 0 and col 0).

Algorithm:
1. First pass (mark): Traverse the entire matrix. If matrix[i][j] == 0:
   - Set matrix[i][0] = 0 (mark the row)
   - Set matrix[0][j] = 0 (mark the column), unless j == 0, then set col = 0
2. Second pass (zero out): Traverse from (1,1) to (m-1, n-1). If matrix[i][0] == 0 or matrix[0][j] == 0, set matrix[i][j] = 0.
3. Handle the first row: If matrix[0][0] == 0, zero out the entire first row.
4. Handle the first column: If col == 0, zero out the entire first column.

Why this works:
- First row and column act as markers without needing extra space.
- We handle the first row/column separately at the end to avoid conflicts.
- The `col` variable tracks the first column state independently.

Time & Space complexity:
- Time: O(m*n), traversing the matrix twice.
- Space: O(1), using only the input matrix and two variables.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i = 0 ; 
        int j = 0 ; 
        int col = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++)
            {
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0) matrix[0][j] = 0;
                    else col = 0;
                }
            }
        }
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++)
            {
                if(matrix[i][j] != 0 ) {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
                }
                
            }
        }
        if (matrix[0][0] == 0) for (int i = 1 ; i < n ; i++) matrix[0][i] = 0;
        if( col == 0) for (int i = 0 ; i < m ; i++) matrix[i][0] = 0;
        
    }
};