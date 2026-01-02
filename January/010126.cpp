#include <vector>
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Dry run

// Input: digits = [9, 9, 9]
// n = 3
// Iteration 1: i = 2
// if case not satisfied
// digit[2] = 0

// Iteration 2: i = 1
// if case not satisfied
// digit[1] = 0

// Iteration 3: i = 0
// if case not satisfied
// digit[0] = 0

// Out of For Loop
// Now that all have bevome zero we need to add a prefix 1
// Inserting 1 at the beginning
// Return [1, 0, 0, 0]