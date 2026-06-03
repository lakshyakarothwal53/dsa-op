/*
LeetCode 74 - Search a 2D Matrix

Problem summary:
Write an efficient algorithm that searches for a value target in an m x n integer matrix.
The matrix has the following properties:
- Integers in each row are sorted from left to right
- Integers in each column are sorted from top to bottom
- Each row's first integer is greater than the previous row's last integer

Example:
matrix = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]], target = 5 -> Output: true
matrix = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]], target = 13 -> Output: true
matrix = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]], target = 15 -> Output: false

Approach used in this implementation (Staircase Search):
- Start from the top-right corner (or bottom-left corner) of the matrix
- This position is chosen because it's at the boundary between small and large numbers
- Compare the target with the current element:
  - If equal, return true (found)
  - If current element > target, move left (j--) because all elements below are larger
  - If current element < target, move down (i++) because all elements to the left are smaller
- Continue until we find the target or go out of bounds
- Return false if not found

Why this works:
- Starting from top-right, we can eliminate either a row or column with each comparison
- If we move left, we eliminate the current column (all elements in it are >= current, and > target)
- If we move down, we eliminate the current row (all elements in it are <= current, and < target)
- This ensures we never miss the target while searching efficiently

Visual representation (matrix = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]], target = 5):
Start at (0,3) = 11
11 > 5, move left to (0,2) = 7
7 > 5, move left to (0,1) = 4
4 < 5, move down to (1,1) = 5
5 == 5, FOUND! Return true

Algorithm walkthrough (nums = [[1,4,7,11],[2,5,8,12],[3,6,9,16],[10,13,14,17]], target = 5):
Initial: i=0, j=3 (top-right corner)
Step 1: matrix[0][3]=11, 11 > 5, j=2
Step 2: matrix[0][2]=7, 7 > 5, j=1
Step 3: matrix[0][1]=4, 4 < 5, i=1
Step 4: matrix[1][1]=5, 5 == 5, return true

Time & Space complexity:
- Time: O(m + n), in worst case we traverse one row and one column
- Space: O(1), only using two pointers

Alternative: You could also use binary search twice (binary search first row to find which row, 
then binary search that row) for O(log m + log n) = O(log(m*n)), but the staircase approach is simpler.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while(i < m and j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else i++;
        }
        return false;
    }
};