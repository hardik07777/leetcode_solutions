class Solution {
public:
    int n;
    int dp[2501][2501];
    
    int helper(int i , int prev , vector<int>& nums){
        if(i == n){
            return 0;
        }
        if(dp[i][prev + 1] != -1 ){
            return dp[i][prev + 1];
        }
        int nottake = helper(i+1 , prev  , nums);
        int take = 0;
        if(prev == -1 or nums[i] > nums[prev ]){
            take = 1 + helper(i+1 , i , nums);

        }
        return dp[i][prev + 1] =  max(take , nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return helper(0 , -1  , nums);        
    }
};