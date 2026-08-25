class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n!=0){
            for(int i=m;i<m+n;i++){
                nums1[i]=nums2[i-m];
            }
        }
        int len=m+n;
        int gap=(len/2)+(len%2);

        while(gap>0){
            int i=0;
            int j=i+gap;

            while(j<len){
                if(nums1[i]>nums1[j]){
                    swap(nums1[i],nums1[j]);
                }
                i++,j++;
            }
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }
    }
};
