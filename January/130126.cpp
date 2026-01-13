class Solution
{
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        double totalArea = 0;
        double low = 2e9;
        double high = 0;

        for (auto &s : squares)
        {
            double y = s[1];
            double l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double targetArea = totalArea / 2.0;

        for (int i = 0; i < 100; i++)
        {
            double mid = low + (high - low) / 2.0;
            double currentArea = 0;

            for (auto &s : squares)
            {
                double y = s[1];
                double l = s[2];
                double h_below = max(0.0, min(l, mid - y));
                currentArea += h_below * l;
            }

            if (currentArea < targetArea)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        return high;
    }
};

// Dry run
// Input: squares = [[1,1,2],[2,2,2],[3,1,2]]
// Total area = 2*2 + 2*2 + 2*2 = 12
// Target area = 12 / 2 = 6
// low = min(1, 2, 1) = 1
// high = max(1+2, 2+2, 1+2) = 4
// Binary Search Steps:
// Iteration 1: mid = 2.5, currentArea = 2 + 0 + 1*2 = 4 (currentArea < targetArea, low = mid)
// Iteration 2: mid = 3.25, currentArea = 2 + 1*2 + 1*2 = 6 (currentArea >= targetArea, high = mid)
// Iteration 3: mid = 2.875, currentArea = 2 + 0.875*2 + 1*2 = 5.75 (currentArea < targetArea, low = mid)
// Iteration 4: mid = 3.0625, currentArea = 2 + 1.0625*2 + 1*2 = 6.125 (currentArea >= targetArea, high = mid)
// ...      
// After 100 iterations, high will converge to the correct y-coordinate where the area below equals half the total area.
// Output: 2.5
