class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        int ind = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] < mini){
                mini = arr[i];
                ind = i;
            }
        }
        for(int i = ind; i < ind + n - 1; i++){
            if(arr[(i+1)%n] < arr[i%n]) return false;
        }
        return true;
    }
};
