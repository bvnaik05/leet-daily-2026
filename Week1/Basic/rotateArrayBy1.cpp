// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
        int dig =arr[n-1];
        arr.pop_back();
        arr.insert(arr.begin(), dig);
    }
};
