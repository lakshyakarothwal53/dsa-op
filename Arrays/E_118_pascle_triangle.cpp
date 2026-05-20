/*
LeetCode 118 - Pascal's Triangle

Problem summary:
Given an integer numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle is a triangular array where each element is the sum of the two elements directly above it.
The edges of each row are always 1.

Example:
numRows = 5 produces:
    [1]
    [1,1]
    [1,2,1]
    [1,3,3,1]
    [1,4,6,4,1]

Approach used in this implementation:
- Handle the base case: if numRows == 1, return {{1}}.
- Initialize with the first two rows: {{1}, {1,1}}.
- For each subsequent row i (from 2 to numRows-1):
    - Create a new row of size i+1, filled with 1s (for the edges).
    - Fill the middle elements: temp[j] = out[i-1][j-1] + out[i-1][j].
      This sums the two elements from the previous row.
    - Add the row to the result.

Why this works:
- Each row in Pascal's triangle is built from the previous row by summing adjacent pairs.
- The first and last elements of each row are always 1.

Time & Space complexity:
- Time: O(numRows^2), as we compute all elements of all rows up to numRows.
- Space: O(numRows^2), for storing the entire triangle.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
         vector<vector<int>> out = {{1},{1,1}};
        for(int i = 2 ; i < numRows ; i++){
            vector<int> temp(i+1 , 1);
            for(int j = 1 ; j < i ; j++){
                temp[j] = out[i-1][j-1] + out[i-1][j];
            }
            out.push_back(temp);
        }
    return out; 
    }
};