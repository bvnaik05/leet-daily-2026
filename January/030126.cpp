class Solution
{
public:
    const int mod = 1e9 + 7;
    int solve(int i, int n, int prev1, int prev2, int prev3, vector<vector<vector<vector<int>>>> &dp)
    {
        if (i == n)
            return 1;
        if (dp[i][prev1 + 1][prev2 + 1][prev3 + 1] != -1) // Memoization check for previously computed states
            return dp[i][prev1 + 1][prev2 + 1][prev3 + 1];

        int ans = 0;
        for (int c1 = 0; c1 < 3; c1++)
        {
            for (int c2 = 0; c2 < 3; c2++)
            {
                for (int c3 = 0; c3 < 3; c3++)
                {
                    if (c1 != c2 && c2 != c3 && c1 != prev1 && c2 != prev2 && c3 != prev3)
                        ans = (ans + solve(i + 1, n, c1, c2, c3, dp)) % mod;
                }
            }
        }
        return dp[i][prev1 + 1][prev2 + 1][prev3 + 1] = ans;
    }
    int numOfWays(int n)
    {
        vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1))));
        return solve(0, n, -1, -1, -1, dp);
    }
};

// Dry run

// Input: n = 1
// dp initialized with -1 where dp size is (2 x 4 x 4 x 4) which means that the combination is not computed yet.

// Call solve(0, 1, -1, -1, -1, dp)

// i = 0, n = 1, prev1 = -1, prev2 = -1, prev3 = -1
// We are at first row and there are no previous colors

// Since i(0) != n(1) and dp[0][0][0][0] == -1, proceed to calculate ans
// We do +1 because prev1, prev2, prev3 can be -1, so we shift them by 1 for indexing (This is done to avoid negative indexing in the dp array)

// ans = 0

// Loop through all color combinations for the current row (c1, c2, c3) 3x3x3 = 27 combinations

// For each combination, check if it satisfies the conditions:
// c1 != c2, c2 != c3, c1 != prev1, c2 != prev2, c3 != prev3

// This means that no two adjacent cells in the same row or in the previous row can have the same color
// Valid combinations are found and for each valid combination, we make a recursive call to solve for the next row

// When i becomes equal to n, we return 1 as a valid way is found
// Finally, store the computed ans in dp[0][0][0][0] and return it





