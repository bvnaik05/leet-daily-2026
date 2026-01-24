class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++)
        {
            int sum = nums[i] + nums[n - i - 1];
            ans = max(ans, sum);
        }
        return ans;
    }
};

// Dry run
// Input: nums = [3,5,2,3]
// Sorted: [2,3,3,5]

// ans = 0
// Iteration 1: i=0, n-i-1 = 3 
// sum = nums[0] + nums[3] = 2 + 5 = 7, ans= max(0,7) = 7

// Iteration 2: i=1, n-i-1 = 2
// sum = nums[1] + nums[2] = 3 + 3 = 6, ans= max(7,6) = 7
// Return 7




