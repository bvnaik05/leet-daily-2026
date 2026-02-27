class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int curr = 0;
        for(auto it: nums){
            if(it) curr++;
            else{
                if(maxi < curr) maxi = curr;
                curr = 0;
            }
        }
        if(maxi < curr) maxi = curr;
        return maxi;
    }
};
