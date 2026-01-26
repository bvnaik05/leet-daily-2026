class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int diff = INT_MAX;
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size() - 1; i++) {
        int cur = arr[i + 1] - arr[i];

        if (cur < diff) {
            diff = cur;
            ans.clear();
            ans.push_back({arr[i], arr[i + 1]});
        } else if (cur == diff) {
            ans.push_back({arr[i], arr[i + 1]});
        }
    }
    return ans;
}
};

// Dry run 
// Input: arr = [4,2,1,3]
// Sort: arr = [1,2,3,4]
// curr = 1, diff = min(INT_MAX, curr) = diff = 1
// 2-1 = 1 (equal to diff) => ans = {[1,2]}
// 3-2 = 1 (equal to diff) => ans = {[1,2], [2,3]}
// 4-3 = 1 (equal to diff) => ans = {[1,2], [2,3], [3,4]}
Output: [[1,2],[2,3],[3,4]]
