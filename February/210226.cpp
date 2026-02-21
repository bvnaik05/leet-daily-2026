class Solution
{
public:
    int countSet(int x)
    {
        int num = 0;
        while (x != 0)
        {
            if ((x & 1) == 1)
                num++;
            x >>= 1;
        }
        return num;
    }
    int countPrimeSetBits(int left, int right)
    {
        set<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int i = left; i <= right; i++)
        {
            int count = countSet(i);
            if (prime.find(count) != prime.end())
                ans++;
        }
        return ans;
    }
};