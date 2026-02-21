class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 4)
            return false;

        int count = 0;
        int i = 0;

        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;
        if (i == 0)
            return false;
        count++;

        while (i + 1 < n && nums[i] > nums[i + 1])
            i++;
        if (i == n - 1)
            return false;
        count++;

        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;

        if (count == 2 && i == n - 1)
            return true;
        return false;
    }
};
