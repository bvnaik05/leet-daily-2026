class Solution
{
public:
    int minimumPairRemoval(vector<int> &input)
    {
        vector<long long> nums(input.begin(), input.end());
        int n = nums.size();

        vector<int> prev(n), next(n);
        for (int i = 0; i < n; i++)
        {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        int badCount = 0;
        set<pair<long long, int>> st;
        for (int i = 0; i < n - 1; i++)
        {
            st.insert({nums[i] + nums[i + 1], i});
            if (nums[i] > nums[i + 1])
                badCount++;
        }

        int ans = 0;

        while (badCount > 0)
        {
            ans++;
            auto [sum, i] = *st.begin();
            st.erase(st.begin());

            int j = next[i];

            if (prev[i] >= 0)
                st.erase({nums[prev[i]] + nums[i], prev[i]});
            if (next[j] < n)
                st.erase({nums[j] + nums[next[j]], j});

            if (prev[i] >= 0 && nums[prev[i]] > nums[i])
                badCount--;
            if (nums[i] > nums[j])
                badCount--;
            if (next[j] < n && nums[j] > nums[next[j]])
                badCount--;

            nums[i] += nums[j];

            next[i] = next[j];
            if (next[j] < n)
                prev[next[j]] = i;

            if (prev[i] >= 0)
            {
                st.insert({nums[prev[i]] + nums[i], prev[i]});
                if (nums[prev[i]] > nums[i])
                    badCount++;
            }
            if (next[i] < n)
            {
                st.insert({nums[i] + nums[next[i]], i});
                if (nums[i] > nums[next[i]])
                    badCount++;
            }
        }
        return ans;
    }
};

// Dry run
// Input: nums = [5,3,4,2]
// Step 1: Initialize prev and next arrays
//         prev = [-1,0,1,2], next = [1,2,3,4]
// Step 2: Initialize set with adjacent sums
//         st = {(5+3,0),(3+4,1),(4+2,2)} = {(8,0),(7,1),(6,2)}
// Step 3: Count bad pairs
//         badCount = 2 (5>3, 4>2) 
// Step 4: While badCount > 0
//         ans = 0
//         Iteration 1:
//         Extract (6,2) from st
//         Merge nums[2] and nums[3]: nums[2] = 4 + 2 = 6
//         Update prev and next: next[2] = 4
//         Update badCount: badCount = 1 (5>3)
//         ans = 1
//         Iteration 2:
//         Extract (7,1) from st
//         Merge nums[1] and nums[2]: nums[1] = 3 + 6 = 9
//         Update prev and next: next[1] = 4
//         Update badCount: badCount = 0
//         ans = 2
// Step 5: Return ans = 2

// Explanation:
// We maintain a set of adjacent sums and a count of bad pairs.
// In each iteration, we merge the pair with the smallest sum, 
// update the linked structure and bad pair count accordingly,
// until there are no bad pairs left.

