class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        vector<int> blocks;
        int curr = 1;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                blocks.push_back(curr);
                curr = 1;
                continue;
            }
            curr++;
        }
        blocks.push_back(curr);
        int sum = 0;
        for(int i = 0; i < blocks.size()-1; i++){
            sum += min(blocks[i], blocks[i+1]);
        }
        return sum;
    }
};

// Dry run
// s = "00110011"
// blocks = [2, 2, 2, 2]
// sum = 0 + min(2, 2) + min(2, 2) + min(2, 2) = 6


