class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        if (letters.back() <= target || letters[0] > target)
            return letters[0];
        int n = letters.size();
        int low = 0;
        int high = n - 1;
        int lexi = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (letters[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return letters[low + 1]
    }
};