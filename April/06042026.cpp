class Solution {
public:
    bool judgeCircle(string moves) {
        int l = 0;
        int b = 0;

        for(auto c: moves){
            if(c == 'U') l++;
            else if(c == 'D') l--;
            else if(c == 'L') b++;
            else b --;
        }
        return (l == 0 && b == 0) ? true : false;
    }
};
