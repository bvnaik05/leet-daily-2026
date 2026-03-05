class Solution {
public:
    int minOperations(string s) {
       int n = s.size();
       char even = s[0];
       char odd = (s[0] == '0') ? '1' : '0';
       int correct = 0;
       for(int i = 0; i < n; i++){
            if(i % 2 != 0 && s[i] == odd) correct++;
            if(i % 2 == 0 && s[i] == even) correct++;
       }
       return min(correct, n - correct);
    }

};
