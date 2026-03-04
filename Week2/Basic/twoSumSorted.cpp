class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int ind1 = 0;
        int ind2 = n-1;
        while(ind1 <= ind2){
            if(numbers[ind1] + numbers[ind2] == target) return {ind1+1, ind2+1};
            else if(numbers[ind1] + numbers[ind2] < target) ind1++;
            else ind2--;
        }
        return {ind1+1, ind2+1};
    }
};
