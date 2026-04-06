
/*
LeetCode 304 - Range Sum Query 2D - Immutable

Problem summary:
Given a 2D matrix, design a data structure that can quickly return the sum of the elements inside a submatrix defined by its upper left (row1, col1) and lower right (row2, col2) corners.

Approach used in this implementation:
- Build a 2D prefix sum matrix `prefix` where prefix[i][j] stores the sum of all elements in the rectangle from (0,0) to (i,j).
- To answer sumRegion(x1, y1, x2, y2):
    - Start with prefix[x2][y2] (sum from (0,0) to (x2,y2)).
    - Subtract the areas above and to the left of the query rectangle, and add back the overlap (if any):
        sum = prefix[x2][y2]
              - prefix[x2][y1-1] (if y1 > 0)
              - prefix[x1-1][y2] (if x1 > 0)
              + prefix[x1-1][y1-1] (if x1 > 0 and y1 > 0)

Why this works:
- Inclusion-exclusion principle: removes the extra areas outside the query rectangle.

Time & Space complexity:
- Preprocessing (constructor): O(m*n) time and space to build the prefix matrix.
- Query (sumRegion): O(1) time per query.
*/
// ...existing code...

class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {    
        int m = matrix.size();
        int n = matrix[0].size();
        prefix = vector<vector<int>> (m, vector<int>(n, 0));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++) {
                if(i) prefix[i][j] += prefix[i-1][j];
                if(j) prefix[i][j] += prefix[i][j-1];
                if(i && j) prefix[i][j] -= prefix[i-1][j-1];
                prefix[i][j]+=matrix[i][j];
            }
        }
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        int sum = prefix[x2][y2];
        if(y1) sum -= prefix[x2][y1 - 1];
        if(x1) sum -= prefix[x1 - 1][y2];
        if(x1 && y1) sum += prefix[x1-1][y1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */