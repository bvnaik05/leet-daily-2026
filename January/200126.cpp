class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto n: nums){
            if(n != 2) ans.push_back(n - ((n + 1) & (-n - 1)) / 2);
            else ans.push_back(-1);
        }
        return ans;
    }
};

// Dry run
// Input: nums = [3,2,5,7]
// Step 1: n = 3
//         (3 + 1) & (-3 - 1) = 4 & (-4) = 4
//          4 / 2 = 2
//          3 - 2 = 1
// Step 2: n = 2
//         n == 2, so ans.push_back(-1) 
// Step 3: n = 5
//         (5 + 1) & (-5 - 1) = 6 & (-6) = 2
//          2 / 2 = 1
//          5 - 1 = 4
// Step 4: n = 7
//         (7 + 1) & (-7 - 1) = 8 &
//         (-8) = 8
//         8 / 2 = 4
//         7 - 4 = 3
// Final ans: [1,-1,4,3]

// Explanation:
// For each number, we find the lowest set bit using (n + 1) & (-n - 1).
// We then divide that value by 2 to get the value to subtract from n.
// If n is 2, we directly append -1 to the answer.


