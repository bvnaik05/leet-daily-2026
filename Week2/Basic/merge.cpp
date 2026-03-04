class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k1 = m-1, k2 = n-1, i = m+n-1;
        while(k1>=0 && k2>=0){
            if(nums1[k1] > nums2[k2]){
                nums1[i] = nums1[k1];
                k1--;
            }
            else{
                nums1[i] = nums2[k2];
                k2--;
            }
            i--;
        }
        while(k2 >=0){
            nums1[i] = nums2[k2];
            k2--;
            i--;
        }
    }
};
