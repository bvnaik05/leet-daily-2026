class Solution {
public:
    int ans = 0;
    bool is_sorted(vector<int> &nums){
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
    int sorting(vector<int> &nums){
        int ans = 0;
        while (!is_sorted(nums)){
            int pos = -1;
            int mini = INT_MAX;
            for(int i = 0; i < nums.size() - 1; i++){
                int sum = nums[i] + nums[i+1];
                if(sum < mini){
                    mini = sum;
                    pos = i;
                }
            }
            nums[pos] = mini;
            nums.erase(nums.begin() + pos + 1);
            ans++;
        }       
        return ans;
    }
    int minimumPairRemoval(vector<int>& nums) {
        if(is_sorted(nums)) return 0;
        ans = sorting(nums);
        return ans;
    }
};

// Dry run
// Input: nums = [3,2,5,7]
// Step 1: Check if nums is sorted
//         It is not sorted, so we proceed to sorting function
// Step 2: In sorting function, initialize ans = 0
// Step 3: While nums is not sorted:
//         Find the adjacent pair with the smallest sum
//         For (3,2): sum = 5
//         For (2,5): sum = 7
//         For (5,7): sum = 12
//         The smallest sum is 5 at position 0
//         Merge (3,2) -> nums becomes [5,5,7], ans = 1
// Step 4: Check if nums is sorted
//         It is not sorted, so continue
// Step 5: Find the adjacent pair with the smallest sum
//         For (5,5): sum = 10
//         For (5,7): sum = 12
//         The smallest sum is 10 at position 0
//         Merge (5,5) -> nums becomes [10,7], ans = 2
// Step 6: Check if nums is sorted
//         It is not sorted, so continue
// Step 7: Find the adjacent pair with the smallest sum
//         For (10,7): sum = 17
//         The smallest sum is 17 at position 0
//         Merge (10,7) -> nums becomes [17], ans = 3
// Step 8: Check if nums is sorted
//         It is sorted now, exit loop
// Final ans: 3
