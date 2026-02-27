
class Solution {
  public:
    int countOfElements(int x, vector<int> &arr) {
        int c = 0;
        // Code Here
        for(auto it: arr){
            if(it <= x) c++;
        }
        return c;
    }
};
