class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        for(auto it: candies){
            if(it > maxi) maxi = it;
        }

        vector<bool>result;
        for(auto it: candies){
            if(it + extraCandies >= maxi) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};
