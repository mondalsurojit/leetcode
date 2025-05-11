class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pre = 0, post = 0, pivot=0;
        int l= nums.size();
        int nums2[l];
        for(int i=0; i<l-1; i++){
            pre = nums[i];
            post = nums[i+1];
            if(pre>post){
                pivot=i+1;
                break;
            }
        }
        for(int j=0; j<l-pivot; j++){
           nums2[j]= nums[pivot+j];
        }
        for(int k = 0; k < pivot; k++) {
            nums2[l-pivot+k] = nums[k];
        }
        
        int start=0, end=l-1;
        int mid=0;
        while(start <= end){
          mid = start + (end - start) / 2;
          if (nums2[mid] == target){
            return true;
          }
          else if (nums2[mid] < target){
            start=mid+1;
          }
          else {
            end = mid-1;
          }
        }
        return false;
    }
};