class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;

        int l = 1;
        int h = x/2;
        int ans = -1;

        while(l <= h){
            int mid = (l + h) / 2;

            if(mid <= x / mid){
                ans = mid;
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        return ans;
    }
};
