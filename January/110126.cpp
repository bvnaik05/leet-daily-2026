class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1')
                    height[c] += 1;
                else
                    height[c] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > curHeight) {
                int h = heights[st.top()];
                st.pop();

                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;

                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }
};


// Dry run
// Input : matrix = [["1","0","1","0","0"],
//                   ["1","0","1","1","1"],
//                   ["1","1","1","1","1"],
//                   ["1","0","0","1","0"]]
// After processing each row, the height array will be:
// Row 0: height = [1, 0, 1, 0, 0] -> Max Area = 1
// Row 1: height = [2, 0, 2, 1, 1] -> Max Area = 3
// Row 2: height = [3, 1, 3, 2, 2] -> Max Area = 6      
// Row 3: height = [4, 0, 0, 3, 0] -> Max Area = 6
// Output: 6