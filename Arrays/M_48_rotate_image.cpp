/*
LeetCode 48 - Rotate Image

Problem summary:
You are given an n x n 2D matrix representing an image. Rotate the image 90 degrees clockwise in-place.
Do not use extra space (other than a few variables).

Example:
[[1,2,3],        [[7,4,1],
 [4,5,6],   ->    [8,5,2],
 [7,8,9]]         [9,6,3]]

Approach used in this implementation (Transpose + Reverse):
Step 1: Transpose the matrix
- Swap elements across the main diagonal: matrix[i][j] <-> matrix[j][i]
- This converts the matrix to its transpose
- Loop through only the upper triangle (j starts from i+1) to avoid redundant swaps

Step 2: Reverse each row
- Reverse the elements in each row from left to right
- This completes the 90-degree clockwise rotation

Why this works:
- Transposing flips the matrix along the main diagonal (top-left to bottom-right)
- Reversing each row rotates it 90 degrees clockwise
- Combined: transpose + row reversal = 90 degree clockwise rotation

Visual example:
Original:          After Transpose:    After Row Reverse:
1 2 3              1 4 7               7 4 1
4 5 6      ->      2 5 8       ->      8 5 2
7 8 9              3 6 9               9 6 3

Algorithm walkthrough:
Transpose loop: i from 0 to n-1, j from i+1 to n-1
- Swaps (0,1)<->(1,0), (0,2)<->(2,0), (1,2)<->(2,1)
Row reverse: for each row, reverse all elements

Time & Space complexity:
- Time: O(n^2), visit each element twice (once for transpose, once for reverse)
- Space: O(1), in-place rotation only (excluding input matrix)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = i+1 ; j < matrix.size() ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i = 0 ; i < matrix.size() ; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};