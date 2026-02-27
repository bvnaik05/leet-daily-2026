class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        int sum = 0;
        int cust = accounts.size();
        int banks = accounts[0].size();
        for(int i = 0; i < cust; i++){
            sum = 0;
            for(int j = 0; j < banks; j++){
                sum += accounts[i][j];
            }
            if(sum > maxi) maxi = sum;
        }
        return maxi;
    }
};
