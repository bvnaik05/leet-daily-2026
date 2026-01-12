class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        int n = points.size();
        for(int i = 0; i < n - 1; i++){
            int dx = abs(points[i][0] - points[i+1][0]);
            int dy = abs(points[i][1] - points[i+1][1]);
            time += max(dx, dy);
        }
        return time;
    }
};

// Dry run

// Input : points = [[1,1],[3,4],[-1,0]]
// From (1,1) to (3,4):
// dx = |3 - 1| = 2
// dy = |4 - 1| = 3    
// Time taken = max(2, 3) = 3

// From (3,4) to (-1,0):
// dx = |-1 - 3| = 4
// dy = |0 - 4| = 4
// Time taken = max(4, 4) = 4

// Total time = 3 + 4 = 7
