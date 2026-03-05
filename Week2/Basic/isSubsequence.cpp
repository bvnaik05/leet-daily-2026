class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int p1 = 0; int p2 = 0;
        while(p1 < n && p2 < m){
            while(t[p2] != s[p1] && p2 < m) p2++;
            if(t[p2] == s[p1]){
                p1++;
                p2++;
            }
        }
        if(p1 == n) return true;
        else return false;
    }
};
