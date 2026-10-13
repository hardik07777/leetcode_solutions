class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int oddtake = 0;
        int eventake = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] <0){
                nums[i] = abs(nums[i]);
            }
        }
        sort(nums.begin() , nums.end());
        long long ans = 0;
        if( n == 1){
            return nums[0] * nums[0];
        }

        if(n%2 == 0){
             oddtake = n/2;
             eventake = n/2;
             for(int i = n-1; i>= eventake; i--){
                ans += 1ll * nums[i] * nums[i];

             }
             for(int i = n/2 -1; i>= 0; i--){
                ans -= 1ll * nums[i] * nums[i];

             }
        }
        else{
            oddtake = n/2;
            eventake = oddtake +1;
            for(int i = n-1 ; i>= (eventake -1 < 0  ? 0 :eventake -1) ; i--){
                ans += 1ll * nums[i] * nums[i];

             }
             for(int i = n/2 - 1 ; i>= 0; i--){
                ans -= 1ll * nums[i] * nums[i];

             }
        }
        return ans;
    }
};