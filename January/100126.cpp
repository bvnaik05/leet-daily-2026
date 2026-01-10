class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp (n+1, vector<int> (m +1, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s1[i] == s2[j])  dp[i+1][j+1] = dp[i][j] + s1[i];
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        int total = 0;
        for (char c: s1) total += c;
        for (char c: s2) total += c;

        return total - 2 * dp[n][m];

    }
};

// Dry run
// Input : s1 = "sea" , s2 = "eat"
// The longest common subsequence is "ea" with ASCII sum 101 + 97 = 198

// Total ASCII sum of s1 = 's' + 'e' + 'a' = 115 + 101 + 97 = 313
// Total ASCII sum of s2 = 'e' + 'a' + 't' = 101 + 97 + 116 = 314
// Total ASCII sum = 313 + 314 = 627

// Minimum delete sum = Total ASCII sum - 2 * LCS ASCII sum
// Minimum delete sum = 627 - 2 * 198 = 627 - 396 = 231

// Output: 231

