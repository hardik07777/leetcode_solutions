class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incsize = 1;
        int decsize = 1;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int temp = 1;
            int prev = i;
            for(int j = i +1; j<n; j++){
               if(nums[j] > nums[prev]){
                temp++;
                prev++;
               }
               else{
                break;
               }
            }
            incsize = max(incsize , temp);
        }
        for(int i = 0; i<n; i++){
            int temp = 1;
            int prev = i;
            for(int j = i +1; j<n; j++){
               if(nums[j] < nums[prev]){
                temp++;
                prev++;
               }
               else{
                break;
               }
            }
            decsize = max(decsize , temp);
        }
        return max(decsize , incsize);
        
    }
};