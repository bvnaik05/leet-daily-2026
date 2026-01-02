class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq; 
        for(auto it: nums){
            freq[it]++;
            if(freq[it] > 1)  return it;
        }
        return 0;
    }
};

// Dry run

// Input: nums = [1,2,3,3]
// freq = {}
// Iteration 1: it = 1
// freq = {1: 1}

// Iteration 2: it = 2
// freq = {1: 1, 2: 1}

// Iteration 3: it = 3
// freq = {1: 1, 2: 1, 3: 1}

// Iteration 4: it = 3
// freq = {1: 1, 2: 1, 3: 2}
// Since freq[3] > 1, return 3



