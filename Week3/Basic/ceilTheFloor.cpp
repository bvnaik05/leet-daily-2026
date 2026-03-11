// User code template

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        
        int h = arr.size() - 1;
        int l = 0;
        int ans = -1;
        
        while(l <= h){
            int mid = (l + h) / 2;
            
            if(x == arr[mid]){
                ans = mid;
                l = mid + 1;
            }
            else if(x > arr[mid]){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        
        return ans;
    }
    int findCeil(vector<int>& arr, int x) {
        
        int h = arr.size() - 1;
        int l = 0;
        int ans = -1;
        
        while(l <= h){
            int mid = (l + h) / 2;
            
            if(x == arr[mid]){
                ans = arr[mid];
                l = mid + 1;
            }
            else if(x > arr[mid]){
                l = mid + 1;
            }
            else{
                ans = arr[mid];
                h = mid - 1;
            }
        }
        
        return ans;
    }
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr. end());
        int floor = findFloor(arr, x);
        int ceil = findCeil(arr, x);
        
        return {floor, ceil};
        
        
        
    }
};
