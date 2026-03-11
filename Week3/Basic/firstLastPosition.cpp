class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                start = i;
                end = i;

                while(i + 1 < nums.size() && nums[i + 1] == nums[i]){
                    i++;
                    end = i;
                }

                break;
            }
        }

        return {start, end};
    }
};
