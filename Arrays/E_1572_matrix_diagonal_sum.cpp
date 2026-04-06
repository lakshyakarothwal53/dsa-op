
/*
LeetCode 1572 - Matrix Diagonal Sum

Problem summary:
Given a square matrix mat, return the sum of its primary diagonal (top-left to bottom-right) and secondary diagonal (top-right to bottom-left).
If the matrix has odd size, the center element is counted twice, so subtract it once.

Approach used in this implementation:
- Loop through each row i:
    - Add mat[i][i] (primary diagonal)
    - Add mat[i][n-i-1] (secondary diagonal)
- If the matrix size is odd, subtract the center element once (as it was added twice).

Why this works:
- The primary diagonal consists of elements where row == col.
- The secondary diagonal consists of elements where row + col == n - 1.
- For odd n, the center element is at (n/2, n/2) and is on both diagonals.

Time & Space complexity:
- Time: O(n), Space: O(1), where n = number of rows/columns.
*/
// ...existing code...

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