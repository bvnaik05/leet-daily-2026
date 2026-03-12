class Solution {
  public:
    int sumOfSeries(int n) {
        if(n == 1){
            return 1;
        }

        int sum = n * n * n + sumOfSeries(n - 1);
        return sum;
    }
};
