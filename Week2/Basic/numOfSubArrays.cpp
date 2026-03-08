class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        vector <int> prefix;
        prefix.push_back(0);
        for(int i = 0; i < n; i++){
            prefix.push_back(prefix.back() + arr[i]);
        }
        int ans = 0;
        for(int i = 0; i < n - k + 1; i++){
            if (prefix[i+k] - prefix[i] >= threshold * k) ans++;
        }
        return ans;
    }
};
