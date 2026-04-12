#include <cmath>
class Solution {
public:
    int reverseBits(int n) {
        int arr[32];
        //convert decimal to binary
        for(int i = 31; i >= 0; i--){
            arr[i] = (n % 2);
            n = n / 2;
        }
        //store in the array of 32 bit
        //convert binary to decimal using array
        long long ans = 0;
        for(int i = 0; i <= 31; i++){
            ans += arr[i] * pow(2, i);
        }
        return ans;
    }
};
