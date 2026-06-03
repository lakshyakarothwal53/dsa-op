/*
LeetCode 50 - Pow(x, n)

Problem summary:
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
The function should handle both positive and negative exponents.

Example:
x = 2.0, n = 10 -> Output: 1024.0
x = 2.1, n = 3 -> Output: 9.261
x = 2.0, n = -2 -> Output: 0.25 (which is 1/2^2)
x = 1.0, n = 2147483647 -> Output: 1.0

Constraints: -100.0 < x < 100.0, -2^31 <= n <= 2^31-1

Approach used in this implementation (Fast Exponentiation / Exponentiation by Squaring):

Step 1: Helper function Pow(x, n) - computes x^n for non-negative n
- Base case: if n == 0, return 1 (any number to power 0 is 1)
- Recursive case:
  - Calculate power = Pow(x, n/2) (divide the exponent by 2)
  - If n is even: return power * power (x^n = (x^(n/2))^2)
  - If n is odd: return x * power * power (x^n = x * (x^(n/2))^2)

Step 2: Main function myPow(x, n) - handles negative exponents
- If n < 0: return 1 / Pow(x, -n) (negative exponent means reciprocal)
- Otherwise: return Pow(x, n) directly

Why this works:
- Exponentiation by squaring reduces the problem size by half each time (logarithmic)
- If n is even: x^n = x^(n/2) * x^(n/2)
- If n is odd: x^n = x * x^(n/2) * x^(n/2)
- For negative exponents: x^(-n) = 1 / x^n
- Recursive halving gives us O(log n) time complexity

Algorithm walkthrough (x = 2, n = 10):
myPow(2, 10):
  - n >= 0, call Pow(2, 10)
  - Pow(2, 10):
    - n=10 (even), power = Pow(2, 5)
    - Pow(2, 5):
      - n=5 (odd), power = Pow(2, 2)
      - Pow(2, 2):
        - n=2 (even), power = Pow(2, 1)
        - Pow(2, 1):
          - n=1 (odd), power = Pow(2, 0)
          - Pow(2, 0): return 1
          - return 2 * 1 * 1 = 2
        - return 2 * 2 = 4
      - return 2 * 4 * 4 = 32
    - return 32 * 32 = 1024
  - return 1024

Example with negative exponent (x = 2, n = -2):
myPow(2, -2):
  - n < 0, compute 1 / Pow(2, 2)
  - Pow(2, 2):
    - n=2 (even), power = Pow(2, 1)
    - Pow(2, 1):
      - n=1 (odd), power = Pow(2, 0) = 1
      - return 2 * 1 * 1 = 2
    - return 2 * 2 = 4
  - return 1 / 4 = 0.25

Time & Space complexity:
- Time: O(log n), because we halve n at each recursive call
- Space: O(log n), recursion depth is log n
- Advantage: Efficiently handles even large exponents up to 2^31
*/

class Solution {
public:
double Pow(double x , int n) {
        if(n == 0) return 1;
        double power = Pow(x , n/2);
        return n % 2 == 0 ? power * power : x * power * power; 
    }
    double myPow(double x, int n) {
        return n < 0 ? 1/(Pow(x , n)) : Pow(x , n); 
    }
};