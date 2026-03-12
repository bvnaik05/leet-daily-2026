class Solution {
  public:
    bool ans(string& s, int l, int h){
        if(l > h) return true;
        if(s[l] != s[h]) return false;
        else ans(s, l+1, h-1);
        
    }
    bool isPalindrome(string& s) {
        // code here
        int l = 0; int h = s.size() - 1;
        
        return ans(s, l, h);
    }
};
