class Solution {
public:
    bool helper(vector<int> & nums , int len){
        int n = nums.size();
        int prevmax = INT_MIN;
        for(int i =0; i<n; i+= len ){
            int cnt = 0;
            int currentmax = nums[i];
            int currentmin = nums[i];
            for(int j = i+1; j< i+len; j++){
               
                if(nums[j] < nums[j-1]){
                    cnt++;
                }
                currentmax = max(currentmax , nums[j]);
                currentmin = min(currentmin , nums[j]);
            }
            if(currentmin < prevmax){
                return false;
            }
            if(nums[i] < nums[i + len - 1]) cnt++;


            if(cnt > 1){
                return false;
            }
            prevmax = currentmax;
            
        }
        return true;

    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i<= n; i++){
            int mini = INT_MIN;
            if( (n % i) == 0){
                if(helper(nums , i )){
                    ans+= i;
                }
            }
        }
        return ans;
        
    }
};