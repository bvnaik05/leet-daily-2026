class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int l = 0;
        int r = n;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(nums[l]); l++;
            ans.push_back(nums[r]); r++;
        }
        return ans;
    }
};
