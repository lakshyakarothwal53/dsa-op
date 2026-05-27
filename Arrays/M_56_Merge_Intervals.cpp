/*
LeetCode 56 - Merge Intervals

Problem summary:
Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example:
intervals = [[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]
intervals = [[1,4],[4,5]] -> [[1,5]]
intervals = [[1,2],[3,5]] -> [[1,2],[3,5]]

Approach used in this implementation (Greedy with Sorting):
Step 1: Sort intervals by their start time
- This allows us to process intervals in order and check for overlaps easily
- The compare function sorts by the first element (start time) in ascending order

Step 2: Iterate through sorted intervals
- If the result is empty OR current interval doesn't overlap with the last merged interval:
  - Add the current interval as a new interval
- If current interval overlaps with the last merged interval:
  - Extend the end of the last interval to the maximum of both ends

Why this works:
- After sorting by start time, intervals are in order from left to right
- Two intervals overlap if: current_start <= last_end
- By merging as we go, we efficiently combine all overlapping intervals
- The greedy approach works because merging overlapping intervals always results in the same merged interval

Algorithm walkthrough (intervals = [[1,3],[2,6],[8,10],[15,18]]):
After sorting: [[1,3],[2,6],[8,10],[15,18]]
i=0: out=[], add [1,3] -> out=[[1,3]]
i=1: [2,6], 2 <= 3, merge: out.back()[1] = max(3,6) = 6 -> out=[[1,6]]
i=2: [8,10], 8 > 6, add [8,10] -> out=[[1,6],[8,10]]
i=3: [15,18], 15 > 10, add [15,18] -> out=[[1,6],[8,10],[15,18]]
Result: [[1,6],[8,10],[15,18]]

Time & Space complexity:
- Time: O(n log n), dominated by sorting (n log n) + linear scan (n)
- Space: O(n), for the output array (not counting input)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> out;
        for(int i = 0 ; i < n ; i++){
            if(out.empty() || out.back()[1] < intervals[i][0]){
                out.push_back(intervals[i]);            
            } else {
                out.back()[1] = max(out.back()[1],intervals[i][1]);
            }
        }
        return out;
    }
};