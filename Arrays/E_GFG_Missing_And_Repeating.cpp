// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

/*
GeeksforGeeks - Find Missing and Repeating

Problem summary:
Given an array nums of size n containing numbers from 1 to n, where one number is missing and another number is repeated.
Find and return both the missing number and the repeating number.

Example:
nums = [1,3,3,4] -> Output: [3, 2] (3 is repeated, 2 is missing)
nums = [2,2] -> Output: [2, 1] (2 is repeated, 1 is missing)
nums = [1,2,2,3] -> Output: [2, 3] (2 is repeated, 3 is missing)

Approach used in this implementation (Mark visited using sign):
- Similar to Find the Duplicate Number approach, use the sign of elements as markers
- Iterate through the array:
  - For each element, get its absolute value and use it as an index
  - If the element at that index is already negative, it means we've seen this number before -> it's the REPEATING number
  - Otherwise, mark that index as visited by negating it
- After marking phase, find the index that is still positive -> that index + 1 is the MISSING number
- Return both the repeating number and the missing number

Why this works:
- Values range from 1 to n, so abs(value) - 1 gives us a valid index in [0, n-1]
- Using sign as a marker avoids extra space
- When we find an already negative element, we know we've encountered that number twice (it's repeated)
- The index that remains positive corresponds to a number that was never visited (missing)

Algorithm walkthrough (nums = [1,3,3,4]):
Initial: nums = [1,3,3,4]
i=0: abs(1)-1=0, nums[0]=1 > 0, mark nums[0]=-1, nums=[-1,3,3,4]
i=1: abs(3)-1=2, nums[2]=3 > 0, mark nums[2]=-3, nums=[-1,3,-3,4]
i=2: abs(3)-1=2, nums[2]=-3 < 0 (already visited!), x=3 (repeating), nums=[-1,3,-3,4]
i=3: abs(4)-1=3, nums[3]=4 > 0, mark nums[3]=-4, nums=[-1,3,-3,-4]
Find positive: j=0, nums[0]=-1 (negative), j=1, nums[1]=3 (positive!), missing=1+1=2
Return: {3, 2}

Time & Space complexity:
- Time: O(n), two passes through the array (marking + finding missing)
- Space: O(1), using only variables (modifies input array)
*/

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        // code here
        int x ;
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                x = abs(nums[i]);
            }
            else nums[abs(nums[i]) - 1] *= -1;
        }
        while(nums[j] < 0) j++;
        return {x,j+1};
        
    }
};

/*
SOLUTION 2: Using Mathematical Formulas (Sum and Product)

This approach uses algebra to find the missing and repeating numbers.

Key insight:
- Let x = repeating number, y = missing number
- S = sum of all elements in array
- S_expected = sum of numbers 1 to n = n*(n+1)/2
- P = product of all elements in array
- P_expected = product of numbers 1 to n = n!

Equations:
- S - S_expected = x - y  ... (difference in sums)
- P / P_expected = x / y  ... (ratio of products, but this can overflow)

Better approach:
- Difference: diff = S - S_expected = x - y
- Product ratio: prod_ratio = P / P_expected = x / y

From these two equations:
- x - y = diff
- x / y = prod_ratio
- Solving: x = (diff + prod_ratio*y) / (prod_ratio - 1)
           y = x - diff

However, product approach can overflow, so we use:
- x - y = S - S_expected
- x + y = n*(n+1) (total sum if one number appears once and one is repeated)

Wait, simpler approach:
If we know (x - y) from sum difference and can determine x or y from other means, we can solve.

Actually, the most practical formula approach:
- diff = S - S_expected = x - y
- sq_diff = S_squares - S_squares_expected = x^2 - y^2 = (x-y)(x+y)
- Therefore: x + y = sq_diff / diff
- Solving: x = (diff + sq_diff/diff) / 2, y = (sq_diff/diff - diff) / 2
*/

class Solution2 {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        int n = nums.size();
        long long S = 0;              // Sum of array
        long long S_expected = (long long)n * (n + 1) / 2;  // Expected sum 1 to n
        long long S_squares = 0;      // Sum of squares of array
        long long S_squares_expected = (long long)n * (n + 1) * (2 * n + 1) / 6;  // Expected sum of squares
        
        for(int i = 0; i < n; i++) {
            S += nums[i];
            S_squares += (long long)nums[i] * nums[i];
        }
        
        // x - y = S - S_expected
        long long diff = S - S_expected;
        
        // x^2 - y^2 = S_squares - S_squares_expected
        // (x - y)(x + y) = S_squares - S_squares_expected
        // x + y = (S_squares - S_squares_expected) / (x - y)
        long long sq_diff = S_squares - S_squares_expected;
        long long sum = sq_diff / diff;  // x + y
        
        // From: x - y = diff and x + y = sum
        // 2x = diff + sum => x = (diff + sum) / 2
        // 2y = sum - diff => y = (sum - diff) / 2
        int x = (diff + sum) / 2;  // repeating number
        int y = (sum - diff) / 2;  // missing number
        
        return {x, y};
    }
};

/*
Example walkthrough (nums = [1,3,3,4]):
n = 4
S = 1 + 3 + 3 + 4 = 11
S_expected = 4*5/2 = 10
S_squares = 1 + 9 + 9 + 16 = 35
S_squares_expected = 4*5*9/6 = 30

diff = S - S_expected = 11 - 10 = 1  (x - y = 1)
sq_diff = S_squares - S_squares_expected = 35 - 30 = 5  (x^2 - y^2 = 5)
sum = sq_diff / diff = 5 / 1 = 5  (x + y = 5)

x = (1 + 5) / 2 = 3  (repeating)
y = (5 - 1) / 2 = 2  (missing)
Return: {3, 2}

Time & Space complexity:
- Time: O(n), single pass for sums and products
- Space: O(1), only using variables
- Advantage: Does NOT modify the input array
- Disadvantage: Works with larger numbers (uses long long to avoid overflow)
*/
