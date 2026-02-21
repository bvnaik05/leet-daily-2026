class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            int ind = (i + nums[i]) % n;
            if (ind < 0)
                ind += n;
            result[i] = nums[ind];
        }
        return result;
    }
};