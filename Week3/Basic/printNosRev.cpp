class Solution {
  public:
    void printNos(int N) {
        // code here
        if(N == 1) {
            cout << 1;
            return;
        }
        else{
            cout << N << " ";
            printNos(N - 1);
        }
    }
};
