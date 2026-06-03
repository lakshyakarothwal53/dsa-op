/*
LeetCode 88 - Merge Sorted Array

Problem summary:
You are given two sorted integer arrays nums1 and nums2, and integers m and n representing the number of valid elements in each array.
Merge nums2 into nums1 as one sorted array in-place. Do not return anything, modify nums1 in-place instead.
Note: nums1 has a length of m + n, so there is enough space to hold additional elements from nums2.

Example:
nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 -> nums1 = [1,2,2,3,5,6]
nums1 = [1], m = 1, nums2 = [], n = 0 -> nums1 = [1]
nums1 = [0], m = 0, nums2 = [1], n = 1 -> nums1 = [1]

Approach used in this implementation (Two-pointer from the end):
- Use three pointers:
  - i: points to the last element of valid nums1 (starts at m-1)
  - j: points to the last element of nums2 (starts at n-1)
  - k: points to the last position in nums1 (starts at m+n-1)
- From the end of both arrays, compare elements and place the larger one at position k
- This avoids overwriting elements in nums1 that haven't been processed yet
- Continue until j < 0 (all elements from nums2 are merged)

Why this works:
- By filling from the end, we use the extra space in nums1 that was reserved for merged elements
- We don't need extra space because we're filling in the empty portion at the end
- Two-pointer comparison ensures the merged array stays sorted

Time & Space complexity:
- Time: O(m + n), single pass through both arrays
- Space: O(1), in-place merge without extra space
*/

// SOLUTION 1: Using Ternary Operator (Compact)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1 ; int j = n - 1 ; int k = m + n - 1;
        while (j >= 0 ) nums1[k--] = i >= 0 && nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--]; 
    }
};

/*
SOLUTION 2: Using If-Else (More Readable)
This implements the same logic but using explicit if-else statements instead of ternary operator.
*/

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Pointer to last valid element in nums1
        int j = n - 1;      // Pointer to last element in nums2
        int k = m + n - 1;  // Pointer to last position in nums1
        
        // Merge from the end while nums2 has elements
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                // If nums1 has elements AND nums1[i] is greater or equal
                nums1[k] = nums1[i];
                i--;
            } else {
                // Otherwise take from nums2
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

/*
Algorithm walkthrough (nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3):
Initial: i=2, j=2, k=5
Compare nums1[2]=3 vs nums2[2]=6: 3 < 6, take 6 -> nums1[5]=6, j=1, k=4
Compare nums1[2]=3 vs nums2[1]=5: 3 < 5, take 5 -> nums1[4]=5, j=0, k=3
Compare nums1[2]=3 vs nums2[0]=2: 3 >= 2, take 3 -> nums1[3]=3, i=1, k=2
Compare nums1[1]=2 vs nums2[0]=2: 2 >= 2, take 2 -> nums1[2]=2, i=0, k=1
Compare nums1[0]=1 vs nums2[0]=2: 1 < 2, take 2 -> nums1[1]=2, j=-1, k=0
j < 0, stop
Result: nums1 = [1,2,2,3,5,6]
*/
