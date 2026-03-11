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
};
