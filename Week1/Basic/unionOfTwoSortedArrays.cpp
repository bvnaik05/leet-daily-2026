class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {

        vector<int> ans;
        int p1 = 0, p2 = 0;

        while(p1 < a.size() && p2 < b.size()){

            if(a[p1] < b[p2]){
                if(ans.empty() || ans.back() != a[p1])
                    ans.push_back(a[p1]);
                p1++;
            }
            else if(a[p1] > b[p2]){
                if(ans.empty() || ans.back() != b[p2])
                    ans.push_back(b[p2]);
                p2++;
            }
            else{
                if(ans.empty() || ans.back() != a[p1])
                    ans.push_back(a[p1]);
                p1++;
                p2++;
            }
        }

        while(p1 < a.size()){
            if(ans.empty() || ans.back() != a[p1])
                ans.push_back(a[p1]);
            p1++;
        }

        while(p2 < b.size()){
            if(ans.empty() || ans.back() != b[p2])
                ans.push_back(b[p2]);
            p2++;
        }

        return ans;
    }
};
