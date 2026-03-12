class Solution {
  public:
    void printNos(int n) {
        // Code here
        if (n ==1){
            cout << 1 << " " ;
            return;
        }
        else printNos(n - 1);
        cout << n << " " ;
    }
};
