class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(j-i +1 >= l and j-i+1 <= r){
                    int temp = 0;
                    for(int k = i; k<=j; k++){
                        temp += nums[k];

                    }
                    if(temp > 0){
                    ans = min(temp , ans);
                    }
                }
            }
        }
        if( ans == INT_MAX){
            return -1;
        }
        return ans;
        
    }
};