class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(m > n) return maxDotProduct(nums2, nums1);

        vector <int> dp(m + 1, -1e9);
        for(int i = 0; i < n; i++){
            int prev = -1e9;
            for (int j = 1; j <= m; j++) {
                int currProd = nums1[i] * nums2[j - 1];
                int temp = dp[j];

                dp[j] = max({
                    currProd,              // start new
                    currProd + prev,       // extend
                    dp[j],                 // skip nums1
                    dp[j - 1]              // skip nums2
                });

                prev = temp;
            }
        }
        return dp[m];
    }
};

// Dry run

// Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
// n = 4, m = 3
// dp = [-1e9, -1e9, -1e9, -1e9]

// i = 0 (nums1[0] = 2)
    // prev = -1e9
    // j = 1
        // currProd = 2 * 3 = 6
        // temp = dp[1] = -1e9
        // dp[1] = max(6, 6 + -1e9, -1e9, -1e9) = 6
        // prev = -1e9
    // j = 2
        // currProd = 2 * 0 = 0
        // temp = dp[2] = -1e9
        // dp[2] = max(0, 0 + -1e9, -1e9, 6) = 6
        // prev = -1e9
    // j = 3
        // currProd = 2 * -6 = -12
        // temp = dp[3] = -1e9
        // dp[3] = max(-12, -12 + -1e9, -1e9, 6) = 6
        // prev = -1e9
// dp after i=0: [-1e9, 6, 6, 6]
// i = 1 (nums1[1] = 1)
    // prev = -1e9
    // j = 1
        // currProd = 1 * 3 = 3
        // temp = dp[1] = 6
        // dp[1] = max(3, 3 + -1e9, 6, -1e9) = 6
        // prev = 6
    // j = 2
        // currProd = 1 * 0 = 0
        // temp = dp[2] = 6
        // dp[2] = max(0, 0 + 6, 6, 6) = 6
        // prev = 6
    // j = 3
        // currProd = 1 * -6 = -6
        // temp = dp[3] = 6
        // dp[3] = max(-6, -6 + 6, 6, 6) = 6
        // prev = 6
// dp after i=1: [-1e9, 6, 6, 6]
// i = 2 (nums1[2] = -2)
    // prev = -1e9
    // j = 1
        // currProd = -2 * 3 = -6
        // temp = dp[1] = 6
        // dp[1] = max(-6, -6 + -1e9, 6, -1e9) = 6
        // prev = 6
    // j = 2
        // currProd = -2 * 0 = 0
        // temp = dp[2] = 6
        // dp[2] = max(0, 0 + 6, 6, 6) = 6
        // prev = 6
    // j = 3
        // currProd = -2 * -6 = 12
        // temp = dp[3] = 6
        // dp[3] = max(12, 12 + 6, 6, 6) = 18
        // prev = 6
// dp after i=2: [-1e9, 6, 6, 18]
// i = 3 (nums1[3] = 5)
    // prev = -1e9
    // j = 1
        // currProd = 5 * 3 = 15
        // temp = dp[1] = 6
        // dp[1] = max(15, 15 + -1e9, 6, -1e9) = 15
        // prev = 6
    // j = 2
        // currProd = 5 * 0 = 0
        // temp = dp[2] = 6
        // dp[2] = max(0, 0 + 6, 6, 15) = 15
        // prev = 6
    // j = 3
        // currProd = 5 * -6 = -30
        // temp = dp[3] = 18
        // dp[3] = max(-30, -30 + 6, 18, 15) = 18
        // prev = 18
// dp after i=3: [-1e9, 15, 15, 18]

// Return dp[3] = 18

// Final Answer: 18

