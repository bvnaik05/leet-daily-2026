class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0; int p2 = n - 1;
        while(p1 <= p2){
            while(nums[p1] % 2 == 0 && p1 < p2) p1++;
            while(nums[p2] % 2 != 0 && p2 > p1) p2--;
            int swap = nums[p1];
            nums[p1] = nums[p2];
            nums[p2] = swap;

            p1++;
            p2--;
        }
        return nums;
    }
};
