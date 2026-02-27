class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {

        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> ans(col, vector<int>(row));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                ans[j][i] = mat[i][j];
            }
        }

        return ans;
    }
};
