#include <cmath>
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long abssum = 0;
        long long absmin = 10e5;
        int countNeg = 0;

        for(auto row: matrix){
            for(auto it: row){
                abssum += std::abs(it);
                absmin = std::min(absmin, (long long)(std::abs(it)));
                if(it < 0) countNeg++;
            }
            
        }
        return (countNeg % 2 == 0) ? abssum : (abssum - 2 * absmin);
    }
};

// Dry run 
// Input: matrix = [
                    // [5,-6,-2],
                    // [9,6,-4],
                    // [2,0,13]
                    // ]
// abssum = 0, absmin = 10e5, countNeg = 0
// For first row: 
    // 5: abssum = 5, absmin = 5, countNeg = 0
    // -6: abssum = 11, absmin = 5, countNeg = 1
    // -2: abssum = 13, absmin = 2, countNeg = 2

// For second row:
    // 9: abssum = 22, absmin = 2, countNeg = 2
    // 6: abssum = 28, absmin = 2, countNeg = 2
    // -4: abssum = 32, absmin = 2, countNeg = 3

// For third row:
    // 2: abssum = 34, absmin = 2, countNeg = 3
    // 0: abssum = 34, absmin = 0, countNeg = 3
    // 13: abssum = 47, absmin = 0, countNeg = 3

// Since countNeg is odd, return abssum - 2 * absmin = 47 - 0 = 47
