class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for(int i = 0; i < n; i++){
            int l = 0;
            int h = n - 1;

            while(l <= h){
                int mid = l + (h - l) / 2;

                if(mid != i && arr[mid] == 2 * arr[i]) return true;
                else if(arr[mid] > 2 * arr[i]) h = mid - 1;
                else l = mid + 1;
            }
        }
        return false;
    }
};
