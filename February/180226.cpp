class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = 0;
        if(n & 1) flag = 1;
        n >>= 1;
        while(n != 0){
            if((n & 1) == flag) return false;
            flag = flag ^ 1;
            n >>= 1;
        }
        return true;
    }
};

// Dry run
// n = 5
// flag = 0
// n & 1 = 1, flag = 1
// n = 2
// n & 1 = 0, flag = 0
// n = 1
// n & 1 = 1, flag = 1
// n = 0
// return true
