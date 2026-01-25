class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = 0; i + k - 1 <= n - 1; i++){
            int diff = nums[i + k - 1] - nums[i];
            ans = min(ans, diff);
        }
        return ans;
    }
};

// Dry run 
// Input : [9, 4, 1, 7], k = 2
// Sorting: [1, 4, 7, 9]
// Window size = 2 : (1, 4), (4, 7), (7, 9)
// ans = min(4-1, 7-4, 9-7) = min(3, 3, 2)
// ans = 2
