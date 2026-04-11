class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        for(int x : nums) xorAll ^= x;

       unsigned int diff = xorAll & (-(unsigned int)xorAll);

        int a = 0, b = 0;

        for(int x : nums) {
            if(x & diff) a ^= x;
            else b ^= x;
        }

        return {a, b};
    }
};
