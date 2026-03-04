class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        for(auto c : s){
            if(c >= 'a' && c <= 'z') clean += c;
            else if(c >= 'A' && c <= 'Z') clean += tolower(c);
            else if(c >= '0' && c <= '9') clean += c;
            else continue;
        }
        int n = clean.size();
        for(int i = 0; i < n/2; i++){
            if(clean[i] != clean[n-i-1]) return false;
        }
        return true;
    }
};
