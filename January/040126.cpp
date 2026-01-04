class Solution
{
public:
    int findDivSum(int x)
    {
        int count = 0;
        int sum = 0;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                count++;
                sum += i;
                if (i != x / i)
                {
                    sum += x / i;
                    count++;
                }
            }
            if (count > 4)
                return 0;
        }
        return (count == 4) ? sum : 0;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += findDivSum(nums[i]);
        }
        return sum;
    }
};

// Dry run
// Input: nums = [21,4,7]
// For each number in nums, we call findDivSum
// For 21:
// Divisors are 1, 3, 7, 21 -> count = 4, return sum = 32

// For 4:
// Divisors are 1, 2, 4 -> count = 3, return 0

// For 7:
// Divisors are 1, 7 -> count = 2, return 0 

// Final sum = 32 + 0 + 0 = 32
// Output: 32

