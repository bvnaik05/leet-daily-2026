class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector <int> prefixSum;
        prefixSum.push_back(0);
        for(auto it: arr){
            prefixSum.push_back(prefixSum.back() + it);
        }
        for(int i = 0; i < n; i++){
            if((prefixSum[i] - prefixSum[0]) == (prefixSum[n] - prefixSum[i+1])) return i;
        }
        return -1;
    }
};
