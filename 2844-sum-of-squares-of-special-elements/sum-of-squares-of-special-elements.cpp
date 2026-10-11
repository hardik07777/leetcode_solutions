class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 2; i<=n; i++){
            if(n % (i) == 0){
                ans += nums[i-1] * nums[i-1];
            }

        }
        ans += nums[0] * nums[0];
        return ans;
        
    }
};