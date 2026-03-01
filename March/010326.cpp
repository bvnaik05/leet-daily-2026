class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(auto it: n){
            if(it - '0' > mx) mx = it - '0';
        }
        return mx;
    }
};
