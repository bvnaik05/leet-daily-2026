class Solution {
  public:
    string reverseString(string& s) {
        if(s.size() == 1) return s;

        string rest = s.substr(1);
        string rev = reverseString(rest);

        return rev + s[0];
    }
};
